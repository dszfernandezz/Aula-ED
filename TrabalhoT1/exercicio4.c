#include <stdio.h>
#include <stdlib.h>

// Função para solicitar e validar a quantidade de linhas
int input_linha(){
    int valor, elemento;
    while (1){
        printf("\nInforme o número de linhas: ");
        elemento = scanf("%d", &valor);

        //Limpa o buffer de entrada
        while (getchar() != '\n');
        
        if (elemento == 1 && valor > 0) break;
        else printf("\nInsira um valor válido!");
    }
    return valor;
}

//Função para solicitar e validar a quantidade de colunas
int input_coluna(){
    int valor, elemento;
    while (1){
        printf("\nInforme o número de colunas: ");
        elemento = scanf("%d", &valor);

        //Limpa o buffer de entrada
        while (getchar() != '\n');
        
        if (elemento == 1 && valor > 0) break;
        else printf("\nInsira um valor válido!");
    }
    return valor;
}

//Função para solicitar e validar a profundidade da matriz
int input_profundidade(){
    int valor, elemento;
    while (1){
        printf("\nInforme a profundidade: ");
        elemento = scanf("%d", &valor);

        //Limpa o buffer de entrada
        while (getchar() != '\n');
        
        if (elemento == 1 && valor > 0) break;
        else printf("\nInsira um valor válido!");
    }
    return valor;
}

//Aloca dinamincamente a matriz de três dimensões
int*** aloca_matriz (int m, int n, int z){
    int ***matriz = (int***)malloc(m * sizeof(int**));
    for (int i = 0; i < m; i++){
        matriz[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++){
            matriz[i][j] = (int*)malloc(z * sizeof(int));
        }
    }
    return matriz;
}

//Validação para o usurio digitar um numero inteiro
int input_num(int i, int j, int k){
    int valor, elemento;
    while (1){
        printf("Preencha uma inteiro na posição[%d][%d][%d]: ", i, j, k);
        elemento = scanf("%d", &valor);

        //Limpa o buffer de entrada
        while (getchar() != '\n');
        
        if (elemento == 1) break;
        else printf("\nInsira um valor válido!\n");
    }
    return valor;
}

//Função para preencher a matriz
void preenche_matriz (int m, int n, int z, int ***mat){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < z; k++){
                mat[i][j][k] = input_num(i, j, k);
            }   
        }
    }
    
}

//Função para imprimir a matriz
void imprime_matriz (int m, int n, int z, int ***mat){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < z; k++){
                printf("\nValor na posição[%d][%d][%d]: %d", i, j, k, mat[i][j][k]);
            }   
        }
        printf("\n");
    }
}

// Função para liberar memória
void liberar_memoria(int ***mat, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);
}


int main(){
    int m = input_linha();
    int n = input_coluna();
    int z = input_profundidade();

    int ***mat = aloca_matriz(m, n, z);

    preenche_matriz(m, n, z, mat);
    imprime_matriz(m, n, z, mat);
    liberar_memoria(mat, m, n);
    
    return 0;
}