#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

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

    a = abb_retira (a, 8);
    a = abb_retira (a, 1);
    a = abb_retira (a, 5);
    a = abb_retira (a, 4);
    abb_imprime(a);
    printf("\n");

    return 0;
}