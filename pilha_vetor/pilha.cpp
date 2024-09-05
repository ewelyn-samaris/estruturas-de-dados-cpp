#include <iostream>
#include "pilha.h"

using namespace std;

    Pilha::Pilha() 
    {
        tamanho = 0;
        estrutura = new TipoItem[MAX_ITENS];
    }

    Pilha::~Pilha()
    {
        delete [] estrutura;
    }

    bool Pilha::estacheia()
    {
        return tamanho == MAX_ITENS;
    }

    bool Pilha::estavazia()
    {
        return tamanho == 0;
    }

    void Pilha::inserir(TipoItem item)
    {
        if(estacheia()) {
            cout << "A pilha esta cheia. Nao eh possivel inserir o elemento\n";
        } else{
            estrutura[tamanho] = item;
            ++tamanho;
        }
    }

    TipoItem Pilha::remover()
    {
        if(estavazia()){
            cout << "A pilha esta vazia. Nao existe elementos a serem removidos\n";
            return -1;
        } else {
            tamanho--;
            return estrutura[tamanho];
        }
    }

    void Pilha::imprimir()
    {
        cout << "Pilha: [ ";
        for(int i = 0; i < tamanho; i++) {
            cout << estrutura[i] << " ";
        }
        cout << "]\n";
    }

    int Pilha::qualtamanho()
    {
        return tamanho;
    }
