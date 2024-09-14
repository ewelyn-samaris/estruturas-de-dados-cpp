#include <iostream>

using namespace std;

class Aluno {
    private:
    int id;
    string name;

    public:
    Aluno(); // esse construtor será utilizado para criar a hash, inicializando os atributos de Aluno para que saibamos quando é vazio (nunca houve inserção)
    Aluno(int id, string name); // sobrecarga do método construtor
    int getId();
    string getName();
};