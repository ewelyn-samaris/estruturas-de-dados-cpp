#include "aluno.h"

class Hash {
    private:
    int HashFunction(Aluno aluno); 
    // a função hash é do tipo inteiro, pois o valor retornado pela função hash é um inteiro 
    // (q será o índice da posição que será ocupada pela chave recebida,
    // que no caso é um objeto da classe Aluno)
    int MAX_ITEMS; // Quantidade máxima de posições a serem ocupadas no vetor
    int MAX_POSITIONS; // Quantidade total de posições do vetor
    // A relação MAX_ITEMS / MAX_POSITIONS define o Fator de carga
    int itemsQuantity; // Quantidade de itens (chaves) que já foram inseridas em meu vetor
    Aluno* structure; // Será o vetor de alunos. O vetor onde iremos implementar nossa hash table

    public:
    Hash(int arraySize, int maxItems);
    ~Hash();
    bool isFull();
    int getItemsQuantity();
    void push(Aluno aluno);
    void pop(Aluno aluno);
    void search(Aluno& aluno, bool& found); 
    // recebe por referência um objeto do tipo Aluno e um boleano chamado "found" que entra como falso e é modificado para true se encontrar o obj aluno
    // se o aluno for encontrado na hash table, o aluno de entrada por referência será modificado, a ele será atribuído o resultado encontrado
    void print();
};