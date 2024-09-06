#include <iostream>
#include "pilha.h"

using namespace std;

int STOP_PROGRAM = 0;
    int ENQUEUE = 1;
    int DEQUEUE = 2;
    int PRINT = 3;

void menu() {
    cout << "Digite [" << STOP_PROGRAM << "] para parar o programa\n";
    cout << "Digite [" << ENQUEUE << "] para inserir um elemento\n";
    cout << "Digite [" << DEQUEUE << "] para remover um elemento\n";
    cout << "Digite [" << PRINT << "] para imprimir a pilha\n";
}

int main() {
    Stack myStack;
    ItemType item;
    int option;

    cout << "Programa gerador de pilha:\n";

    do {
       menu();
        cin >> option;

        if(option == ENQUEUE) {
            cout << "Digite o elemento a ser inserido: ";
            cin >> item;
            myStack.push(item);
        } else if(option == DEQUEUE) {
            item = myStack.pop();
            if(item != -1) { 
                cout << "Elemento " << item << " removido com sucesso" << endl;
            }
        } else if(option == PRINT) {
            myStack.print();
        }

    } while (option != STOP_PROGRAM);
    cout << "Programa pilha finalizado";

    return 0;
}
