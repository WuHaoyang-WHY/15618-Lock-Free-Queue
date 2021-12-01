//
// Created by Haoyang Wu on 2021/12/1.
//

#ifndef INC_15618_LOCK_FREE_QUEUE_FINE_LOCK_QUEUE_HPP
#define INC_15618_LOCK_FREE_QUEUE_FINE_LOCK_QUEUE_HPP

#include <mutex>
#include <atomic>
#include <queue>
#include <optional>

using namespace std;
template <typename T>

/**
 * For the fine lock queue, we use a dummy head to separate operation of push and pop. So we only need
 * two locks: push lock and pop lock, instead of every fine lock on each node.
 *
 * @tparam T
 */
class fine_lock_queue {

public:

    fine_lock_queue() {
        head = new Node();
        tail = head;
        head->next = nullptr;
        size.store(0);
    }

    ~fine_lock_queue() {
        Node* ptr = head;
        while (ptr) {
            Node* next = ptr->next;
            delete ptr;
            ptr = next;
        }
        size.store(0);
    }

private:

    struct Node {
        T val;
        Node* next;
    };

    Node* head;
    Node* tail;

    std::mutex head_lock;
    std::mutex tail_lock;

    atomic<int> size{};

public:

    std::optional<T> poll() {
        std::lock_guard<std::mutex> lock(head_lock);
        Node* head_next = head->next;
        if (!head_next) {   // empty queue
            return {};
        }
        delete head;
        head = head_next;
        size.fetch_sub(1);

        return head->val;
    }

    void push(T val) {
        Node* newNode = new Node();
        newNode->val = val;
        newNode->next = nullptr;
        std::lock_guard<std::mutex> lock(tail_lock);
        tail->next = newNode;
        tail = newNode;

        size.fetch_add(1);
    }

    unsigned long getSize() {
        return size;
    }

};

#endif //INC_15618_LOCK_FREE_QUEUE_FINE_LOCK_QUEUE_HPP
