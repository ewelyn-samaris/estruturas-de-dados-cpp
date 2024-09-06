
typedef int ItemType;

const int MAX_ITEMS = 100;

class Stack {
    private: 
    int size;
    ItemType* structure;

    public:
    Stack();
    ~Stack();
    bool isEmpty(); 
    bool isFull();
    void push(ItemType item);
    ItemType pop();
    void print(); 
    int getSize();
};