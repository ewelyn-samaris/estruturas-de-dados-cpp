#include<iostream>
#include "hash.h"

// Método: Encadeamento interior homogêneo (Teste linear)
// Usaremos -1 para vazio e -2 para disponível (removido)

int Hash::HashFunction(Aluno aluno)
{
    return aluno.getId() % MAX_POSITIONS;
}

Hash::Hash(int arraySize, int maxItems)
{
    itemsQuantity = 0;
    MAX_ITEMS = maxItems;
    MAX_POSITIONS = arraySize;
    structure = new Aluno[arraySize];
}

Hash::~Hash()
{
    delete [] structure;
}

bool Hash::isFull()
{
    return this->getItemsQuantity() == this->MAX_ITEMS;
}

int Hash::getItemsQuantity()
{
    return this->itemsQuantity;
}

void Hash::push(Aluno aluno)
{
    if(isFull()) {
        cout << "\nNao eh possivel inserir o elemento. A Hash table esta cheia\n";
    } else {
        int position = this->HashFunction(aluno);
        while(structure[position].getId() > 0) { 
            // posso inserir em espaços vazios (-1) e disponíveis (-2, removidos)
            position = (position + 1) % MAX_POSITIONS;
        }
        this->structure[position] = aluno;
        this->itemsQuantity++;
    }
}

void Hash::pop(Aluno aluno)
{
    int position = this->HashFunction(aluno);
    bool found = false;
    while(structure[position].getId() != -1) {
        if(structure[position].getId() == aluno.getId()) {
            found = true;
            structure[position] = Aluno(-2, " "); // -2 é removido
            itemsQuantity--;
            cout << "\nElemento removido!\n";
            break;
        }
        position = (position + 1) % MAX_POSITIONS;
    }
    if(!found) {
        cout << "\nAluno a ser removido nao encontrado. nenhum elemento foi removido!\n";
    }
}

void Hash::search(Aluno& aluno, bool& found)
{
    // A busca só é interrompida se encontrar elemento ou posição vazia
    found = false;
    int position = this->HashFunction(aluno);
    while(structure[position].getId() != -1) {
        if(structure[position].getId() == aluno.getId()) {
            aluno = structure[position];
            found = true;
            cout << "\nElemento encontrado: " << aluno.getId() << " " << aluno.getName() << "\n";
            break;
        }
        position = (position + 1) % MAX_POSITIONS;
    }

    if(!found) {
        cout << "\nAluno nao encontrado.\n";
    }
}

void Hash::print()
{
    cout << "\nHash Table: [";
    for(int i =0; i< MAX_POSITIONS; ++i) {
        if(structure[i].getId() > 0) { // excluo -1 vazio e -2 removidos
            cout << "\n" << i << ": " << structure[i].getId() << " " << structure[i].getName();
        }
    }
    cout << "\n]\n";
}
