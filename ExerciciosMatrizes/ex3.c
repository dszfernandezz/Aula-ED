//Implemente quatro funções que alocam, desalocam, preenchem e mostram uma matriz de
//tamanho mxn, respectivamente (considere que a matriz seja armazenada como um vetor de
//ponteiros). Estas funções devem obedecer aos protótipos:
//int** aloca_matriz (int m, int n)
//void desaloca_matriz (int m, int** mat)
//void preenche_matriz (int m, int n, int **mat)
//void mostra_matriz (int m, int n, int **mat)
#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int m = 4, n = 2;
    int **mat = alocar_matriz(m, n);
    preenche_matriz(m, n, mat);
    mostra_matriz(m, n, mat);
    desaloca_matriz(m, mat);

    return 0;
}