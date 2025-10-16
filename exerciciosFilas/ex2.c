#include <stdio.h>
#include <stdlib.h>
#include "filas_lst.h"
#include "filas_vet.h"

void combina_filas(FilaLst* f_res, FilaLst* f1, FilaLst* f2){
    while (!filaLst_vazia(f1) || !filaLst_vazia(f2)){
        if (!filaLst_vazia(f1)){
            insere_filaLst(f_res, retira_filaLst(f1));
        }
        
        if (!filaLst_vazia(f2)){
            insere_filaLst(f_res, retira_filaLst(f2));
        }
    }
}

int main(){
    FilaLst *f1 = cria_filaLst();
    FilaLst *f2 = cria_filaLst();
    FilaLst *f3 = cria_filaLst();

    insere_filaLst(f1, 9);
    insere_filaLst(f1, 6);
    insere_filaLst(f1, 4);
    insere_filaLst(f1, 1);
    insere_filaLst(f1, 2);

    insere_filaLst(f2, 5);
    insere_filaLst(f2, 9);
    insere_filaLst(f2, 7);
    insere_filaLst(f2, 6);
    insere_filaLst(f2, 3);
    insere_filaLst(f2, 3);

    
    imprime_filaLst(f1);
    printf("\n");
    imprime_filaLst(f2);

    printf("\n");

    combina_filas(f3, f1, f2);

    imprime_filaLst(f3);

    return 0;

}