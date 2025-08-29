//Implemente uma função que receba duas listas encadeadas de valores inteiros e
//retorne a lista resultante da concatenação das duas listas recebidas como parâmetros,
//isto é, após a concatenação, o último elemento da primeira lista deve apontar para o
//primeiro elemento da segunda lista.
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

Lista* concatena (Lista* l1, Lista* l2){
    Lista *p = l1;
    while (p->prox != NULL){
        p = l1->prox;
    }
    p->prox = l2;
    
    return l1;
}

int main(){
    Lista *l1 = lst_cria();
    Lista *l2 = lst_cria();

    l1 = lst_insere(l1, 25);
    l1 = lst_insere(l1, 2);
    l2 = lst_insere(l2, 5);
    l2 = lst_insere(l2, 9);

    Lista *u = concatena(l1, l2);

    lst_imprime(l1);

    return 0;
}

