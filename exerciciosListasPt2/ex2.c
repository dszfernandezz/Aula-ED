//Implemente uma função que insira elementos sempre ao final da lista. 
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


int main(){
    Lista *l = lst_cria();

    l = lst_insere(l, 2);
    l = lst_insere(l, 9);
    l = lst_insere(l, 45);
    l = lst_insere(l, -2);

    lst_imprime(l);
    

    return 0;
}