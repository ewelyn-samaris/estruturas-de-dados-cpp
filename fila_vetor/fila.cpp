#include <iostream>
#include "fila.h"

using namespace std;

Queue::Queue()
{
    first = 0;
    last = 0;
    structure = new ItemType(MAX_ITEMS);
}

Queue::~Queue()
{
    delete [] structure;
}

bool Queue::isEmpty()
{
    return first == last;
}

bool Queue::isFull()
{
    return (last - first) == MAX_ITEMS;
}

void Queue::enqueue(ItemType item)
{
    if(isFull()) {
        cout << "Fila esta cheia. Não eh possivel inserir elementos\n";
    } else{
        structure[last % MAX_ITEMS] = item;
        last++;
        cout << "Elemento " << item << " inserido na fila com sucesso\n";
    }
}

ItemType Queue::dequeue()
{
    if(isEmpty()) {
        cout << "Fila esta vazia. Nao ha elementos a serem removidos\n";
        return -1;
    } else{
        first++;
        return structure[(first-1) % MAX_ITEMS];
    }
}

void Queue::print()
{
    cout << "Fila: [ ";
    for(int i = first; i < last; ++i ){
        cout << structure[i % MAX_ITEMS] << " ";
    }
    cout << "]\n";
}
