struct lista{
    float info;
    struct lista *prox;
};
typedef struct lista Lista;

struct pilhaLst{
    Lista *prim;
};
typedef struct pilhaLst PilhaLst;

PilhaLst *cria_pilhaLst();

void push_lst(PilhaLst *p, float v);

float pop_lst(PilhaLst *p);

int pilhaLst_vazia(PilhaLst *p);

void libera_pilhaLst(PilhaLst *p);

void imprime_lst(PilhaLst *p);