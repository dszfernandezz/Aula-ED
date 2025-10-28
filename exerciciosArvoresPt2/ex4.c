#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

ArvBin* inverter(ArvBin* a){
    if (a == NULL) return NULL;
    inverter(a->esq);
    inverter(a->dir);
    ArvBin *temp = a->dir;
    a->dir = a->esq;
    a->esq = temp;

    return a;
}


int main(){
    Arv *a = abb_cria();
    
    a = abb_insere (a, 5);
    a = abb_insere (a, 1);
    a = abb_insere (a, 3);
    a = abb_insere (a, 4);
    a = abb_insere (a, 7);
    a = abb_insere (a, 2);
    a = abb_insere (a, 8);
    abb_imprime(a);
    printf("\n");
    a = inverter(a);
    abb_imprime(a);
    printf("\n");


    return 0;
}