# Concurrent Lock-free Queue
Haoyang Wu, Yutong Zhu  

## 1 Summary
In this final project we implemented a concurrent lock-free FIFO queue using the atomic compare-and-swap (CAS). We evaluated the performance of our lock-free implementation on GHC machines by comparing it with two other implementations of locked queues of different granularity.
## 2 Background
There are many problems associated with locks in shared data structures, such as overheads in high-frequency synchronisations. Rather than achieving concurrent operations through mutual exclusion, lock-free data structures rely on synchronization primitives such as compare-and-swap (CAS) while ensuring that no process is forced to wait for another process to complete a queue operation.  

FIFO Queue is a widely used data structure for parallel scenarios such as work assignment, which we discussed in class. A basic queue supports enqueue and dequeue. However, things can get tricky when we have multiple producers and consumers accessing shared resources concurrently.   

Our project will be implementing lock-free queue with CAS, fine-grained and coarse-grained queue. The key operations on these data structures are push and pop. After testing the correctness with the unit test framework, we will be focusing on comparing their performance on multi-processor machines under different workload and work distribution.  

## 3 Approach
### 3.1 Enviroment
We use C++ as our development language since it supports operations including CAS and mutex very well. Also we utilize third-party frameworks Google Benchmark to analyse the performance of different implementations of concurrent queue under contention with less pain. We use GHC machines as the platform to run the benchmark since it has CPU supporting CAS operations and has 16-cores to simulate multi-thread contention.
### 3.2 Parallel Problem Mapping
The parallel problem here is the Multi-Producer, Multi-Consumer problem for concurrent queues. We map each thread to either a consumer or a producer under certain predefined probability to analyse performance under different workload distributions (push and pop proportion). Each thread would do certain times of push/pop operation, as it is assigned beforehand. In doing so, we can analyze performance under various workloads.
### 3.3 Algorithm
The lock-free queue implementation made use of atomic Compare-and-Swap (CAS) operation. Note that we use a dummy node as head, meaning the actual element in the queue starts at the head's next node.  

The most challenging part in implementing the lock-free queue is to ensure the atomic operation can correctly update the queue without corruption from contention of other threads. For the push operation, we will be trying to update the current tail node’s next node to our new node with CAS(null, newNode). The semantics here are that the tail will only be atomically updated to the new node if it is still the tail of the queue with null as the next node. For the pop operation, we will be trying to move the current head to its next node if it exists with CAS(oldhead, newhead). The semantics are that the head will be updated atomically to the next node only when the next node has not been modified by other threads yet. Note that if the queue is empty, our pop operation will silently return.  

Both the fine-lock and coarse-lock queues are implemented using mutex. The coarse-grained queue was simply implemented by adding a global mutex lock to the cpp built in queue data structure. The fine-lock queue is more tricky. We implemented the unbounded queue with our own nodes so that we can use fine-grained locks on every node. After further consideration, we realized we can make optimization by only adding locks on push and poll operation respectively, meaning that we can reduce the lock number from O(n) to O(1) - only two locks are required. To achieve this, we refactored our implementation by using a dummy node as the head, so that we can make sure that the push operation and pop operation will not corrupt each other.   
## 4 Performance Measurement and Results
To evaluate performance we use third-party frameworks Google Benchmark to analyse the performance of different implementations of concurrent queue. In Google Benchmark’s multithreaded test, it is guaranteed that none of the threads will start until all have reached the start of the benchmark loop, and all will have finished before any thread exits the benchmark loop. The number of iterations that the benchmarked code will be run is determined dynamically to ensure that the ultimate result is statistically stable.    

Since our benchmarked code does not use threads internally, Google benchmark’s CPU Timer provides a good enough measurement for latency comparisons. We use the operation throughput (items pushed and popped per second) which is calculated based on CPU time, as the main measurement of performance for each of our implementations.
## 4.1 Performance Analyses of Push and Push Operations
### 4.1.1 Performance Comparison between Different Implementations
We first look at the performance of push and pop operations alone. To measure the throughput of pop, we first pause timing, insert a number of elements, then start timing, and pop all these elements out.   

From Figure 1, we can see that the pop operation of the lock-free implementation achieves 2 times the throughput of coarse-grained locked queue and about 4 times the throughput of fine-grained locked queue in both low-contention region (low number of threads) and high-contention region (high number of threads). Interestingly, the pop performance of lock-free queue under low-contention is significantly better than its performance under medium-contention. From medium-contention to high-contention, its performance improves again. Our guess is that from low-contention to medium contention, there is significant increase in cache-coherence traffic (since under threadnum = 1 there is basically no cache coherence traffic), jeopardizing the performance severely. But as thread number further increases we begin to enjoy the benefits of parallelism.  
However, from Figure 2, we see that the push performance of  the lock-free implementation is worst among the three under low-contention and only slightly better than the other lock-based implementations under high contention. Our guess for the reason is that the CAS-based lock-free queue needs to update two shared locations when doing a push: 1) make the last node point to the new node and 2) make the Tail pointer point to the new node. Hence, while the pop operation only calls compare_exchange_weak once, the push operation calls  compare_exchange_weak twice, hence we can estimate that its contention is roughly two times the contention. To confirm our hypothesis, we further compare the throughputs of Push and Pop operations.  

### 4.1.2 Deeper Analysis of Push and Pop Throughputs

As Figure 3 shows, under medium-contention (threadnum = 4, 8) scenarios, when each thead’s sync time is relatively small compared to its work time, the throughput of Pop is only slightly higher than the throughput of Push. This is expected because our implementation of push has a few more operations than our implementation of Pop.   

Under high-contention scenarios (threadnum = 16, 32) when sync time dominates, the throughput of Pop is roughly two times the throughput of Push, showing that the Push operation under high thread numbers has roughly 2x the contention than the Pop operation. Thus, it shows that our hypothesis in 4.1.1 is likely correct. The reason for Push operation’s performance is the need to update two shared locations when doing a push.  

## 4.2  Performance Analysis under Different Push/Pop Distribution
### 4.2.1 Evenly Distributed

The first scenario is evenly distributed push and pop operations: 50% push and 50% pop. To test this scenario, we assign each thread a certain number of operations. For each operation, there is a 50% chance that the thread pops and a 50% chance that the thread pushes. Since the number of operations is sufficiently large and Google Benchmark runs many iterations, we can estimate the distribution to be 50% push - 50% pop.  

As we can see in Figure 4, the performance of lock-based implementations decreases as the thread number increases, while the performance of lock-free implementation increases linearly. Starting from threadnum = 4, the lock-free implementation begins to outperform the other two implementations significantly.  

### 4.2.2 Unevenly Distributed Operations

The second scenario is unevenly distributed push and pop operations. We investigate the performance comparison of Push-heavy operations (roughly 80% push) and Pop-heavy operations (roughly 80% pop). For this test we used the same method as we did in the evenly distributed case. Since the number of operations is sufficiently large and Google Benchmark runs many iterations, we can estimate the actual distribution to be 80-20 and 20-80, respectively. 

As we can see in Figure 5 and 6, in both cases, the performance of lock-free implementation increases as the number of threads increases and outperforms the other two implementations under medium and high contention. However, under Push-heavy operations the lock-free implementation only achieves 2x the throughput of lock-based implementations, while under Pop-heavy operations it achieves more than 10x the throughput of lock-based implementations.  

Based on our results from the isolated evaluation of Push and Pop operations, the performance difference between Push-heavy operations and Pop-heavy operations is expected, since CAS-based pop performs much better than CAS-based push operations under high contention.  

## 4.3 Performance Analysis under Different Workload Sizes
For this test we investigate the performance of different implementations of concurrent queue under different sizes of the workload. We choose the scenario even distribution for this test: 50% push operations and 50% pop operations. We define the workload size as the number of operations.   

Under all workload sizes, the lock-free implementation performs evenly distributed operations significantly better than the other two lock-based implementations. While the performance curves of the lock-free implementation under workload sizes of 512 and 4096 are roughly the same (linear improvement), under the workload size of 8192 there is a significant drop from 8 threads to 16 threads. Possibly we are hitting a memory threshold of structure size that jeopardizes our performance. In the following section, we generate the graph for unevenly distributed operations to further look at this performance bottleneck under high workload.  

### 4.3.1 Performance Bottleneck under High Workload Size
As we can see from Figure 10 and Figure 11, Push-Heavy operations under high workload size hit the bottleneck (possibly a memory threshold) earlier at 8 threads, while Pop-Heavy operations do not experience a bottleneck. Hence, our implementation works best when the operation distribution skews towards Pop.  



## 5 Reference
[1] John D. Valois. 1994.  Implementing Lock-Free Queues. To appear in Proceedings of the Seventh International Conference on Parallel and Distributed Computing Systems , Las Vegas, NV, October 1994. 
