#include <stdio.h>
#include <stdlib.h>
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

    // if(li->qtd == 0){
    //     return 1;
    // }else{
    //     return 0;
    // }

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

    if(i == li->qtd){
        return 0;
    }
    
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