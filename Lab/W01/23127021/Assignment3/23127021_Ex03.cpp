#include "linkedListStruct.cpp"

int main() {
    //Testing
    LinkedListQueue testList = init(10); // new list
    
    // with no nodes
    std::cout << "Node count: " << testList.num << '\n';
    std::cout << "Is empty: " << testList.isEmpty() << '\n';
    std::cout << "Dequeue with no nodes: " << testList.dequeue() << '\n';
    std::cout << "Peek with no nodes: " << testList.peek() << '\n';

    // adding some nodes
    for (int i = 0; i < 5; ++i) {
        testList.enqueue(1);
    }
    std::cout << "Dequeue: " << testList.dequeue() << '\n';
    std::cout << "Peek: " << testList.peek() << '\n';

    // adding nodes until full
    for (int i = 0; i < 6; ++i) {
        testList.enqueue(i+10);
    }
    std::cout << "Is full: " << testList.isFull() << '\n';
    std::cout << "Adding when full" << '\n';
    testList.enqueue(100);

    // clearing all nodes
    testList.clear();
    std::cout << "Is empty: " << testList.isEmpty() << '\n';
}