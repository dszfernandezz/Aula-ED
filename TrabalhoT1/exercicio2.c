#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Criar estrutura da Lista
struct lista {
    int linha;
    int coluna;
    int info;           
    struct lista *prox; 
};

typedef struct lista Lista;

//Cria estrutura para a matriz esparsa
struct esparsa{
    int linhas;   
    int colunas;        
    struct lista *prim;
};
typedef struct esparsa Esparsa;

//Função para criar a matriz esparsa
Esparsa *criar_matriz(int linha, int coluna){
    Esparsa *m = (Esparsa*)malloc(sizeof(Esparsa));
    m->colunas = coluna;
    m->linhas = linha;
    m->prim = NULL;

    return m;
}

// Função para o usurio informar o numero de linhas
int consultar_linha(){
    int valor, elemento;
    while (1){
        printf("\nInforme o numero de linhas: ");
        elemento = scanf("%d", &valor);

        // Limpra buffer de entrada
        while (getchar() != '\n');
        
        //Verifica se a leitura foi bem sucedida e se o valor é positivo
        if ((elemento) == 1 && valor > 0) break;
        else printf("\nInsira um elemento valido!\n");
    }
    return valor;
}

// Função para o usurio informar o numero de colunas
int consultar_coluna(){
    int valor, elemento;
    while (1){
        printf("\nInforme o numero de colunas: ");
        elemento = scanf("%d", &valor);

        // Limpra buffer de entrada
        while (getchar() != '\n');
        
        //Verifica se a leitura foi bem sucedida e se o valor é positivo
        if ((elemento) == 1 && valor > 0) break;
        else printf("\nInsira um elemento valido!\n");
    }
    return valor;
}

//Função para validar o valor de uma linha
bool valida_lin(Esparsa *matriz, int linha){
    if (linha < 0 || linha >= matriz->linhas){
        printf("Linha %d invalida! Deve estar entre 0 e %d\n", linha, matriz->linhas-1);
        return false;
    }
    return true;
}

//Função para validar o valor de uma coluna
bool valida_col(Esparsa *matriz, int coluna){
    if (coluna < 0 || coluna >= matriz->colunas){
        printf("Coluna %d invalida! Deve estar entre 0 e %d\n", coluna, matriz->colunas-1);
        return false;
    }
    return true;
}

//Função para inserir um elemento
void inserir_elemento(Esparsa *matriz, int linha, int coluna, int valor){
    if (valor == 0) return;
    
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->info = valor;
    novo->prox = matriz->prim;
    matriz->prim = novo;
}

//Função para receber a respostas do usuario
char resposta(int i, int j){
    char r;
    printf("Deseja inserir um numero nao nulo na posicao m[%d][%d]: (S/N)", i, j);
    scanf("%c", &r);
    getchar();

    return r;
}

//Função para o usurio informar um valor não nulo
int informar_valor(){
    int valor = 0;
    while (valor == 0){
        printf("informe um valor nao nulo: ");
        scanf("%d", &valor);
        getchar();

    }

    return valor;
}

//Função para preencher a matriz esparsa
void preencher_matriz(Esparsa *matriz){
    for (int i = 0; i < matriz->linhas; i++){
        for (int j = 0; j < matriz->colunas; j++){
            char resp = resposta(i, j);

            //Caso a respostas for sim, inseri o elemento na posição desejada pelo usuario
            if (resp == 'S' || resp == 's'){
                int valor = informar_valor();
                inserir_elemento(matriz, i, j, valor);
            }
        }       
    }
}

//Função para imprimir a matriz
void imprimir_matriz(Esparsa *matriz){
    for (int i = 0; i < matriz->linhas; i++){
        for (int j = 0; j < matriz->colunas; j++){
            bool encontrou = false;

            for (Lista *l = matriz->prim; l != NULL; l = l->prox){
                if (l->linha == i && l->coluna == j){
                    printf("%d ", l->info);
                    encontrou = true;
                    break;
                }
            }

            if (!encontrou) printf("0 ");
        }
        printf("\n");
    }
}

// Função para somar elementos de uma linha especifica
int somatario_linha(Esparsa* matriz, int linha){
    int soma = 0;
    for (Lista* l = matriz->prim; l != NULL; l = l->prox) {
        if (l->linha == linha) soma += l->info;
    }
    return soma;
}

//Função para solicitar uma linha e mostrar a soma da mesma
void mostrar_soma_linha(Esparsa *matriz){
    int i;
    printf("Deseja fazer o somatorio da qual linha: ");
    scanf("%d", &i);

    int soma = somatario_linha(matriz, i);

    printf("Soma da Linha %d: %d\n", i, soma);
}

// Função para consultar um elemento especifico
int consultar_elemento(Esparsa* matriz, int linha, int coluna) {
    if (!valida_lin(matriz, linha) || !valida_col(matriz, coluna)){
        return -1;
    }

    for (Lista* l = matriz->prim; l != NULL; l = l->prox) {
        if (l->linha == linha && l->coluna == coluna) {
            return l->info;
        }
    }
    return 0;
}

//Função para solicitar ao usuario a linha e a coluna e mostrar o elemento na posição
void mostrar_elemento_selecionado(Esparsa *matriz){
    int i, j;
    printf("\nEscolha a linha: ");
    scanf("%d", &i);

    printf("Escolha a coluna: ");
    scanf("%d", &j);

    int elemento = consultar_elemento(matriz, i, j);

    (elemento == -1) ? printf("\nPosicao invalida.\n") : printf("elemento na posição m[%d][%d]: %d", i, j, elemento);

}

// Função para calcular o percentual de elementos não nulos
float percentual_nao_nulos(Esparsa *matriz){
    int qtdNum = 0, total = matriz->linhas * matriz->colunas;
    for(Lista *l = matriz->prim; l != NULL; l = l->prox){
        qtdNum++;
    }

    return (float)(qtdNum * 100) / total;
}

//Função para mostar o percentual de não nulos
void mostrar_percentual(Esparsa *matriz){
    float percentual = percentual_nao_nulos(matriz);
    printf("\nO percentual de nao nulos e: %.2f\n", percentual);
}

//Função para liberar memória
void liberar_memoria(Esparsa *matriz){
    Lista *l = matriz->prim;
    while (l != NULL) {
        Lista* temp = l;
        l = l->prox;
        free(temp);
    }

    free(matriz);
}

int main(){
    int i = consultar_linha();
    int j = consultar_coluna();
    Esparsa *matriz = criar_matriz(i, j);

    preencher_matriz(matriz);
    imprimir_matriz(matriz);

    mostrar_elemento_selecionado(matriz);
    mostrar_percentual(matriz);
    mostrar_soma_linha(matriz);

    liberar_memoria(matriz);

    return 0;
}

