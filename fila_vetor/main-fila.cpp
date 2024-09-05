#include <iostream>
#include "fila.h"

using namespace std;

int PARAR_PROGRAMA = 0;
int INSERIR = 1;
int REMOVER = 2;
int IMPRIMIR = 3;

void menu() {
    cout << "Digite [ " << PARAR_PROGRAMA << " ] para parar o prgrama\n";
    cout << "Digite [ " << INSERIR << " ] para inserir um novo elemento na fila\n";
    cout << "Digite [ " << REMOVER << " ] para remover um elemento da fila\n";
    cout << "Digite [ " << IMPRIMIR << " ] para imprimir a fila\n";
}

int main (){
Fila fila1;
int opcao;
TipoItem item;
cout << "\nPrograma gerador de fila:\n";


do {
    menu();
    cin >> opcao;

    if(opcao == INSERIR) {
        cout << "Digite o elmento a ser inserido na fila: ";
        cin >> item;
        fila1.inserir(item);
    } else if(opcao == REMOVER){
        item = fila1.remover();
        cout << "o elemento " << item << " foi removido\n";
    } else if(opcao == IMPRIMIR) {
        fila1.imprimir();
    }

} while(opcao != PARAR_PROGRAMA);
cout << "Programa finalizado\n";

return 0;
}