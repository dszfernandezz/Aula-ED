#include <stdio.h>
#include <stdlib.h>
#include "pilhasVet.h"
#include "pilhasLst.h"

int num_obj_lst(PilhaLst *p){
    int cont = 0;
    Lista *l = p->prim;

    while (l != NULL){
        cont++;
        l = l->prox;
    }
    return cont;
}

int num_obj_vet(PilhaV *p){
    int cont = 0;
    for (int i = 0; i < p->n; i++){
        cont++;
    }
    return cont;
}

float topo_pilhaVet(PilhaV *p){
    if (PilhaV_vazia(p)){
        printf("pilha vazia!!!!\n");
        exit(1);
    }
    return p->v[p->n-1];
}

float topo_pilhaLst(PilhaLst *p){
    Lista *l = p->prim;
    if (pilhaLst_vazia(p)){
        printf("pilha vazia!!!!\n");
        exit(1);
    }

    return l->info;
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

    int qtdLst = num_obj_lst(pl);
    int qtdVet = num_obj_vet(pv);

    printf("Quantidade de objetos na pilha Lst: %d\n", qtdLst);
    printf("Quantidade de objetos na pilha Vet: %d\n", qtdVet);

    float topoV = topo_pilhaVet(pv);
    float topoLst = topo_pilhaLst(pl);

    printf("Topo da pilha lst: %.2f\n", topoLst);
    printf("Topo da pilha vet: %.2f\n", topoV);

    return 0;
}

