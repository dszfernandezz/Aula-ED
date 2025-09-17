#include <stdio.h>
#include <stdlib.h>
//criando estrutura da matriz diagonal
struct diagonal {
    int ordem; // Ordem da matriz
    int *v; // Os elementos da diagonal principal são armazenados neste vetor
};
typedef struct diagonal Diagonal;

//Função para criar a matriz
Diagonal *cria_matriz(int ordem){
    Diagonal *matriz = (Diagonal*) malloc(sizeof(Diagonal));
    matriz->ordem = ordem;
    matriz->v = (int*)malloc(ordem * sizeof(int));
    
    return matriz;
}

//Função para informar a ordem da matriz, com validação de valores
int info_ordem(){
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
int input_info(int i){
    int valor, elemento;
    while (1){
        printf("\nInsirir info na posicao [%d][%d]: ", i, i);
        elemento = scanf("%d", &valor);

        //Limpa o buffer de entrada
        while (getchar() != '\n');

        //Verifica se a leitura foi bem sucedida
        if ((elemento) == 1) break;
        else printf("\nInsira um elemento valido!\n");
    }
    return valor;
}

//Insere informações na matriz
Diagonal *insere_info(Diagonal *d){
    for (int i = 0; i < d->ordem; i++){
        d->v[i] = input_info(i);
    }
    return d;
}

//Imprime a matriz
void imprime_matriz(Diagonal *d){
    for (int i = 0; i < d->ordem; i++){
        printf("valor da posicao v[%d][%d]: %d\n", i, i, d->v[i]);
    }
}

//Função para consultar um elemento escolhido pelo usúario
void consultar_elemento(Diagonal *d){
    int i, j;
    printf("\nInforme a linha: ");
    scanf("%d", &i);

    printf("Informe a coluna: ");
    scanf("%d", &j);

    if (i < 0 || j < 0 || i >= d->ordem || j >= d->ordem) printf("valor invalido");
    else (i!=j) ? printf("O valor é NULL\n") : printf("valor de [%d][%d]: %d\n", i, j, d->v[i]);
}

//Função para liberar memória
void liberar_memoria(Diagonal *d){
    free(d->v);
    free(d);
}


int main(){
    int ordem = info_ordem();
    Diagonal *d = cria_matriz(ordem);

    d = insere_info(d);

    imprime_matriz(d);

    consultar_elemento(d);

    liberar_memoria(d);

    return 0;
}