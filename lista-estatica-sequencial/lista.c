#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func-lista.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

/*
    Criar lista:

    1° passo: Define a lista
    2° passo: Aloca memória para a lista
    3° passo: Verifica se houve sucesso
    4° passo: Se sucesso, atualiza
    5° passo: Retorna a lista
*/
Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    
    if(li != NULL){
        li->qtd = 0;
    }

    return li;
}

void libera_lista(Lista *li){
    free(li);
}


/*
    Verificar o tamanho da lista:
    1° passo: Verifica se existe
        1.1° passo: Se existe, retorna quantidade
        1.2° passo: Se não existe, retorna -1
*/
int tamanho_lista(Lista *li){
    if(li != NULL){
        return li->qtd;
    }else{
        return -1;
    }
}

int verificaListaCheia(Lista *li){
    if(li == NULL){
        return -1;
    }
    if(li->qtd == MAX){
        return 1;
    }else{
        return 0;
    }
}


int lista_vazia(Lista *li){
    if(li == NULL){
        return -1;
    }

    return (li->qtd == 0);
}

/*
    Inserir no fim da lista
    1° passo: Criar nó
    2° passo: Atribuir valor ao nó
    3° passo: Inserir no final
        3.1° passo: Verificar se a lista existe
        3.2° passo: Verificar se a lista está cheia
        3.3° passo: Armazenar dados do aluno na lista
        3.4° passo: Incrimentar quantidade
*/
int insere_lista_final(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(verificaListaCheia(li)){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;

    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(verificaListaCheia(li)){
        return 0;
    }

    for(int i = li->qtd-1 ; i>=0 ; i--){
        li->dados[i+1] = li->dados[i];
    }   

    li->dados[0] = al;
    li->qtd++;

    return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(verificaListaCheia(li)){
        return 0;
    }

    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula < al.matricula){
        i++;
    }

    for(k = li->qtd-1 ; k >= i ; k--){
        li->dados[k+1] = li->dados[k];
    }

    li->dados[i] = al;
    li->qtd++;
    
    return 1;
}

int remove_lista_final(Lista *li){
    if(li == NULL){
        return 0;
    }
    if(lista_vazia(li)){
        return 0;
    }
    
    li->qtd--;

    return 1;
}

int remove_lista_inicio(Lista *li){
    if(li == NULL){
        return 0;
    }
    if(lista_vazia(li)){
        return 0;
    }

    for(int i = 0 ; i < li->qtd-1 ; i++){
        li->dados[i] = li->dados[i+1];
    }

    li->qtd--;

    return 1;
}

// Ex 1(b)
int remove_lista_meio(Lista *li, int mat){
    if(li == NULL){
        return 0;
    }

    if(lista_vazia(li)){
        return 0;
    }

    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula != mat){
        i++;
    }

    if(i == li->qtd){ // Matricula inválida
        return 0;
    }
    
    // Ex 1(b) - Mostrando item removido e sua posição
    printf("Matricula do item removido: %d\n", li->dados[i].matricula);
    printf("Posicao: %d\n", i);

    for(k = i ; k < li->qtd-1 ; k++){
        li->dados[k] = li->dados[k+1];
    }

    li->qtd--;

    return 1;
}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd){
        return 0;
    }

    *al = li->dados[pos-1];

    return 1;
}

//Ex 1(a)
void imprime_lista(Lista *li){
    if(li == NULL){
        printf("Lista inexistente\n");
    }
    if(lista_vazia(li)){
        printf("Lista vazia\n");
    }

    printf("\n====== IMPRIMINDO DADOS ======\n");

    for(int i = 0 ; i < li->qtd ; i++){
        
        printf("\nNome: %s\n", li->dados[i].nome);
        printf("Matricula: %d\n", li->dados[i].matricula);
        printf("Nota da prova 1: %.2f\n", li->dados[i].nota1);
        printf("Nota da prova 2: %.2f\n", li->dados[i].nota2);
        printf("Nota da prova 3: %.2f\n", li->dados[i].nota3);
        printf("\n ------------------------------------- \n");
    }
}

// Ex 1(c)
int orderna_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    if(lista_vazia(li)){
        return 0;
    }

    int auxMat, auxN1, auxN2, auxN3, i, j;
    char auxNome[200];

    for(j = 0 ; j < li->qtd ; j ++){
        for(i = 0 ; i < li->qtd ; i++){
            if(li->dados[i].matricula > li->dados[i+1].matricula && i+1 < li->qtd){
                auxMat = li->dados[i].matricula;
                strncpy(auxNome, li->dados[i].nome, strlen(li->dados[i].nome)+1);
                auxN1 = li->dados[i].nota1;
                auxN2 = li->dados[i].nota2;
                auxN3 = li->dados[i].nota3;
                li->dados[i].matricula = li->dados[i+1].matricula;
                strncpy(li->dados[i].nome, li->dados[i+1].nome, strlen(li->dados[i+1].nome)+1);
                li->dados[i].nota1 = li->dados[i+1].nota1;
                li->dados[i].nota2 = li->dados[i+1].nota2;
                li->dados[i].nota3 = li->dados[i+1].nota3; 
                li->dados[i+1].matricula = auxMat;
                strncpy(li->dados[i+1].nome, auxNome, strlen(auxNome)+1);
                li->dados[i+1].nota1 = auxN1;
                li->dados[i+1].nota2 = auxN2;
                li->dados[i+1].nota3 = auxN3;
            }
        }
    }
    return 1;
}

// Ex 2
int lista_ordenada(Lista *li, int cod){
    if(li == NULL){
        return -1;
    }
    if(lista_vazia(li)){
        return -1;
    }

    int isSorted = 0, i, j;

    if(cod == 1){
        for(i = 0 ; i < li->qtd ; i++){
            if(li->dados[i].matricula < li->dados[i+1].matricula && i+1 < li->qtd){
                isSorted++;
            }
        }
        return (isSorted == li->qtd-1);
    }else if(cod == 2){
        for(i = 0 ; i < li->qtd ; i++){
            if(li->dados[i].matricula > li->dados[i+1].matricula && i+1 < li->qtd){
                isSorted++;
            }
        }
        return (isSorted == li->qtd-1);
    }
    
    
}