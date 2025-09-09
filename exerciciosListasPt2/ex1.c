//Implemente uma função que altere uma lista, de forma que os valores positivos fiquem negativos e os
//negativos fiquem positivos. Esta função deve ter o protótipo:
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

void lst_altera(Lista* l){
    Lista *p = l;
    while (p!=NULL){
        p->info *= -1;
        p = p->prox;
    }        
}

int main(){
    Lista *l = lst_cria();

    l = lst_insere(l, 2);
    l = lst_insere(l, 9);
    l = lst_insere(l, 45);
    l = lst_insere(l, -2);

    lst_imprime(l);
    
    printf("\n");
    lst_altera(l);
    lst_imprime(l);
    printf("\n");

    return 0;
}