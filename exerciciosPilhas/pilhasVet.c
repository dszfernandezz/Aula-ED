#include <stdio.h>
#include <stdlib.h>
#include "pilhasVet.h"

PilhaV *cria_PilhaV(){
    PilhaV *p = (PilhaV*)malloc(sizeof(PilhaV));   
    p->n = 0;
    return p;
}

void push(PilhaV *p, float v){
    if (p->n == N){
        printf("Capacidade maxima atingida\n");
        exit(1);
    }

    p->v[p->n] = v;
    p->n++;
}

int PilhaV_vazia(PilhaV *p){
    return (p->n == 0);
}

void imprime_vet(PilhaV *p){
    if (p->n == 0){
        printf("pilha vet vazia\n");
    }
    
    for (int i = p->n -1; i >= 0; i--){
        printf("Info %d: %.2f\n", i, p->v[i]);
    }
}

float pop(PilhaV *p){
    float v;
    if (PilhaV_vazia(p)){
        printf("A PilhaV está vazia\n");
        exit(1);
    }
    
    v = p->v[p->n-1];
    p->n--;
    return v;
}

void liberar_PilhaV(PilhaV *p){
    free(p);
}