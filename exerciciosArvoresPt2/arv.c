#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

Arv *abb_cria(void){
    return NULL;
}

void abb_imprime(Arv *a){
    if (a != NULL){
        abb_imprime(a->dir);
        printf("%d\n", a->info);
        abb_imprime(a->esq);
    }
}

Arv *abb_insere(Arv *a, int v){
    if (a == NULL){
        a = (Arv *)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info) a->esq = abb_insere(a->esq, v);
    else a->dir = abb_insere(a->dir, v);

    return a;
}

Arv *abb_busca(Arv *r, int v){
    if (r == NULL) return NULL;
    else if (r->info > v) return abb_busca(r->esq, v);
    else if (r->info < v) return abb_busca(r->dir, v);
    else return r;
}


Arv *abb_retira(Arv *r, int v){
    if (r == NULL) return NULL;
    else if (r->info > v)
        r->esq = abb_retira(r->esq, v);
    else if (r->info < v)
        r->dir = abb_retira(r->dir, v);
    else { /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL){
            free(r);
            r = NULL;
        }
        /* nó só tem filho à direita */
        else if (r->esq == NULL){
            Arv *t = r;
            r = r->dir;
            free(t);
        }
        /* só tem filho à esquerda */
        else if (r->dir == NULL){
            Arv *t = r;
            r = r->esq;
            free(t);
        }
        /* nó tem os dois filhos */
        else{
            Arv *f = r->esq;
            while (f->dir != NULL){
                f = f->dir;
            }
            /* troca as informações */
            r->info = f->info; 
            f->info = v;
            r->esq = abb_retira(r->esq, v);
        }
    }
    return r;
}

/* Arvore binaria */
ArvBin *abbBin_cria(void){
    return NULL;
}

void abbBin_imprime(ArvBin *a){
    if (a != NULL){
        abbBin_imprime(a->esq);
        printf("%d\n", a->info);
        abbBin_imprime(a->dir);
    }
}

ArvBin *abbBin_insere(ArvBin *a, int v){
    if (a == NULL){
        a = (ArvBin *)malloc(sizeof(ArvBin));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info) a->esq = abb_insere(a->esq, v);
    else a->dir = abb_insere(a->dir, v);

    return a;
}

ArvBin *abbBin_busca(ArvBin *r, int v){
    if (r == NULL) return NULL;
    else if (r->info > v) return abbBin_busca(r->esq, v);
    else if (r->info < v) return abbBin_busca(r->dir, v);
    else return r;
}


ArvBin *abbBin_retira(ArvBin *r, int v){
    if (r == NULL) return NULL;
    else if (r->info > v)
        r->esq = abbBin_retira(r->esq, v);
    else if (r->info < v)
        r->dir = abbBin_retira(r->dir, v);
    else { /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL){
            free(r);
            r = NULL;
        }
        /* nó só tem filho à direita */
        else if (r->esq == NULL){
            ArvBin *t = r;
            r = r->dir;
            free(t);
        }
        /* só tem filho à esquerda */
        else if (r->dir == NULL){
            ArvBin *t = r;
            r = r->esq;
            free(t);
        }
        /* nó tem os dois filhos */
        else{
            ArvBin *f = r->esq;
            while (f->dir != NULL){
                f = f->dir;
            }
            /* troca as informações */
            r->info = f->info; 
            f->info = v;
            r->esq = abbBin_retira(r->esq, v);
        }
    }
    return r;
}