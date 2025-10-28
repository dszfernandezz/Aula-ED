#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arv.h"

bool aux_ehABB(ArvBin *a, ArvBin *min, ArvBin *max){
    if (a == NULL) return true;

    if ((min != NULL && a->info <= min->info) || (max != NULL && a->info >= max->info)){
        return false;
    }
    
    return aux_ehABB(a->esq, min, a) && aux_ehABB(a->dir, a, max);
}

bool ehABB(ArvBin* a){
    return aux_ehABB(a, NULL, NULL);
}

int main(){
    ArvBin *a = abb_cria();
    
    a = abb_insere (a, 101010);
    a = abb_insere (a, 101101);
    a = abb_insere (a, 1011011);
    a = abb_insere (a, 1001001);
    bool resultado = ehABB(a);
    abb_imprime(a);
    printf("\n");

    (resultado == true) ? printf("A arvore é binaria") : printf("A arvore não é binaria");
    printf("\n");

    return 0;
}