struct lista {
    float info;
    struct lista* prox;
};
typedef struct lista Lista;

struct filalst{
    Lista* ini;
    Lista* fim;
};
typedef struct filalst FilaLst;

FilaLst *cria_filaLst();

void insere_filaLst(FilaLst *f, float v);

float retira_filaLst(FilaLst *f);

int filaLst_vazia(FilaLst *f);

void libera_filaLst(FilaLst *f);

void imprime_filaLst(FilaLst *f);
