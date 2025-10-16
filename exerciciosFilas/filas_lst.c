#include <stdio.h>
#include <stdlib.h>
#include "filas_lst.h"

FilaLst *cria_filaLst(){
    FilaLst *f = (FilaLst*)malloc(sizeof(FilaLst));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void insere_filaLst(FilaLst *f, float v){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->info = v;

    if (f->fim != NULL){
        f->fim->prox = l;
    } else {
        f->ini = l;
    }
    f->fim = l;
}

int filaLst_vazia(FilaLst *f){
    return (f->ini==NULL);
}

//retira elemento do inicio da fila
float retira_filaLst(FilaLst *f){
    if (filaLst_vazia(f)) { printf("Fila vazia.\n");
        exit(1);
    }
    Lista *temp = f->ini;
    f->ini = temp->prox;
    float v = temp->info;
    if (f->ini == NULL){
        f->fim = NULL;
    } 
    free(temp);
    return v;
}

void imprime_filaLst(FilaLst *f){
    if (f->ini == NULL) {
        printf("A fila está vazia.\n");
        return;
    }
    Lista *l = f->ini;
    int i = 0;
    while (l != NULL){
        printf("info lst %d: %.2f\n", i, l->info);
        l = l->prox;
        i++;
    }
}

void libera_filaLst(FilaLst *f){
    Lista *l = f->ini;
    while (l != NULL){
        Lista *temp = l->prox; 
        free(l);
        l = temp;
    }
    free(f);
    
}