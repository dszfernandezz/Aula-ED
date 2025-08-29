#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

/* função de criação: retorna uma lista vazia */
Lista* lst_cria (void){
    return NULL;
}

Lista* ultimo(Lista *l){
    Lista* p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }

    return p;
}

/* inserção no fim*/
Lista* lst_insere(Lista* l, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = NULL;
    Lista *ult = ultimo(l);

    if (ult == NULL) return novo;
    else ult->prox = novo; 

    return l;
}

void lst_imprime(Lista* l){
    Lista* p;
    for (p = l; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
}
