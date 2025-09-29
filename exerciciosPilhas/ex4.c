#include <stdio.h>
#include <stdlib.h>
#include "pilhasVet.h"
#include "pilhasLst.h"

void esvazia_vet(PilhaV *p){
    if (p == NULL){
        printf("Pilha vazia!");
        exit(1);
    }
    p->n = 0;
}

void esvazia_lst(PilhaLst *p){
    Lista *l = p->prim;
    if (l == NULL){
        printf("Pilha vazia!");
        exit(1);
    }
    Lista *temp;

    while (l != NULL){
        temp = l;
        l = l->prox;
        free(temp);
    }
    p->prim = NULL;
}


int main(){
    PilhaV *pv = cria_PilhaV();
    PilhaLst *pl = cria_pilhaLst();
    
    push(pv, 5);
    push(pv, 4);
    push(pv, 3);
    push(pv, 1);
    push(pv, 7);
    push(pv, 10);

    push_lst(pl, 5);
    push_lst(pl, 4);
    push_lst(pl, 3);
    push_lst(pl, 7);
    push_lst(pl, 9);

    imprime_lst(pl);
    printf("\n");
    imprime_vet(pv);

    esvazia_lst(pl);
    esvazia_vet(pv);

    printf("\n");
    imprime_lst(pl);
    imprime_vet(pv);

    return 0;
}