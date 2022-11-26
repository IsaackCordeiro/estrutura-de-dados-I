#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    int **matriz;

    printf("Informe o numero de linhas: ");
    scanf("%d", &n);
    printf("Informe o numero de colunas: ");
    scanf("%d", &m);
    
    //Aloca memória para as linhas
    matriz = (int**)malloc(n * sizeof(int*));


    //Aloca memória para as colunas
    for(int i = 0 ; i < n ; i++){
        matriz[i] = (int*)malloc(m * sizeof(int));
    }

    // Preenchendo matriz
    for(int i = 0 ; i < n ; i++){
        for (int j = 0; j < m ; j++){
            matriz[i][j] = i + j;
        }
    }

    // Imprimindo matriz
    for(int i = 0 ; i < n ; i++){
        for (int j = 0; j < m ; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a memória alocadas para as linhas
    for(int i = 0 ; i < n ; i++){
        free(matriz[i]);
    }
    // Libera a memória alocada do ponteiro de fato
    free(matriz);

    return 0;

}