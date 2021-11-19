#ifndef _LOCK_FREE_QUEUE_H
#define _LOCK_FREE_QUEUE_H

#include <atomic>

using namespace std;
template <typename T>

class lock_free_queue { 

private:
    struct Node
    {
        /* data */
        T* val;
        atomic<Node *> next;

        Node() : Node(nullptr, nullptr){}
        Node(T* v) : Node(v, nullptr){}
        Node(T* v, Node* ne) : val(v), next(ne){}
    };

    atomic<Node *> head, tail;

public:
    
    // TODO: add if-else to fix scenerio of when queue is empty(oldTail->next would cause NullPTRException)
    void push(T* val) {
        Node* newNode = new Node(val);
        Node* oldTail;
        do {
            oldTail = tail.load();
        } while (!oldTail->next.compare_exchange_weak(nullptr, newNode));   // insert new node to tail with CAS.

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
        } while (oldHead && !head.compare_exchange_weak(oldHead, oldHead->next));
        
        return oldHead? oldHead->val :nullptr;
    }
    

};

#endif