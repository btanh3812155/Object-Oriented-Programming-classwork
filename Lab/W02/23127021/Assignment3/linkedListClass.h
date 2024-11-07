// Node for linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data) {};
};

class LinkedListQueue {
private:
    // List data
    Node* head;
    Node* tail;
    int capacity;
    int num;

public:
    // Constructor
    LinkedListQueue(int capacity) : capacity(capacity),
                                    num(0),
                                    head(nullptr),
                                    tail(nullptr) {};
    // Functions
    static LinkedListQueue* init(int capacity);
    void enqueue(int x);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
};