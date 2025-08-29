//Implemente uma função que receba como parâmetro duas matrizes de inteiros de tamanho m
//x n (alocadas dinamicamente como vetor de ponteiros), soma as duas matrizes (nas
//respectivas posições), armazene esta soma numa terceira matriz e retorne a matriz resultante.
//Esta função deve obedecer ao protótipo:
//
//int** soma_matriz (int m, int n, int** mat1, int** mat2)
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int** soma_matriz(int m, int n, int** mat1, int** mat2){
    int **matriz = alocar_matriz(m, n);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            matriz[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return matriz;
} 

int main(){
    int m = 2, n = 2;
    int **mat1 = alocar_matriz(m, n);
    int **mat2 = alocar_matriz(m, n);

    preenche_matriz(m, n, mat1);
    preenche_matriz(m, n, mat2);

    int **mat3 = soma_matriz(m, n, mat1, mat2);
    desaloca_matriz(m, mat1);
    desaloca_matriz(m, mat2);
    
    mostra_matriz(m, n, mat3);
    desaloca_matriz(m, mat3);


    return 0;
}
