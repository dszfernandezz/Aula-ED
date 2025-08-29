#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

/* função de criação: retorna uma lista vazia */
Lista* lst_cria (void){
    return NULL;
}

/* inserção no início: retorna a lista atualizada */
Lista* lst_insere(Lista* l, int i){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void lst_imprime(Lista* l){
    Lista* p;
    for (p = l; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
}
