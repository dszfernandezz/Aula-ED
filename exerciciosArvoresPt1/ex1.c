#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

Arv *criar_arvore(){
    Arv *a7 = arv_cria('i', arv_criavazia(), arv_criavazia());
    Arv *a6 = arv_cria('g', a7, arv_criavazia());
    Arv *a5 = arv_cria('e', a6, arv_criavazia());

    Arv *a10 = arv_cria('j', arv_criavazia(), arv_criavazia());
    Arv *a9 = arv_cria('h', a10, arv_criavazia());
    Arv *a8 = arv_cria('f', arv_criavazia(), a9);

    Arv *a4 = arv_cria('d', a5, a8);
    Arv *a3 = arv_cria('c', a4, arv_criavazia());
    Arv *a2 = arv_cria('b', arv_criavazia(), a3);
    Arv *a1 = arv_cria('a', arv_criavazia(), a2);

    return a1;
}

void arv_simetrica(Arv* a){
    if (!arv_vazia(a)){
        arv_simetrica(a->esq);
        printf("%c ", a->info);         
        arv_simetrica(a->dir);
    }   
}

void arv_pos_ordem(Arv* a){
    if (!arv_vazia(a)){
        arv_pos_ordem(a->esq);
        arv_pos_ordem(a->dir);
        printf("%c ", a->info);         
    }   
}

int main(){
    Arv *a = criar_arvore();

    arv_imprime(a);
    printf("\n");
    arv_simetrica(a);
    printf("\n");
    arv_pos_ordem(a);
    printf("\n");

    a = arv_libera(a);
    
    return 0;
}