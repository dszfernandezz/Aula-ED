//1) Faça uma função que insira elementos na lista.
//2) Faça uma função que imprima os elementos desta lista.
#include <stdio.h>
#include <stdlib.h>


struct lista{
    int matricula;
    char nome[50];
    struct lista* prox;
};
typedef struct lista Lista;

Lista *cria_lista(){
    return NULL;
}

Lista *inserir_elementos(Lista *aluno, int matricula){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->matricula = matricula;

    printf("Informe o nome do aluno: ");
    fgets(novo->nome, 50, stdin);

    novo->prox = aluno;

    return novo;
}

void imprime_lista(Lista *l){
    Lista *p = l;

    while (p != NULL){
        printf("\nMatricula: %d", p->matricula);
        printf("\nNome: %s", p->nome);
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

int main(){
    Lista *l = cria_lista();

    int matricula = input_matricula();

    l = inserir_elementos(l, matricula);
    imprime_lista(l);
    
}