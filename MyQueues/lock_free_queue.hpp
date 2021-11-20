#ifndef _LOCK_FREE_QUEUE_H
#define _LOCK_FREE_QUEUE_H

#include <atomic>
#include <cstdlib>
#include <typeinfo>

using namespace std;
template <typename T>

class lock_free_queue {

public:
    lock_free_queue() {
        nullnode.store(new Node());
        Node* dummy = new Node(nullptr, nullnode);
//        dummy->next = nullnode;
        head.store(dummy);  // dummy node to start with.
        tail.store(dummy);

        size = 0;
    }

    ~lock_free_queue() {
        Node* ptr = head;
        while (ptr) {
            Node* next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }

private:
    struct Node
    {
        /* data */
        T* val;
        atomic<Node *> next;

        Node() : Node(nullptr, nullptr){}
        explicit Node(T* v) : Node(v, nullptr){}
        Node(T* v, Node* ne) : val(v), next(ne){}
    };

    /**
     * head always points to a dummy node. The real queue starts from head->next
     */
    atomic<Node *> head;
    atomic<Node *> tail;
    atomic<Node *> nullnode;
    atomic<int> size;

public:
    
    void push(T* val) {
        atomic<Node*> newNode = new Node(val, nullnode);

        Node* oldTail;
        Node* nullLoad;
        do {
            oldTail = tail.load();
//            printf("%s %s\n", typeid(oldTail).name(), typeid(newNode).name());
            nullLoad = nullnode.load();

        } while (!oldTail->next.compare_exchange_weak(nullLoad, newNode,
                                                      memory_order_release, memory_order_relaxed));

        // update tail to newNode if newNode is still tail with CAS.
        tail.compare_exchange_weak(oldTail, newNode,
                                    memory_order_release, memory_order_relaxed);

        size.fetch_add(1);
    }

    /**
     * @brief poll from the head of queue.
     * 
     * @return T* nullptr if queue is empty, else value of queue head.
     */
    T* poll() {
        Node* oldHead;
        do {
            oldHead = head.load();
//            printf("%s %s\n", typeid(oldHead).name(), typeid(oldHead->next).name());

            if (!oldHead->next || oldHead->next == nullnode) {
                return nullptr;
            }
        } while (!head.compare_exchange_weak(oldHead, oldHead->next,
                                             memory_order_release, memory_order_relaxed));

        T* returnVal = oldHead->next.load()->val;

        size.fetch_sub(1);
        return returnVal;
    }

    int getSize() {
        return size;
    }

};

#endif