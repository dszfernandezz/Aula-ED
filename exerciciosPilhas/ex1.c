#include <stdio.h>
#include <stdlib.h>
#include "pilhasVet.h"
#include "pilhasLst.h"

void imprime_pilhaV(PilhaV *pv){
    for (int i = pv->n-1; i >= 0; i--){
        printf("Info: %.2f\n", pv->v[i]);
    }
}

void imprime_pilhaLst(PilhaLst *p){   
    Lista *l = p->prim;

    while (l != NULL){
        printf("info lst: %.2f\n", l->info);
        l = l->prox;
    } 
}


int main(){
    PilhaV *pv = cria_PilhaV();
    PilhaLst *pl = cria_pilhaLst();
    
    push(pv, 5);
    push(pv, 4);
    push(pv, 3);
    push(pv, 7);
    push(pv, 9);

    push_lst(pl, 5);
    push_lst(pl, 4);
    push_lst(pl, 3);
    push_lst(pl, 7);
    push_lst(pl, 9);

    imprime_pilhaV(pv);
    printf("\n");
    imprime_pilhaLst(pl);

    return 0;
}





