#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lista{
    int linha;
    int coluna;
    int info;           
    struct lista *prox; 
};
typedef struct lista Lista;

struct esparsa{
    int linhas;   
    int colunas;        
    struct lista *prim;
};
typedef struct esparsa Esparsa;

Esparsa *criar_matriz(int linha, int coluna){
    Esparsa *m = (Esparsa*)malloc(sizeof(Esparsa));
    m->colunas = coluna;
    m->linhas = linha;
    m->prim = NULL;

    return m;
}

int consultar_linha(){
    int l;
    printf("Informe o numero de linhas: ");
    scanf("%d", &l);
    getchar();
    
    return l;
}

int consultar_coluna(){
    int l;
    printf("Informe o numero de colunas: ");
    scanf("%d", &l);
    getchar();
    
    return l;
}

bool valida_lin(Esparsa *matriz, int linha){
    if (linha < 0 || linha >= matriz->linhas){
        printf("Linha %d invalida! Deve estar entre 0 e %d\n", linha, matriz->linhas-1);
        return false;
    }
    return true;
}

bool valida_col(Esparsa *matriz, int coluna){
    if (coluna < 0 || coluna >= matriz->colunas){
        printf("Coluna %d invalida! Deve estar entre 0 e %d\n", coluna, matriz->colunas-1);
        return false;
    }
    return true;
}

void inserir_elemento(Esparsa *matriz, int linha, int coluna, int valor){
    if (valor == 0) return;
    
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->info = valor;
    novo->prox = matriz->prim;
    matriz->prim = novo;
}

char resposta(int i, int j){
    char r;
    printf("Deseja inserir um numero nao nulo na posicao m[%d][%d]: (S/N)", i, j);
    scanf("%c", &r);
    getchar();

    return r;
}

int informar_valor(){
    int valor = 0;
    while (valor == 0){
        printf("informe um valor nao nulo: ");
        scanf("%d", &valor);
        getchar();

    }

    return valor;
}

void preencher_matriz(Esparsa *matriz){
    for (int i = 0; i < matriz->linhas; i++){
        for (int j = 0; j < matriz->colunas; j++){
            char resp = resposta(i, j);

            if (resp == 'S' || resp == 's'){
                int valor = informar_valor();
                inserir_elemento(matriz, i, j, valor);
            }
        }       
    }
}

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


int somatario_linha(Esparsa* matriz, int linha){
    int soma = 0;
    for (Lista* l = matriz->prim; l != NULL; l = l->prox) {
        if (l->linha == linha) soma += l->info;
    }
    return soma;
}

void mostrar_soma_linha(Esparsa *matriz){
    int i;
    printf("Deseja fazer o somatorio da qual linha: ");
    scanf("%d", &i);

    int soma = somatario_linha(matriz, i);

    printf("Soma da Linha %d: %d\n", i, soma);
}


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

void mostrar_elemento_selecionado(Esparsa *matriz){
    int i, j;
    printf("\nEscolha a linha: ");
    scanf("%d", &i);

    printf("Escolha a coluna: ");
    scanf("%d", &j);

    int elemento = consultar_elemento(matriz, i, j);

    (elemento == -1) ? printf("\nPosicao invalida.\n") : printf("elemento na posição m[%d][%d]: %d", i, j, elemento);

}

float percentual_nao_nulos(Esparsa *matriz){
    int qtdNum = 0, total = matriz->linhas * matriz->colunas;
    for(Lista *l = matriz->prim; l != NULL; l = l->prox){
        qtdNum++;
    }

    return (float)(qtdNum * 100) / total;
}

void mostrar_percentual(Esparsa *matriz){
    float percentual = percentual_nao_nulos(matriz);
    printf("\nO percentual de nao nulos e: %.2f\n", percentual);
}

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

