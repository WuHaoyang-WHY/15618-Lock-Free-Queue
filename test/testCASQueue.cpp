//
// Created by Haoyang Wu on 2021/11/19.
//

#include <lock_free_queue.hpp>
#include "gtest/gtest.h"

class CASQueueTest : public ::testing::Test {
protected:
    void SetUp() override {

    }

    // void TearDown() override {}

    lock_free_queue<int> q0_;
    lock_free_queue<int> q1_;
    lock_free_queue<int> q2_;
};

