//
// Created by Haoyang Wu on 2021/12/1.
//

#include "benchmark/benchmark.h"
#include "coarse_lock_queue.hpp"
#include "fine_lock_queue.hpp"
#include "lock_free_queue.hpp"


static int getRandomNumber() {
    srand((unsigned)time(0));
    int number = (rand()%100);

    return number;
}

// test performance of pure push operation
template <class Q> static void BM_Push(benchmark::State& state) {
    static Q* q;
    if (state.thread_index() == 0) {
        q = new Q();
    }

    auto opsTime = state.range(0) / state.threads();
    for (auto _: state) {

        for (int i = 0; i < opsTime; i ++) {
            q->push(0);
        }
    }
    state.SetItemsProcessed(opsTime * state.threads() * state.iterations());

    if (state.thread_index() == 0) {
//        printf("Queue size: %ld\n", q->getSize());
        delete q;
    }
}
//
//BENCHMARK_TEMPLATE(BM_Push, coarse_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
//BENCHMARK_TEMPLATE(BM_Push, fine_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
//BENCHMARK_TEMPLATE(BM_Push, lock_free_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);

// test performance of pure poll op
template <class Q> static void BM_Poll(benchmark::State& state) {
    static Q* q;

    if (state.thread_index() == 0) {
        q = new Q();
    }

    auto opsTime = state.range(0) / state.threads();
    for (auto _: state) {
        state.PauseTiming();
        for (int i = 0; i < opsTime; i ++) {
            q->push(0);
        }
        state.ResumeTiming();

        for (int i = 0; i < opsTime; i ++) {
            q->poll();
        }
    }
    state.SetItemsProcessed(opsTime * state.threads() * state.iterations());

    if (state.thread_index() == 0) {
//        printf("Queue size: %ld\n", q->getSize());
        delete q;
    }
}
//
//BENCHMARK_TEMPLATE(BM_Poll, coarse_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
//BENCHMARK_TEMPLATE(BM_Poll, fine_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
//BENCHMARK_TEMPLATE(BM_Poll, lock_free_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);


// test performance of half push, half pop
template <class Q> static void BM_half_push_poll(benchmark::State& state) {
    static Q* q;

    if (state.thread_index() == 0) {
        q = new Q();
    }

    auto opsTime = state.range(0) / state.threads();
    for (auto _: state) {
        for (int i = 0; i < opsTime; i ++) {
            if (getRandomNumber() >= 50) {
                q->push(0);
            }
            else {
                q->poll();
            }
        }
    }
    state.SetItemsProcessed(opsTime * state.threads() * state.iterations());

    if (state.thread_index() == 0) {
//        printf("Queue size: %ld\n", q->getSize());
        delete q;
    }
}

//
//BENCHMARK_TEMPLATE(BM_half_push_poll, coarse_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
//BENCHMARK_TEMPLATE(BM_half_push_poll, fine_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
//BENCHMARK_TEMPLATE(BM_half_push_poll, lock_free_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);

// test performance of half push, half pop
template <class Q> static void BM_80_push_20_poll(benchmark::State& state) {
    static Q* q;

    if (state.thread_index() == 0) {
        q = new Q();
    }

    auto opsTime = state.range(0) / state.threads();
    for (auto _: state) {
        for (int i = 0; i < opsTime; i ++) {
            if (getRandomNumber() >= 20) {
                q->push(0);
            }
            else {
                q->poll();
            }
        }
    }
    state.SetItemsProcessed(opsTime * state.threads() * state.iterations());

    if (state.thread_index() == 0) {
//        printf("Queue size: %ld\n", q->getSize());
        delete q;
    }
}

//
//BENCHMARK_TEMPLATE(BM_80_push_20_poll, coarse_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
//BENCHMARK_TEMPLATE(BM_80_push_20_poll, fine_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
//BENCHMARK_TEMPLATE(BM_80_push_20_poll, lock_free_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);

// test performance of half push, half pop
template <class Q> static void BM_20_push_80_poll(benchmark::State& state) {
    static Q* q;

    if (state.thread_index() == 0) {
        q = new Q();
    }

    auto opsTime = state.range(0) / state.threads();
    for (auto _: state) {
        for (int i = 0; i < opsTime; i ++) {
            if (getRandomNumber() >= 80) {
                q->push(0);
            }
            else {
                q->poll();
            }
        }
    }
    state.SetItemsProcessed(opsTime * state.threads() * state.iterations());

    if (state.thread_index() == 0) {
//        printf("Queue size: %ld\n", q->getSize());
        delete q;
    }
}


BENCHMARK_TEMPLATE(BM_20_push_80_poll, coarse_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
BENCHMARK_TEMPLATE(BM_20_push_80_poll, fine_lock_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);
BENCHMARK_TEMPLATE(BM_20_push_80_poll, lock_free_queue<int>)->ThreadRange(1<<0, 1<<8)->Range(8<<3, 8<<10);

BENCHMARK_MAIN();