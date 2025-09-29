#include <stdio.h>
#include <stdlib.h>
#include "pilhasLst.h"

PilhaLst *cria_pilhaLst(){
    PilhaLst *p = (PilhaLst*)malloc(sizeof(PilhaLst));
    p->prim = NULL;
    return p;
}

void push_lst(PilhaLst *p, float v){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->info = v;
    l->prox = p->prim;
    p->prim = l;
}

int pilhaLst_vazia(PilhaLst *p){
    return (p->prim==NULL);
}

void imprime_lst(PilhaLst *p){
    Lista *l = p->prim;
    if (l == NULL){
        printf("pilha lst vazia\n");
    }
    
    while (l != NULL){
        printf("Info: %.2f\n", l->info);
        l = l->prox;
    }
}

float pop_lst(PilhaLst *p){
    Lista* t;
    float v;
    if (pilhaLst_vazia(p)) { 
        printf("Pilha vazia.\n");
        exit(1); 
    }

    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);

    return v;
}

void libera_pilhaLst(PilhaLst *p){
    Lista *l = p->prim;
    while (l != NULL){
        Lista *temp = l->prox;
        free(l);
        l = temp;
    }
    free(p);
}

