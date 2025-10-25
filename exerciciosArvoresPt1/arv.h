struct arv{
    char info;
    struct arv *esq;
    struct arv *dir;
};
typedef struct arv Arv;

struct arvint{
    int info;
    struct arvint *esq;
    struct arvint *dir;
};
typedef struct arv ArvInt;

Arv* arv_criavazia (void);
Arv* arv_cria (char c, Arv* e, Arv* d);
Arv* arv_libera (Arv* a);
int arv_vazia (Arv* a);
int arv_pertence (Arv* a, char c);
void arv_imprime (Arv* a);

ArvInt* arvInt_criavazia(void);
ArvInt* arvInt_cria (int i, ArvInt* e, ArvInt* d);
ArvInt* arvInt_libera(ArvInt* a);
int arvInt_vazia(ArvInt* a);
int arvInt_pertence (ArvInt* a, int i);
void arvInt_imprime (ArvInt* a);