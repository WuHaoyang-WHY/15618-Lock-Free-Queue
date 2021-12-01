//
// Created by Haoyang Wu on 2021/11/19.
//

#include <lock_free_queue.hpp>
#include "gtest/gtest.h"
#include "algorithm"
#include "vector"
#include "thread"
#include "random"
#include "time.h"

class CASQueueTest : public ::testing::Test {
protected:
    void SetUp() override {
        q1_.push(reinterpret_cast<int *>(1));
        q2_.push(reinterpret_cast<int *>(1));
        q2_.push(reinterpret_cast<int *>(2));
        q2_.push(reinterpret_cast<int *>(3));
    }

    // void TearDown() override {}
//    static default_random_engine e;
    lock_free_queue<int> q0_;
    lock_free_queue<int> q1_;
    lock_free_queue<int> q2_;
    std::vector<std::thread> consumerThreads;
    std::vector<std::thread> producerThreads;

    static int* getRandomNumber() {
        srand((unsigned)time(0));
        int number = (rand()%100);

        return reinterpret_cast<int *>(number);
    }

    static void producerTask(lock_free_queue<int>* queue) {
        queue->push(getRandomNumber());
    }

    static void consumerTask(lock_free_queue<int>* queue) {
        queue->poll();
    }

    void initProducers(int num, lock_free_queue<int>* queue) {
        for (int i = 0; i < num; i ++) {
            producerThreads.emplace_back(producerTask, queue);
        }
    }

    void initConsumers(int num, lock_free_queue<int>* queue) {
        for (int i = 0; i < num; i ++) {
            consumerThreads.emplace_back(consumerTask, queue);
        }
    }

    void run(lock_free_queue<int>* queue, int consumerNum, int producerNum) {
        initProducers(producerNum, queue);
        initConsumers(consumerNum, queue);

        for (int i = 0; i < producerNum; i ++) {
            producerThreads[i].join();
        }
        for (int i = 0; i < consumerNum; i ++) {
            consumerThreads[i].join();
        }

        EXPECT_EQ(queue->getSize(), max(producerNum - consumerNum, 0));
    }

};

TEST_F(CASQueueTest, TestEmptyQueue) {
    EXPECT_EQ(q0_.getSize(), 0);
    q0_.push(reinterpret_cast<int *>(1));
    EXPECT_EQ(q0_.getSize(), 1);
    auto poped = q0_.poll();
    EXPECT_EQ(q0_.getSize(), 0);
    EXPECT_EQ(poped, reinterpret_cast<int *>(1));
}

TEST_F(CASQueueTest, TestMultiThreadSameAmount) {
    lock_free_queue<int> queue;
    run(&queue, 100, 100);
}

TEST_F(CASQueueTest, TestMultiThreadMoreProducer) {
    lock_free_queue<int> queue;
    run(&queue, 100, 200);
}

TEST_F(CASQueueTest, TestMultiThreadMoreConsumer) {
    lock_free_queue<int> queue;
    run(&queue, 200, 200);
}

//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
