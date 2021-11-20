//
// Created by Haoyang Wu on 2021/11/19.
//

#include "MyQueues/lock_free_queue.hpp"
#include <gtest/gtest.h>

int main() {
    lock_free_queue<int> lockFreeQueue;
    lockFreeQueue.push((int*) 1);
    lockFreeQueue.poll();

    printf("%d", lockFreeQueue.getSize());
    return 0;
}
