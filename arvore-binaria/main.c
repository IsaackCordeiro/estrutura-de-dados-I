#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main(){
    ArvBin *raiz;

    raiz = cria_ArvBin();

    libera_ArvBin(raiz);
    
    if(estaVazia_ArvBin(raiz)){
        printf("Arvore vazia\n");
    }else{
        printf("Arvore possui itens\n");
    }

    int altura_Arv = altura_ArvBin(raiz);
    printf("Altura da arvore: %d\n", altura_Arv);

    int totalNos = totalNO_ArvBin(raiz);
    printf("Quantidade de nos: %d\n", totalNos);
    
    return 0;
}