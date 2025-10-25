#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

Arv* arv_criavazia (void){
    return NULL;    
}

Arv* arv_cria(char c, Arv* e, Arv* d){
    Arv *a = (Arv*)malloc(sizeof(Arv));
    a->info = c;
    a->esq = e;
    a->dir = d;
    return a;
}

int arv_vazia(Arv* a){
    return a == NULL;
}

Arv* arv_libera(Arv* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);   
    } 
    return NULL;
}

int arv_pertence(Arv* a, char c){
    if (arv_vazia(a)) return 0; 
    else return a->info == c || arv_pertence(a->esq,c) || arv_pertence(a->dir,c);
}

void arv_imprime (Arv* a){
    if (!arv_vazia(a)){
        printf("%c ", a->info);
        arv_imprime(a->esq); 
        arv_imprime(a->dir);    
    }
}



/* Arvore de inteiros */

ArvInt* arvInt_criavazia(){
    return NULL;
}

ArvInt* arvInt_cria (int i, ArvInt* e, ArvInt* d){
    ArvInt *a = (ArvInt*)malloc(sizeof(ArvInt));
    a->info = i;
    a->esq = e;
    a->dir = d;
    return a;
}

ArvInt* arvInt_libera(ArvInt* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);   
    } 
    return NULL;
}

int arvInt_vazia(ArvInt* a){
    return a == NULL;
}

int arvInt_pertence(ArvInt* a, int i){
    if (arvInt_vazia(a)) return 0; 
    else return a->info == i || arv_pertence(a->esq, i) || arv_pertence(a->dir, i);
}

void arvInt_imprime(ArvInt* a){
    if (!arvInt_vazia(a)){
        printf("%d ", a->info); 
        arvInt_imprime(a->dir);
        arvInt_imprime(a->esq);  
    }
}