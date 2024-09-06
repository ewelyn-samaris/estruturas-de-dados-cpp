#include <iostream>
#include "pilha.h"

using namespace std;

    Stack::Stack() 
    {
        size = 0;
        structure = new ItemType[MAX_ITEMS];
    }

    Stack::~Stack()
    {
        delete [] structure;
    }

    bool Stack::isFull()
    {
        return size == MAX_ITEMS;
    }

    bool Stack::isEmpty()
    {
        return size == 0;
    }

    void Stack::push(ItemType item)
    {
        if(isFull()) {
            cout << "A pilha esta cheia. Nao eh possivel inserir o elemento\n";
        } else{
            structure[size] = item;
            ++size;
        }
    }

    ItemType Stack::pop()
    {
        if(isEmpty()){
            cout << "A pilha esta vazia. Nao existe elementos a serem removidos\n";
            return -1;
        } else {
            size--;
            return structure[size];
        }
    }

    void Stack::print()
    {
        cout << "Pilha: [ ";
        for(int i = 0; i < size; i++) {
            cout << structure[i] << " ";
        }
        cout << "]\n";
    }

    int Stack::getSize()
    {
        return size;
    }
