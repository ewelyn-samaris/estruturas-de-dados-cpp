#include "node.h"

typedef int ItemType;

class DynamicQueue {
    private:
    Node* Front;
    Node* Rear;

    public:
    DynamicQueue();
    ~DynamicQueue();
    bool isEmpty();
    bool isFull();
    void enqueue(ItemType item);
    ItemType dequeue();
    void print();
};