#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elemento {
    int linha;
    int coluna;
    int valor;
    struct elemento *prox;
};
typedef struct elemento Elemento;

struct matrizidentidade {
    int ordem;
    Elemento *violacao;
};
typedef struct matrizidentidade MatrizIdentidade;

MatrizIdentidade *criar_matriz(int ordem){
    MatrizIdentidade *novo = (MatrizIdentidade*)malloc(sizeof(MatrizIdentidade));
    novo->ordem = ordem;
    novo->violacao = NULL;
    return novo;
}

void adicionar_violacao(MatrizIdentidade *matriz, int linha, int coluna, int valor){
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->valor = valor;
    novo->prox = matriz->violacao;
    matriz->violacao = novo;
}

int ordem_matriz(){
     int valor, elemento;
    while (1){
        printf("\nInforme a ordem da matriz: ");
        elemento = scanf("%d", &valor);

        while (getchar() != '\n');
        
        if ((elemento) == 1 && valor > 0) break;
        else printf("\nInsira um elemento valido!\n");
    }
    return valor;
}

int input_valor(int i, int j){
    int valor, elemento;
    while (1){
        printf("\nInsira um valor na posicao [%d][%d]: ", i, j);
        elemento = scanf("%d", &valor);

        while (getchar() != '\n');

        if ((elemento) == 1) break;
        else printf("\nInsira um elemento valido!\n");
    }
    return valor;
}

void preencher_matriz(MatrizIdentidade *matriz){
    int valor;
    for (int i = 0; i < matriz->ordem; i++){
        for (int j = 0; j < matriz->ordem; j++){
            valor = input_valor(i, j);
            if ((i == j && valor != 1) || (i != j && valor != 0)){
                adicionar_violacao(matriz, i, j, valor);
            }
        }
    }
}

void imprime_matriz(MatrizIdentidade *matriz){
    printf("\nImpressao da Matriz: ");
    for (int i = 0; i < matriz->ordem; i++){
        for (int j = 0; j < matriz->ordem; j++){
            bool encontrou = false;

            for (Elemento *e = matriz->violacao; e != NULL; e = e->prox){
                if (e->linha == i && e->coluna == j){
                    encontrou = true;
                    break;
                }
            }
            if (!encontrou){
                printf("%d ", (i == j) ? 1 : 0);
            } else{
                printf("X ");
            }
        }
        printf("\n");   
    }
}

void mostrar_violacao(MatrizIdentidade *matriz){
    printf("\nImpressao das violacoes: ");
    if(matriz->violacao == NULL) printf("\nA matriz é uma matriz identidade.");
    else {
        for (Elemento *e = matriz->violacao; e != NULL; e = e->prox){
            printf("Violacao na posição [%d][%d]: %d\n", e->linha, e->coluna, e->valor);  
        }
    }
}

void liberar_memoria(MatrizIdentidade *matriz){
    Elemento *e = matriz->violacao;
    while (e != NULL){
        Elemento *temp = e;
        e = e->prox;
        free(temp);
    }
    free(matriz);
}

int main(){
    int ordem = ordem_matriz();
    MatrizIdentidade *matriz = criar_matriz(ordem);

    preencher_matriz(matriz);
    imprime_matriz(matriz);
    mostrar_violacao(matriz);

    liberar_memoria(matriz);

    return 0;
}