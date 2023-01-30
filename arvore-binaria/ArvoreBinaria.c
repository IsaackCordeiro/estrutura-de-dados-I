/*
    Aqui está: 
    - o tipo de dado "árvore"
    - implementar as suas funções
*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin)); // Aloca memória para *raiz

    if(raiz != NULL){ // Verifica se alocou memória
        *raiz = NULL; // Conteúdo de raiz é igual a NULL
    }

    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL){ // Verifica se o nó é nulo
        return;
    }
    
    libera_NO(no->esq); // Percorre recursivamente os nós da esquerda
    libera_NO(no->dir); // Percorre recursivamente os nós da direita
    free(no); // Libera o nó pai

    no = NULL;
}

void libera_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }

    libera_NO(*raiz); // Libera cada nó
    free(raiz); // Libera raiz

    
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL){ // Verifica se raiz é nulo
        return 1;
    }
    if(*raiz == NULL){ // Verifica se o conteúdo do nó raiz é nulo
        return 1;
    }

    return 0;
}

int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }

    int alt_esq = altura_ArvBin(&((*raiz)->esq)); // Percorre os nós da esquerda recursivamente até chegar o nó folha
    int alt_dir = altura_ArvBin(&((*raiz)->dir)); // Percorre os nós da direita recursivamente até chegar o nó folha

    if(alt_esq > alt_dir){ // Verifica se altura da esquerda é maior que da direita, seja qual for maior o nó pai recebe a altura de um dos nós + 1
        return (alt_esq+1);
    }else{
        return (alt_dir+1);
    }
}

int totalNO_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }

    int alt_esq = altura_ArvBin(&((*raiz)->esq)); // Percorre os nós da esquerda recursivamente até chegar o nó folha
    int alt_dir = altura_ArvBin(&((*raiz)->dir)); // Percorre os nós da direita recursivamente até chegar o nó folha

    return (alt_esq + alt_dir + 1); // Retorna a soma altura da sub-árvore esquerda com a direita + 1 que representa o nó raiz
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info); // Mostra o nó
        preOrdem_ArvBin(&((*raiz)->esq)); // Caminha pelos nós da sub-arvore esquerda
        preOrdem_ArvBin(&((*raiz)->dir)); // Caminha pelos nós da sub-arvore direita
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        preOrdem_ArvBin(&((*raiz)->esq)); // Caminha pelos nós da sub-arvore esquerda
        printf("%d\n", (*raiz)->info); // Mostra o nó
        preOrdem_ArvBin(&((*raiz)->dir)); // Caminha pelos nós da sub-arvore direita
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        preOrdem_ArvBin(&((*raiz)->esq)); // Caminha pelos nós da sub-arvore esquerda
        preOrdem_ArvBin(&((*raiz)->dir)); // Caminha pelos nós da sub-arvore direita
        printf("%d\n", (*raiz)->info); // Mostra o nó
    }
}

ArvBin *insere_ArvBin(ArvBin *raiz, int valor){
    if(*raiz == NULL){
      struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));

        if(novo == NULL){
            return 0;
        }
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return novo;
    }
    struct NO* atual = *raiz;

    if (valor < atual->info){
        atual->esq = insere_ArvBin(&(atual->esq), valor);
    }else if(valor > atual->info){
        atual->dir = insere_ArvBin(&(atual->dir), valor);
    }

    return atual;
}


int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }

    struct NO *atual = *raiz;

    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    
    return 0;
}