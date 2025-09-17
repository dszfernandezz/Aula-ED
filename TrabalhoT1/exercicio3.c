#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Criar estrutura do elemento
struct elemento {
    int linha;
    int coluna;
    int valor;
    struct elemento *prox;
};
typedef struct elemento Elemento;

//Cria estrutura para a matriz identidade
struct matrizidentidade {
    int ordem;
    Elemento *violacao;
};
typedef struct matrizidentidade MatrizIdentidade;

//Função para criar a matriz
MatrizIdentidade *criar_matriz(int ordem){
    MatrizIdentidade *novo = (MatrizIdentidade*)malloc(sizeof(MatrizIdentidade));
    novo->ordem = ordem;
    novo->violacao = NULL;

    return novo;
}

//Função para adicionar violação
void adicionar_violacao(MatrizIdentidade *matriz, int linha, int coluna, int valor){
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->valor = valor;
    novo->prox = matriz->violacao;
    matriz->violacao = novo;
}

//Função para informar a ordem da matriz, com validação de valores
int ordem_matriz(){
    int valor, elemento;
    while (1){
        printf("\nInforme a ordem da matriz: ");
        elemento = scanf("%d", &valor);

        // Limpra buffer de entrada
        while (getchar() != '\n');
        
        //Verifica se a leitura foi bem sucedida e se o valor é positivo
        if ((elemento) == 1 && valor > 0) break;
        else printf("\nInsira um elemento valido!\n");
    }
    return valor;
}

//Função para validar a informação
int input_valor(int i, int j){
    int valor, elemento;
    while (1){
        printf("\nInsira um valor na posicao [%d][%d]: ", i, j);
        elemento = scanf("%d", &valor);

        //Limpa o buffer de entrada
        while (getchar() != '\n');

        //Verifica se a leitura foi bem sucedida
        if ((elemento) == 1) break;
        else printf("\nInsira um elemento valido!\n");
    }
    return valor;
}

//Função para preencher a matriz
void preencher_matriz(MatrizIdentidade *matriz){
    int valor;
    for (int i = 0; i < matriz->ordem; i++){
        for (int j = 0; j < matriz->ordem; j++){
            valor = input_valor(i, j);
            //Verifica se é uma violação da matriz identidade
            if ((i == j && valor != 1) || (i != j && valor != 0)){
                adicionar_violacao(matriz, i, j, valor);
            }
        }
    }
}

//Função para imprimir a matriz
void imprime_matriz(MatrizIdentidade *matriz){
    printf("\nImpressao da Matriz: ");
    for (int i = 0; i < matriz->ordem; i++){
        for (int j = 0; j < matriz->ordem; j++){
            bool encontrou = false;

            //Procura se há violação nesta posição
            for (Elemento *e = matriz->violacao; e != NULL; e = e->prox){
                if (e->linha == i && e->coluna == j){
                    encontrou = true;
                    break;
                }
            }
            
            //Se não encontrou violação, imprime o valor correto
            if (!encontrou){
                printf("%d ", (i == j) ? 1 : 0);
            } else{
                printf("X "); //Marca a violação com X
            }
        }
        printf("\n");   
    }
}

//Função para mostrar as violações
void mostrar_violacao(MatrizIdentidade *matriz){
    printf("\nImpressao das violacoes: ");
    if(matriz->violacao == NULL) printf("\nA matriz é uma matriz identidade.");
    else {
        //Percorre todas as violações e imprime
        for (Elemento *e = matriz->violacao; e != NULL; e = e->prox){
            printf("Violacao na posição [%d][%d]: %d\n", e->linha, e->coluna, e->valor);  
        }
    }
}

//Função para liberar memória
void liberar_memoria(MatrizIdentidade *matriz){
    Elemento *e = matriz->violacao;
    while (e != NULL){
        Elemento *temp = e;
        e = e->prox;
        free(temp);
    }
    free(matriz);
}

//Função principal
int main(){
    //Solicita a ordem da matriz
    int ordem = ordem_matriz();
    //Cria a matriz
    MatrizIdentidade *matriz = criar_matriz(ordem);

    //Preenche a matriz com valores do usuário
    preencher_matriz(matriz);
    //Imprime a matriz
    imprime_matriz(matriz);
    //Mostra as violações encontradas
    mostrar_violacao(matriz);

    //Libera a memória alocada
    liberar_memoria(matriz);

    return 0;
}