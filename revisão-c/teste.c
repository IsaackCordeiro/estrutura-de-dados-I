#include <stdio.h>
#include <stdlib.h>

struct pessoa{
    int idade;
    char nome[10];
};

typedef struct pessoa Pessoa;

int main(){
    int *Idades;
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);
    
    Idades = (int*)malloc(n * sizeof(int));

    if(Idades != NULL){
        Idades[0] = 10;
        Idades[1] = 20;
        Idades[2] = 30;
        printf("%d\n%d\n%d\n", Idades[0],Idades[1],Idades[2]);
    }else{
        printf("Memoria indisponivel");
    }

    free(Idades);

    return 0;

}

