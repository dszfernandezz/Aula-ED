#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

ArvInt *criar_arvore_int(){
    ArvInt *a7 = arvInt_cria(10, arvInt_criavazia(), arvInt_criavazia());
    ArvInt *a6 = arvInt_cria(9, a7, arvInt_criavazia());
    ArvInt *a5 = arvInt_cria(8, a6, arvInt_criavazia());
    ArvInt *a10 = arvInt_cria(7, arvInt_criavazia(), arvInt_criavazia());
    ArvInt *a9 = arvInt_cria(6, a10, arvInt_criavazia());
    ArvInt *a8 = arvInt_cria(5, arvInt_criavazia(), a9);
    ArvInt *a4 = arvInt_cria(4, a5, a8);
    ArvInt *a3 = arvInt_cria(3, a4, arvInt_criavazia());
    ArvInt *a2 = arvInt_cria(2, arvInt_criavazia(), a3);
    ArvInt *a1 = arvInt_cria(1, arvInt_criavazia(), a2);

    return a1;
}

int pares(ArvInt *a){
    int cont = 0;
    if (!arvInt_vazia(a)){
        if(a->info % 2 == 0){
            cont++;
        }
        cont += pares(a->dir);
        cont += pares(a->esq);
    }
    return cont;
}


int main(){
    ArvInt *a = criar_arvore_int();

    arvInt_imprime(a);
    printf("\n");
    int q = pares(a);
    printf("%d\n", q);

    a = arvInt_libera(a);
    
    return 0;
}