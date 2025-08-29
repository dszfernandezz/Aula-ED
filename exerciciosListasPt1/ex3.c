//Implemente uma função que tenha como valor de retorno o ponteiro para o último nó
//de uma lista encadeada.
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

Lista* ultimo (Lista* l){
    while (l != NULL){
        l = l->prox;
    }

    return l;
}

int main(){
    Lista *l = lst_cria();

    l = lst_insere(l, 25);
    l = lst_insere(l, 2);
    l = lst_insere(l, 5);
    l = lst_insere(l, 9);

    Lista *u = ultimo(l);

    printf("%d\n", l->info);
}