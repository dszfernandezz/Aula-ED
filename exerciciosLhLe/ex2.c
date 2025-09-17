//1) Faça uma função que insira elementos nesta lista, dadas as seguintes definições de structs:
//2) Faça uma função que imprima os elementos desta lista.
#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[50];
};
typedef struct aluno Aluno;

struct lista{
    Aluno info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista *cria_lista(){
    return NULL;
}

Lista *inserir_elementos(Lista *aluno, int matricula){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info.matricula = matricula;

    printf("Informe o nome do aluno: ");
    fgets(novo->info.nome, 50, stdin);

    novo->prox = aluno;

    return novo;
}

void imprime_lista(Lista *l){
    Lista *p = l;

    while (p != NULL){
        printf("\nMatricula: %d", p->info.matricula);
        printf("\nNome: %s", p->info.nome);
        p = p->prox;
    }
}

int input_matricula(){
    int matricula = 0;

    while (matricula == 0){
        printf("Insira uma matricula: ");
        scanf("%d", &matricula);
        getchar();
    }
    return matricula;
}

void libera_lista(Lista *l) {
    Lista *p = l;
    while (p != NULL) {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

int main(){
    Lista *l = cria_lista();

    int matricula = input_matricula();

    l = inserir_elementos(l, matricula);
    imprime_lista(l);
    libera_lista(l);

    return 0;
}

