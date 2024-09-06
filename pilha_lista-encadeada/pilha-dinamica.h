#include "node.h"

typedef int ItemType;

class DynamicStack {
    private:
    Node* TopNode;

    public:
    DynamicStack();
    ~DynamicStack();
    bool isEmpty();
    bool isFull();
    void push(ItemType item);
    ItemType pop();
    void print();
};
