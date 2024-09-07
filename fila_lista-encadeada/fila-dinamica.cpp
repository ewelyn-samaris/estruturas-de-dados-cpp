#include "fila-dinamica.h"
#include <iostream>
#include <cstddef>


using namespace std;

DynamicQueue::DynamicQueue() 
{
    Front = Rear = NULL;
}

DynamicQueue::~DynamicQueue() 
{
    Node* TempNode;
    while(Front != NULL) {
        TempNode = Front;
        Front = Front->next;
        delete TempNode;
    }
    Rear = NULL;
}

bool DynamicQueue::isEmpty() 
{
 return Front == NULL;
}

bool DynamicQueue::isFull() 
{
    Node* TempNode;
    try {
        TempNode = new Node();
        delete TempNode;
        return false;
    } catch(bad_alloc exception) {
        return true;
    }
}

void DynamicQueue::enqueue(ItemType item) 
{
    if(isFull()) {
        cout << "\nCan't enqueue item. Queue is full!\n";
    } else {
        Node* node = new Node();
        node->value = item;
        node->next = NULL;
        
        if(isEmpty()) {
            Front = node;
        } else {
            Rear->next = node; // Atualizo o atual último para apontar para esse novo nó que agora é o último
        }
        Rear = node;
    }

}

ItemType DynamicQueue::dequeue() 
{
    if(isEmpty()) {
        cout << "\nQueue is empty. There's no item to dequeue!\n";
        return -1;
    } else {
        Node* TempNode = Front;
        ItemType deletedItem = Front->value;
        Front = Front->next;
        delete TempNode;
        if(isEmpty()) Rear = NULL;
        return deletedItem;
    }
}

void DynamicQueue::print() 
{
    Node* TempNode = Front;
    cout << "\n\nFila: [ ";
    while(TempNode != NULL) {
        cout << TempNode->value << " ";
        TempNode = TempNode->next;
    }
    cout << "]\n\n";
}
