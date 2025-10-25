#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

Arv *criar_arvore_b(){
    Arv *a7 = arv_cria('i', arv_criavazia(), arv_criavazia());
    Arv *a6 = arv_cria('g', a7, arv_criavazia());
    Arv *a5 = arv_cria('p', a6, arv_criavazia());

    Arv *a10 = arv_cria('j', arv_criavazia(), arv_criavazia());
    Arv *a9 = arv_cria('h', a10, arv_criavazia());
    Arv *a8 = arv_cria('f', arv_criavazia(), a9);

    Arv *a4 = arv_cria('d', a5, a8);
    Arv *a3 = arv_cria('c', a4, arv_criavazia());
    Arv *a2 = arv_cria('b', arv_criavazia(), a3);
    Arv *a1 = arv_cria('a', arv_criavazia(), a2);

    return a1;
}

bool igual(Arv* a, Arv* b){
    if (arv_vazia(a) && arv_vazia(b)) return true;
    if (arv_vazia(a) || arv_vazia(b)) return false;

    return (a->info == b->info) && (igual(a->esq, b->esq)) && (igual(a->dir, b->dir));
}


int main(){
    Arv *a = criar_arvore();
    Arv *b = criar_arvore();

    arv_imprime(a);
    printf("\n");
    arv_imprime(b);
    printf("\n");
    bool d = igual(a, b);

    (d == true) ? printf("As arvores a e b sao iguais!\n") : printf("As arvores a e b nao sao iguais!\n");

    a = arv_libera(a);
    b = arv_libera(b);
    
    return 0;
}