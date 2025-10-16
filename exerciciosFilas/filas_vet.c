#include <stdio.h>
#include <stdlib.h>
#include "filas_vet.h"

FilaV *cria_pilhav(){
    FilaV *f = (FilaV*)malloc(sizeof(FilaV));
    f->ini = 0;
    f->n = 0;
    return f;
}

void insere_filaV(FilaV *f, float v){
    if (f->n == N) {
        printf("Capacidade da fila estourou.\n");
        exit(1); 
    }
    int fim = (f->ini + f->n) % N;
    f->v[fim] = v;
    f->n++; 
}

int filaV_vazia(FilaV *f){
    return (f->n == 0);
}


//retira elemento do inicio da fila
float retira_filaV(FilaV *f){
    if (filaV_vazia(f)){
        printf("\nFila vazia.\n");
        exit(1);
    }    
    f->ini = (f->ini +1) % N;
    float v = f->v[f->ini];
    f->n--; 
    return v;
}

void libera_filaV(FilaV *f){
    free(f);
}

void imprime_filaV(FilaV *f){
    if (f->n == 0){
        printf("Fila vazia");
    }
    
    for (int i = 0; i < f->n; i++){
        printf("info %d: %.2f\n", i, f->v[i]);
    }
}