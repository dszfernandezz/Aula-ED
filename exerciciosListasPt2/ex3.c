//Implemente uma função que calcule a média aritmética dos valores armazenados.
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

float lst_calculaMedia(Lista* l){
    Lista *p = l;
    float media = 0;
    while (p!=NULL){
        media += p->info;
        p = p->prox;
    }
    return media/sizeof(p->info);
}

int main(){
    Lista *l = lst_cria();

    l = lst_insere(l, 10);
    l = lst_insere(l, 9);
    l = lst_insere(l, 5);
    l = lst_insere(l, 8);

    float r = lst_calculaMedia(l);

    printf("%.2f", r);

    return 0;

}