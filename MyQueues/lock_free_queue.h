#ifndef _LOCK_FREE_QUEUE_H
#define _LOCK_FREE_QUEUE_H

#include <atomic>

using namespace std;
template <typename T>

class lock_free_queue { 
public:


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

    

};

#endif