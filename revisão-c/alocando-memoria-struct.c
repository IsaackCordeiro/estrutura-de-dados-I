#include <stdio.h>
#include <stdlib.h>

#define N 2

struct pessoa {
    int documento;
    char nome[30];
    int idade;
};

typedef struct pessoa Pessoa;

int main(){
    Pessoa *p;

    // Alocando memória para o TAD(Tipo abstrato de dados)
    p = (Pessoa*)malloc(N * sizeof(Pessoa));
    
    for(int i = 0 ; i < N ; i++){
        printf("Informe o documento: ");
        scanf("%d", &p[i].documento);
        printf("Informe o nome: ");
        scanf("%s", &p[i].nome);
        printf("Informe a idade: ");
        scanf("%d", &p[i].idade);
    }

    printf("\n-------------- IMPRIMINDO DADOS ---------------\n\n");
    
    for(int i = 0 ; i < N ; i++){
        printf("Documento: %d\t\t", p[i].documento);
        printf("Nome: %s\t\t", p[i].nome);
        printf("Idade: %d\n", p[i].idade);
    }

    return 0;
}