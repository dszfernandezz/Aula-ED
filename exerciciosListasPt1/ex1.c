// Implemente uma função que tenha como valor de retorno o comprimento de uma lista
// encadeada, isto é calcule o número de nós de uma lista.
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

int comprimento(Lista *l){
    int cont = 0;
    while (l != NULL){
        cont++;
        l = l->prox;
    }
    return cont;
}

int main(){
    Lista *l = lst_cria();

    l = lst_insere(l, 25);
    l = lst_insere(l, 2);
    l = lst_insere(l, 5);

    int t = comprimento(l);

    printf("%d", t);

    return 0;
}
