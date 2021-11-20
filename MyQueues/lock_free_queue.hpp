#ifndef _LOCK_FREE_QUEUE_H
#define _LOCK_FREE_QUEUE_H

#include <atomic>
#include <cstdlib>

using namespace std;
template <typename T>

class lock_free_queue {

public:
    lock_free_queue() {
        head = tail = (Node *) malloc(sizeof(Node));    // dummy node to start with.
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
    atomic<Node *> head, tail;

public:
    
    void push(T* val) {
        Node* newNode = (Node *) malloc(sizeof(Node));
        newNode->val = val;

        Node* oldTail;
        do {
            oldTail = tail.load();
        } while (!oldTail->next.load().compare_exchange_weak(nullptr, newNode));   // insert new node to tail with CAS.

        tail->compare_exchange_weak(oldTail, newNode);  // update tail to newNode if newNode is still tail with CAS.
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
            if (!oldHead->next) {
                return nullptr;
            }
        } while (head->compare_exchange_weak(oldHead, oldHead->next));

        T* returnVal = oldHead->next->val;
        // free oldHead
        free(oldHead);

        return returnVal;
    }

};

#endif