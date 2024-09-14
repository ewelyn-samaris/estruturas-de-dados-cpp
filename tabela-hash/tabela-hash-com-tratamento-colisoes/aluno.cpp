#include "aluno.h"

Aluno::Aluno()
{
    // valores de inicialização das posições da hash para que diferenciemos as posições vazias
    id = -1;
    name = " ";
}

Aluno::Aluno(int id, string name)
{
    // em C++ `this`é um ponteiro para o objeto, então é preciso utilizar `->`
    this->id = id;
    this->name = name;
}

int Aluno::getId()
{
    return this->id;
}

string Aluno::getName()
{
    return this->name;
}
