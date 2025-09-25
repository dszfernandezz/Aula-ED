#include <stdio.h>
#include <stdlib.h>

struct lista2{
    int info;
    struct lista2* ant;
    struct lista2* prox;
};
typedef struct lista2 Lista2;

Lista2 *cria_lista(){
    return NULL;
}

Lista2* ultimo(Lista2 *l){
    Lista2* p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    return p;
}

Lista2 *insere_elemento(Lista2 *l, int info){
    Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
    novo->info = info;
    novo->prox = NULL;    

    if (l == NULL){
        novo->ant = NULL;
        return novo;
    }

    Lista2* ult = ultimo(l);

    ult->prox = novo;
    novo->ant = ult;
    
    return l;
}

Lista2* lst_busca (Lista2* l, int v){
    Lista2 *p = l;
    while (p != NULL){
        if (p->info == v) return p;
        p = p->prox;
    }
    
    return NULL;
}

Lista2 *retira(Lista2 *l, int info){
    Lista2* p = lst_busca(l, info);
	if (p == NULL) return l;
    
    if (l == p) l = p->prox;
    else p->ant->prox = p->prox;

    if(p->prox != NULL) p->prox->ant = p->ant;

    free(p);

    return l;
}

Lista2 *retira_ant(Lista2 *l, int v){
    // retorna caso a lista esteja:
    // vazia, com apenas um elemento ou 
    // se quiser remover o anterior ao primeiro elemento
    if (l == NULL || l->prox == NULL || l->info == v) return l;

    Lista2 *p = l;
    Lista2 *ant = NULL;

    while (p != NULL && p->info != v){
        ant = p;
        p = p->prox;
    }

    if (p != NULL){
        l = retira(l, ant->info);
    }
    
    return l;
}

void imprime_lista(Lista2 *l){
    for (Lista2 *p = l; p != NULL; p = p->prox){
        printf("Info: %d\n", p->info);
    }
}

int main(){
    Lista2 *l = cria_lista();

    l = insere_elemento(l, 6);
    l = insere_elemento(l, 9);
    l = insere_elemento(l, 3);
    l = insere_elemento(l, 4);

    imprime_lista(l);

    printf("\n");
    retira_ant(l, 4);
    imprime_lista(l);

    return 0;
}