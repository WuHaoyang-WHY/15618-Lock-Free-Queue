//
// Created by Haoyang Wu on 2021/12/1.
//

#ifndef INC_15618_LOCK_FREE_QUEUE_COARSE_LOCK_QUEUE_HPP
#define INC_15618_LOCK_FREE_QUEUE_COARSE_LOCK_QUEUE_HPP

#include <mutex>
#include <atomic>
#include <queue>
#include <optional>

template <typename T>

class coarse_lock_queue {

public:

    coarse_lock_queue() = default;

    ~coarse_lock_queue() = default;

private:

    std::queue<T> queue_;
    std::mutex global_lock;

public:

    std::optional<T> poll() {
        std::lock_guard<std::mutex> lock(global_lock);
        if (queue_.empty()) {
            return {};
        }
        T temp = queue_.front();
        queue_.pop();
        return temp;
    }

    void push(T val) {
        std::lock_guard<std::mutex> lock(global_lock);
        queue_.push(val);
    }

    unsigned long getSize() {
        std::lock_guard<std::mutex> lock(global_lock);
        return queue_.size();
    }

};

#endif //INC_15618_LOCK_FREE_QUEUE_COARSE_LOCK_QUEUE_HPP
