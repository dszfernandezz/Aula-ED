#include <stdio.h>
#include <stdlib.h>

struct diagonal {
    int ordem; 
    int* v;
};

typedef struct diagonal Diagonal;

Diagonal *cria_matriz(int ordem){
    Diagonal *matriz = (Diagonal*) malloc(sizeof(Diagonal));
    matriz->ordem = ordem;
    matriz->v = (int*)malloc(ordem * sizeof(int));
    
    return matriz;
}

int info_ordem(){
    int i=0;
    printf("Informe a ordem da matriz: ");
    scanf("%d", &i);
    return i;
}

Diagonal *insere_info(Diagonal *d){
    for (int i = 0; i < d->ordem; i++){
        printf("Inserir info na posicao [%d][%d]: ", i, i);
        scanf("%d", &d->v[i]);
    }
    return d;
}

void imprime_matriz(Diagonal *d){
    for (int i = 0; i < d->ordem; i++){
        printf("valor da posicao v[%d][%d]: %d\n", i, i, d->v[i]);
    }
}

void consultar_elemento(Diagonal *d){
    int i, j;
    printf("\nInforme a linha: ");
    scanf("%d", &i);

    printf("Informe a coluna: ");
    scanf("%d", &j);

    if (i < 0 || j < 0 || i >= d->ordem || j >= d->ordem) printf("valor invalido");
    else (i!=j) ? printf("O valor é NULL\n") : printf("valor de [%d][%d]: %d\n", i, j, d->v[i]);

}


int main(){
    int ordem = info_ordem();
    Diagonal *d = cria_matriz(ordem);

    d = insere_info(d);

    imprime_matriz(d);

    consultar_elemento(d);

    free(d);

    return 0;
}