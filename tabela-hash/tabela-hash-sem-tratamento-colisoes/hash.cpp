#include<iostream>
#include "hash.h"

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
    // sem tratamento de colisões
    if(isFull()) {
        cout << "\nNao eh possivel inserir o elemento. A Hash table esta cheia\n";
    } else {
        int position = this->HashFunction(aluno);
        this->structure[position] = aluno;
        this->itemsQuantity++;
    }
}

void Hash::pop(Aluno aluno)
{
    int position = this->HashFunction(aluno);
    if(structure[position].getId() == aluno.getId()) {
        structure[position] = Aluno(-1, " "); // quando o id == -1 a posição é vazia (na verdade disponível, mas não estamos considerando colisões)
        // não uso new, pois o operador new aloca memória dinamicamente e retorna um ponteiro p/ o objeto do tipo Aluno
        // enquanto o array structure espera receber um objeto do tipo aluno diretamente
        itemsQuantity--;
    } else{
        cout << "\nAluno a ser removido nao encontrado\n";
    }
}

void Hash::search(Aluno& aluno, bool& found)
{
    int position = this->HashFunction(aluno);
    Aluno storedAluno = structure[position];

    if(storedAluno.getId() == aluno.getId()) {
        aluno = storedAluno;
        found = true;
    } else {
        found = false;
    }
}

void Hash::print()
{
    cout << "\nHash Table: [";
    for(int i =0; i< MAX_POSITIONS; ++i) {
        if(structure[i].getId() != -1) {
            cout << "\n" << i << ": " << structure[i].getId() << " " << structure[i].getName();
        }
    }
    cout << "\n]\n";
}
