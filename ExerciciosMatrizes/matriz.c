#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int** alocar_matriz(int linha, int coluna){
    int **matriz = (int **)malloc(linha*sizeof(int*));
    for (int i = 0; i < linha; i++){
        matriz[i] = (int *)malloc(coluna*sizeof(int));
    }

    if (matriz == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    return matriz;
}

void desaloca_matriz(int linha, int** mat){
    for (int i = 0; i < linha; i++) free(mat[i]);
}

void preenche_matriz(int linha, int coluna, int **mat){
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("Informe o valor de m[%d][%d]: ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void mostra_matriz(int m, int n, int **mat){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("O valor de mat[%d][%d]: %d\n", i, j, mat[i][j]);
        }
    }
}