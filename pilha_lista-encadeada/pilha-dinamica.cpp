#include <iostream>
#include "pilha-dinamica.h"
#include <cstddef>

using namespace std;

DynamicStack::DynamicStack()
{
    TopNode = NULL;
}

DynamicStack::~DynamicStack()
{
    Node* TempNode;
    while(TopNode != NULL) {
        TempNode = TopNode;
        TopNode = TopNode->next;
        delete TempNode;
    }
}

bool DynamicStack::isEmpty()
{
    return TopNode == NULL;
}

bool DynamicStack::isFull()
{
    // Tento criar um novo nó, caso consiga
    // ainda há espaço na memória para a alocação
    Node* NewNode;

    try{
        NewNode = new Node();
        delete NewNode;
        return false;
    } catch(bad_alloc exception) { // exception é apenas o nome da variável que é do tipo bad_alloc
        // por ser fortemente tipada, é preciso especificar o tipo exato da exceção a ser capturada
        return true;
    }
}

void DynamicStack::push(ItemType item)
{
    if(isFull()) {
        cout << "A pilha esta cheia. Nao foi possivel inserir o elemento.\n";
    } else {
        Node* node = new Node();
        node->value = item;
        node->next = TopNode; // O next aponta p/ o antigo topo pois percorremos a pilha do topo para baixo
        TopNode = node;
    }
}

ItemType DynamicStack::pop()
{
    if(isEmpty()) {
        cout << "A pilha está vazia. Não há itens a serem removidos\n";
        return -1;
    } else {
        // Atualizo o ponteiro TopNode para o próximo do atual TopNode
        // Desaloco a memória de TopNode
        // retorno o valor do nó removido
        Node* TempNode = TopNode;
        ItemType deletedItem = TopNode->value;
        TopNode = TopNode->next;
        delete TempNode;
        return deletedItem;
    }
}

void DynamicStack::print()
{
    Node* node = TopNode;
    cout << "Pilha: [ ";
    while(node != NULL) {
        // O primeiro elemento a ser impresso é o último, em seguida o penúltimo e assim sucessivamente
        cout << node->value << " ";
        node = node->next;
    }
    cout << "]\n";
}
