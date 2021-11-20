//
// Created by Haoyang Wu on 2021/11/19.
//

#include <lock_free_queue.hpp>
#include "gtest/gtest.h"
#include "algorithm"
#include "vector"
#include "cstdlib"
#include "thread"
#include "random"

class CASQueueTest : public ::testing::Test {
protected:
    void SetUp() override {
        q1_.push(reinterpret_cast<int *>(1));
        q2_.push(reinterpret_cast<int *>(1));
        q2_.push(reinterpret_cast<int *>(2));
        q2_.push(reinterpret_cast<int *>(3));
    }

    // void TearDown() override {}
    default_random_engine e;
    lock_free_queue<int> q0_;
    lock_free_queue<int> q1_;
    lock_free_queue<int> q2_;
    std::vector<std::thread> consumerThreads;
    std::vector<std::thread> producerThreads;

    int* getRandomNumber() {
        int number = e()%100;

        return reinterpret_cast<int *>(number);
    }

    void producerTask(lock_free_queue<int>* queue) {
        queue->push(getRandomNumber());
    }

    void consumerTest(lock_free_queue<int>* queue) {
        queue->poll();
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



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
