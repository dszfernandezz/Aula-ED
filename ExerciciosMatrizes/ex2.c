//Implemente uma função que receba como parâmetro uma matriz de inteiros de tamanho m x
//n (alocada dinamicamente como um vetor de ponteiros) e imprima na tela os elementos
//armazenados nesta matriz. Esta função deve obedecer ao protótipo:
//void imprime_matriz (int m, int n, int** mat)
#include <stdio.h>
#include <stdlib.h>

int** alocar_matriz(int m, int n){
    int **matriz = (int **)malloc(m*sizeof(int*));
    for (int i = 0; i < n; i++){
        matriz[i] = (int *)malloc(n*sizeof(int));
    }
    return matriz;
}

void preenche_matriz(int linha, int coluna, int **mat){
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("Informe o valor de m[%d][%d]: ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void imprime_matriz (int m, int n, int **mat){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("O valor de mat[%d][%d]: %d\n", i,j, mat[i][j]);
        }
    }
}

int main(){
    int m = 2, n = 2;
    int **mat = alocar_matriz(m, n);
    preenche_matriz(m, n, mat);
    mostra_matriz(m, n, mat);
    free(mat);

    return 0;
}