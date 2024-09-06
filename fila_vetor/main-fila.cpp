#include <iostream>
#include "fila.h"

using namespace std;

int STOP_PROGRAM = 0;
int ENQUEUE = 1;
int DEQUEUE = 2;
int PRINT = 3;

void menu() {
    cout << "Digite [ " << STOP_PROGRAM << " ] para parar o prgrama\n";
    cout << "Digite [ " << ENQUEUE << " ] para inserir um novo elemento na fila\n";
    cout << "Digite [ " << DEQUEUE << " ] para remover um elemento da fila\n";
    cout << "Digite [ " << PRINT << " ] para imprimir a fila\n";
}

int main (){
Queue myQueue;
int option;
ItemType item;
cout << "\nPrograma gerador de fila:\n";


do {
    menu();
    cin >> option;

    if(option == ENQUEUE) {
        cout << "Digite o elmento a ser inserido na fila: ";
        cin >> item;
        myQueue.enqueue(item);
    } else if(option == DEQUEUE){
        item = myQueue.dequeue();
        cout << "o elemento " << item << " foi removido\n";
    } else if(option == PRINT) {
        myQueue.print();
    }

} while(option != STOP_PROGRAM);
cout << "Programa finalizado\n";

return 0;
}