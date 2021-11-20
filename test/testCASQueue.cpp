////
//// Created by Haoyang Wu on 2021/11/19.
////
//
//#include <lock_free_queue.hpp>
//#include "gtest/gtest.h"
//
//class CASQueueTest : public ::testing::Test {
//protected:
//    void SetUp() override {
//        q1_.push(reinterpret_cast<int *>(1));
//        q1_.poll();
//    }
//
//    // void TearDown() override {}
//
//    lock_free_queue<int> q0_;
//    lock_free_queue<int> q1_;
//    lock_free_queue<int> q2_;
//};
//
//TEST_F(CASQueueTest, TestEmptyQueue) {
//
//}
//
//
////int main(int argc, char **argv) {
////    ::testing::InitGoogleTest(&argc, argv);
////    return RUN_ALL_TESTS();
////}
