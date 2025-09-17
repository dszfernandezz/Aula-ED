//1) Faça uma função que insira elementos nesta lista, dadas as seguintes definições de structs:
//2) Faça uma função que imprima os elementos desta lista.
#include <stdio.h>
#include <stdlib.h>

struct professor{
    int codigo;
    char nome[50];
    float salario;
};
typedef struct professor Professor;

struct aluno{
    int matricula;
    char nome[50];
};
typedef struct aluno Aluno;

struct listaHet{
    int tipo;
    void* info;
    struct listaHet* prox;
};
typedef struct listaHet ListaHet;

ListaHet *cria_lista(){
    return NULL;
}



