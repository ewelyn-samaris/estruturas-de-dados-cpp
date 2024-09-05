typedef int TipoItem;
const int MAX_ITENS = 100;

class Fila {
    private:
    int primeiro, ultimo;
    TipoItem* estrutura;

    public:
    Fila(); 
    ~Fila(); 
    bool estavazio();
    bool estacheio();
    void inserir(TipoItem item);
    TipoItem remover();
    void imprimir();
};