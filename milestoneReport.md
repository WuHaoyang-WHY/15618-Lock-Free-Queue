# Final Project Milestone Report
Yutong Zhu (yutongz3)  
Haoyang Wu (haoyang2)  

November 20, 2021  

[Project GITHUB](https://github.com/WuHaoyang-WHY/15618-Lock-Free-Queue)  
[MileStone Report URL](https://wuhaoyang-why.github.io/15618-Lock-Free-Queue/milestoneReport)

## Schedule
  
| Week | Task |Progress |  
| --- | --- | --- |  
| Nov 5 - Nov 12|Read paper and study implementation of lock free queue|Done|
| Nov 13 - Nov 19|Implement lock free queue and unit tests|Done|
| Nov 20 - Nov 26|Implement lock based queue with coarse-granularity lock|In progress(Haoyang Wu)|
|               |Implement lock based queue with fine-granularity lock|In progress(Yutong Zhu)|
|Nov 27 - Dec 3|Evaluate and analyse performance|TODO|
|Dec 4 - Dec 10|Finish final report and poster|TODO|

## Work Completed
We finished the implementation of the lock-free queue using CAS based on [Implementing Lock-Free Queues by John D. Valois](https://people.cs.pitt.edu/~jacklange/teaching/cs2510-f12/papers/implementing_lock_free.pdf) and we also finished the unit tests with multi-thread using google test module. 
We are working on performance evaluation using google benchmark. We are also working on the lock-based implementations using different granularities.

## Goals
Overall we think we are making progress according to our schedule. 

Our plans are still to implement the lock-free queue, test its correctness and also evaluate its performance along with other concurrent queue solutions (e.g., traditional lock techniques).

We still plan to achieve the following goals:

1. Implement lock-free queue with CAS (already implemented and tested)
2. Implement queues with lock of different granularity
3. Evaluate and conduct performance analysis.

## Deliverable
The deliverable we plan to show at the poster session will be performance graphs of the 2-3 different implementations. We will compare these graphs to determine if the performance of our implementation is as desired.

## Hope to achieve
Whether we will attempt to do the “hope to achieve” goals depends on our subsequent progress in evaluating the performance.

## Results
As we are still implementing the concurrent tests, we do not have results of performance evaluation as of now. However, once we completed the tests we will be able to present some results.

## Issues
One of our current issues is to test the lock-free queue using concurrent threads. Multi-thread program behavior is difficult to predict inherently, causing the unit test almost impossible to list all the scenarios that might happen. But we will try to explore the unit test cases as thoroughly as we can.

The other issue we encountered is the ABA problem. Currently we solve the problem by using memory points instead of the actual values. We will need testing to see if it has been successfully resolved.
