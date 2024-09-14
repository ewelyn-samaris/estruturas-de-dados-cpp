#include <iostream>
#include "hash.h"

int STOP_PROGRAM = 0;
int PUSH = 1;
int POP = 2;
int SEARCH = 3;
int PRINT = 4;

void menu() {
    std::cout << "Digite [" << STOP_PROGRAM << "] para parar o programa\n";
    std::cout << "Digite [" << PUSH << "] para inserir um elemento\n";
    std::cout << "Digite [" << POP << "] para remover um elemento\n";
    std::cout << "Digite [" << SEARCH << "] para buscar um elemento\n";
    std::cout << "Digite [" << PRINT << "] para imprimir a Hahs Table\n";
    std::cout << "Opcao escolhida: ";
}

int main() {
    cout << "Programa gerador de Hash Table!\n";
    int maxItems, arraySize;
    std::cout << "Digite o tamanho da Hash Table: ";
    std::cin >> arraySize;
    std::cout << "Digite o numero maximo de elementos: ";
    std::cin >> maxItems;

    cout << "O fator de carga e: " << (float)maxItems / (float)arraySize << endl;
    Hash myHash(arraySize, maxItems); // inicialização direta. O objeto myHash é criado e inicializado usando o construtor da classe Hash diretamente
    // Hash myHash = Hash(arraySize, maxItems); é uma inicialização por cópia. 
    // Na inicialização por cópia, o lado direto da expressão cria um objeto temporário que é copiado para o objeto myHash

    int option;
    int id;
    string name;
    bool found;

    do {
        menu();
        std::cin >> option;

        if(option == PUSH) {
            std::cout << "\nDigite o id do aluno: ";
            std::cin >> id;
            std::cout << "Digite o nome do aluno: ";
            std::cin >> name;

            Aluno aluno = Aluno(id, name);
            myHash.push(aluno);
        } else if(option == POP) {
            std::cout << "\nDigite o id do aluno a ser removido: ";
            std::cin >> id;

            Aluno aluno = Aluno(id, " ");
            myHash.pop(aluno);
        } else if (option == SEARCH) {
            std::cout << "\nDigite o id do aluno aser buscado: ";
            std::cin >> id;
            
            Aluno aluno = Aluno(id, "");
            myHash.search(aluno, found);
            
            if(found) {
                std::cout << "\nAluno encontrado: " << aluno.getId() << " " << aluno.getName() << endl;
            } else {
                std::cout << "Aluno nao encontrado!\n";
            }
        } else if(option == PRINT) {
            myHash.print();
        } else {
            std::cout << "\nOpcao invalida!";
        }
    } while(option != STOP_PROGRAM);
    
    return 0;
}
