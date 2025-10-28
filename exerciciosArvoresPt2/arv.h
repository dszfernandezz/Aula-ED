struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

struct arvbin {
    int info;
    struct arvbin* esq;
    struct arvbin* dir;
};
typedef struct arv ArvBin;


Arv* abb_cria (void);
Arv* abb_insere (Arv* a, int v);
void abb_imprime (Arv* a);
Arv* abb_busca (Arv* r, int v);
Arv* abb_retira (Arv* r, int v);

ArvBin* abbBin_cria (void);
ArvBin* abbBin_insere (ArvBin* a, int v);
void abbBin_imprime (ArvBin* a);
ArvBin* abbBin_busca (ArvBin* r, int v);
ArvBin* abbBin_retira (ArvBin* r, int v);