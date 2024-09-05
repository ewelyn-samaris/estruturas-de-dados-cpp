#include <iostream>
#include "fila.h"

using namespace std;

Fila::Fila()
{
    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem(MAX_ITENS);
}

Fila::~Fila()
{
    delete [] estrutura;
}

bool Fila::estavazio()
{
    return primeiro == ultimo;
}

bool Fila::estacheio()
{
    return (ultimo - primeiro) == MAX_ITENS;
}

void Fila::inserir(TipoItem item)
{
    if(estacheio()) {
        cout << "Fila esta cheia. Não eh possivel inserir elementos\n";
    } else{
        estrutura[ultimo % MAX_ITENS] = item;
        ultimo++;
        cout << "Elemento " << item << " inserido na fila com sucesso\n";
    }
}

TipoItem Fila::remover()
{
    if(estavazio()) {
        cout << "Fila esta vazia. Nao ha elementos a serem removidos\n";
        return -1;
    } else{
        primeiro++;
        return estrutura[(primeiro-1) % MAX_ITENS];
    }
}

void Fila::imprimir()
{
    cout << "Fila: [ ";
    for(int i = primeiro; i < ultimo; ++i ){
        cout << estrutura[i % MAX_ITENS] << " ";
    }
    cout << "]\n";
}
