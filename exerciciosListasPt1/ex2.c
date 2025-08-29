//Considere listas encadeadas de valores inteiros e implemente uma função para
//retornar o número de nós da lista que possuem o campo info com valores maiores do
//que n.
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

int maiores(Lista* l, int n){
    int qtd = 0;
    while (l != NULL){
        if (l->info > n) qtd++;
        l = l->prox; 
    }
    return qtd;
}

int main(){
    Lista *l = lst_cria();

    l = lst_insere(l, 25);
    l = lst_insere(l, 2);
    l = lst_insere(l, 5);

    int m = maiores(l, 6);

    printf("%d\n", m);
}