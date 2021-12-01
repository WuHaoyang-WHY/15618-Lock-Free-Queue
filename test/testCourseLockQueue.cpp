//
// Created by Haoyang Wu on 2021/11/19.
//

#include <coarse_lock_queue.hpp>
#include "gtest/gtest.h"
#include "algorithm"
#include "vector"
#include "thread"
#include "time.h"



class CoarseLockQueueTest : public ::testing::Test {
protected:
    void SetUp() override {
        q1_.push(1);
        q2_.push(1);
        q2_.push(2);
        q2_.push(3);
    }

    // void TearDown() override {}
//    static default_random_engine e;
    coarse_lock_queue<int> q0_;
    coarse_lock_queue<int> q1_;
    coarse_lock_queue<int> q2_;
    std::vector<std::thread> consumerThreads;
    std::vector<std::thread> producerThreads;

    static int getRandomNumber() {
        srand((unsigned)time(0));
        int number = (rand()%100);

        return number;
    }

    static void producerTask(coarse_lock_queue<int>* queue) {
        queue->push(getRandomNumber());
    }

    static void consumerTask(coarse_lock_queue<int>* queue) {
        queue->poll();
    }

    void initProducers(int num, coarse_lock_queue<int>* queue) {
        for (int i = 0; i < num; i ++) {
            producerThreads.emplace_back(producerTask, queue);
        }
    }

    void initConsumers(int num, coarse_lock_queue<int>* queue) {
        for (int i = 0; i < num; i ++) {
            consumerThreads.emplace_back(consumerTask, queue);
        }
    }

    void run(coarse_lock_queue<int>* queue, int consumerNum, int producerNum) {
        initProducers(producerNum, queue);
        initConsumers(consumerNum, queue);

        for (int i = 0; i < producerNum; i ++) {
            producerThreads[i].join();
        }
        for (int i = 0; i < consumerNum; i ++) {
            consumerThreads[i].join();
        }

        EXPECT_EQ(queue->getSize(), std::max(producerNum - consumerNum, 0));
    }

};

TEST_F(CoarseLockQueueTest, TestEmptyQueue) {
    EXPECT_EQ(q0_.getSize(), 0);
    q0_.push(1);
    EXPECT_EQ(q0_.getSize(), 1);
    auto poped = q0_.poll();
    EXPECT_EQ(q0_.getSize(), 0);
    EXPECT_EQ(poped, 1);
}

TEST_F(CoarseLockQueueTest, TestMultiThreadSameAmount) {
    coarse_lock_queue<int> queue;
    run(&queue, 100, 100);
}

TEST_F(CoarseLockQueueTest, TestMultiThreadMoreProducer) {
    coarse_lock_queue<int> queue;
    run(&queue, 100, 200);
}

TEST_F(CoarseLockQueueTest, TestMultiThreadMoreConsumer) {
    coarse_lock_queue<int> queue;
    run(&queue, 200, 200);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
