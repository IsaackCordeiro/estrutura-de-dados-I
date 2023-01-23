#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main(){
    ArvBin *raiz;

    raiz = cria_ArvBin();

    libera_ArvBin(raiz);

    return 0;
}