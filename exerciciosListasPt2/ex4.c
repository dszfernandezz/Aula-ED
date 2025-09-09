// Implemente uma função que remova o elemento anterior a um elemento de valor v.
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Lista* lst_retira(Lista *l, int v){
    Lista *p = l;
    Lista *anterior = NULL; 

    while (p!=NULL && p->info != v){
        anterior = p;
        p = p->prox;
    }

    if (anterior == NULL){
        l = p->prox;
    } else {
        anterior->prox = p->prox;
    }
    
    free(p);
    return l;
}

Lista *lst_retira_ant(Lista *l, int v){
    // retorna caso a lista esteja:
    // vazia ou com apenas um elemento
    if (l == NULL || l->prox == NULL || l->info == v) return l;

    Lista *p = l;
    Lista *anterior = NULL;   

    while (p != NULL && p->info!=v){
        anterior = p;
        p = p->prox;
    }
    if (p!=NULL){
        l = lst_retira(l, anterior->info);
    }
    
    return l;
}

int main(){
    Lista *l = lst_cria();

    l = lst_insere(l, 10);
    l = lst_insere(l, 9);
    l = lst_insere(l, 5);
    l = lst_insere(l, 8);

    lst_imprime(l);
    printf("\n");
    l = lst_retira_ant(l, 8);
    lst_imprime(l);
    printf("\n");

    return 0;
}