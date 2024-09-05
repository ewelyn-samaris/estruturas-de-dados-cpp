#include <iostream>
#include "pilha.h"

using namespace std;

int PARAR_PROGRAMA = 0;
    int INSERIR = 1;
    int REMOVER = 2;
    int IMPRIMIR = 3;

void menu() {
    cout << "Digite [" << PARAR_PROGRAMA << "] para parar o programa\n";
    cout << "Digite [" << INSERIR << "] para inserir um elemento\n";
    cout << "Digite [" << REMOVER << "] para remover um elemento\n";
    cout << "Digite [" << IMPRIMIR << "] para imprimir a pilha\n";
}

int main() {
    Pilha pilha1;
    TipoItem item;
    int opcao;

    cout << "Programa gerador de pilha:\n";

    do {
       menu();
        cin >> opcao;

        if(opcao == INSERIR) {
            cout << "Digite o elemento a ser inserido: ";
            cin >> item;
            pilha1.inserir(item);
        } else if(opcao == REMOVER) {
            item = pilha1.remover();
            if(item != -1) { 
                cout << "Elemento " << item << " removido com sucesso" << endl;
            }
        } else if(opcao == IMPRIMIR) {
            pilha1.imprimir();
        }

    } while (opcao != PARAR_PROGRAMA);
    cout << "Programa pilha finalizado";

    return 0;
}
