#include <iostream>

#include "linkedListClass.h"

// return value when dequeueing/peeking empty list
#define MAX_INT 2147483647

// create new list
LinkedListQueue init(int capacity) {
    LinkedListQueue res(capacity);
    return res;
}

// add new node to tail
void LinkedListQueue::enqueue(int x) {
    ++num; // update node count 

    // if list is full
    if (num - 1 == capacity) {
        std::cout << "Error: list is full" << '\n';
        return;
    }

    // if list is empty
    if (!head) {
        head = new Node(x);
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;

        return;
    }

    // if list is not empty
    tail->next = new Node(x);
    tail = tail->next;
    tail->next = nullptr;

    return;
}

// get head value and delete head
int LinkedListQueue::dequeue() {
    // if list is empty
    if (!head) {
        return MAX_INT;
    }

    // if list is not empty
    --num; // update node count
    int res = head->data; // get return value

    // update head and tail
    // head = head->next;
    // if (tail == head->prev) {
    //     tail = head;
    // }

    // clean up node pointers
    // if (head) {
    //     delete head->prev;
    //     head->prev = nullptr;
    // }

    return res;
}

// get head value without deleting head
int LinkedListQueue::peek() {
    if (!head) {
        return MAX_INT;
    }
    return head->data;
}

// check if list is empty
bool LinkedListQueue::isEmpty() {
    return (!num);
}

//check if list is full
bool LinkedListQueue::isFull() {
    return (num == capacity);
}

// remove all nodes
void LinkedListQueue::clear() {
    while (head) {
        dequeue();
    }
    return;
}