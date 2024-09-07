#include <iostream>
#include "fila-dinamica.h"

using namespace std;

int STOP_PROGRAM = 0;
    int ENQUEUE = 1;
    int DEQUEUE = 2;
    int PRINT = 3;

void menu() {
    cout << "Digite [" << STOP_PROGRAM << "] para parar o programa\n";
    cout << "Digite [" << ENQUEUE << "] para inserir um elemento\n";
    cout << "Digite [" << DEQUEUE << "] para remover um elemento\n";
    cout << "Digite [" << PRINT << "] para imprimir a fila\n";
}

int main() {
    DynamicQueue myQueue;
    ItemType item;
    int option;

    cout << "Programa gerador de Fila:\n";

    do {
       menu();
        cin >> option;

        if(option == ENQUEUE) {
            cout << "Digite o elemento a ser inserido: ";
            cin >> item;
            myQueue.enqueue(item);
        } else if(option == DEQUEUE) {
            item = myQueue.dequeue();
            if(item != -1) { 
                cout << "\nElemento " << item << " removido com sucesso" << endl;
            }
        } else if(option == PRINT) {
            myQueue.print();
        }

    } while (option != STOP_PROGRAM);
    cout << "\nPrograma filha finalizado\n\n";

    return 0;
}