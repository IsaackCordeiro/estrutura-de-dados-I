#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncadDupla.h"

// Struct que controla a lista
struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista(){
    Lista *li = (Lista *)malloc(sizeof(Lista)); // Alocando memória para lista

    if(li != NULL){// Verifica se foi alocado corretamente
        *li = NULL; // Li aponta para NULL, ou seja, lista fazia
    }

    return li;
}


void libera_lista(Lista *li){
    if(li != NULL){
        Elem *no; // Cria nó
        while((*li) != NULL){ // Percorre a lista até o final
            no = *li;   // Aponta nó para o Conteúdo de li
            *li = (*li)->prox; // li aponta para o seu próximo
            free(no); // Libera nó, que é onde li apontava anteriormente
        }
        free(li); // Libera li
    }
}

int tamanho_lista(Lista *li){
    if(li == NULL){ // Verifica se a lista existe
        return 0;
    }
    
    int cont = 0;
    Elem *no = *li;  // Cria no e aponta para o conteúdo de li

    while(no != NULL){
        cont++;      // Incrementa cont
        no = no->prox; // No aponta para o seu proximo elemento
    }

    return cont;
}

int lista_vazia(Lista *li){
    if(li == NULL){  // Se lista é nula, então está vazia
        return 1;
    }
    if(*li == NULL){  // Se o conteudo dela aponta pra null, ela está vazia
        return 1;
    }

    return 0;
}


int insere_lista_inicio(Lista *li, struct aluno al){
    if(li == NULL){ // Verifica se a lista existe
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    
    if (no == NULL){  // Verifica se o novo nó foi alocado corretamente
        return 0;
    }

    no->dados = al; // Atribui os dados
    no->prox = (*li); // Aponta prox para o conteudo em que li aponta
    no->ant = NULL;

    if(*li != NULL){
        (*li)->ant = no;
    }
    *li = no; // Aponta li para o nó que passa a ser o primeiro

    return 1;
}


int insere_lista_final(Lista *li, struct aluno al){
    if(li == NULL){ // Verifica se a lista existe
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    
    if (no == NULL){ // Verifica se o novo nó foi alocado corretamente
        return 0;
    }

    no->dados = al; // Atribui dados
    no->prox = NULL; // Aponta prox do novo nó para NULL, pois vai ser o último

    if((*li) == NULL){ // Lista vazia? Insere no início
        no->ant = NULL;
        *li = no; // Conteúdo de li aponta para nó
    }else{
        Elem *aux = *li; // Cria elemento aux que aponta para o conteúdo de li
        while (aux->prox != NULL){ // Buscando a última posição
            aux = aux->prox;   // Nó aux recebe o seu proxímo elemento
        }
        aux->prox = no; // Apontando o último para o novo nó último
        no->ant = aux;
    }

    return 1;
}

int insere_lista_ordenado(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    
    if (no == NULL){
        return 0;
    }

    no->dados = al; // Atribui dados

    if(lista_vazia(li)){
        no->ant = NULL;
        no->prox = (*li); // Aponta prox para NULL(onde li está apontando)
        *li = no; // Aponta li para o nó que passa a ser o primeiro
        return 1;
    }else{
        // Procurar o local para inserir novo nó
        Elem *ante, *atual = *li;

        while(atual != NULL && atual->dados.matricula < al.matricula){
            ante = atual;      // Ant aponta para Atual
            atual = atual->prox; // Atual recebe seu proximo elemento
        }    

        if(atual == *li){ // Atual é o início da lista? Insere no início
            no->ant = NULL;
            (*li)->ant = no; 
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ante->prox; // No prox aponta para o proximo elemento de ant
            no->ant = ante;
            ante->prox = no;   // ant prox aponta para o novo Nó
            if(atual != NULL) atual->ant = no;
        }

        return 1;
    }
}

int remove_lista_inicio(Lista *li){
    if(li == NULL){ // Verifica se a lista existe
        return 0;
    }

    if(*li == NULL){ // Verifica se a Lista está Vazia 
        return 0;
    }

    Elem *no = *li; // Cria novo nó e aponta para conteudo de li
    *li = no->prox;  // li aponta para onde no->prox aponta

    if(no->prox != NULL) no->prox->ant = NULL; // Verifica se tem mais de um elemento na lista

    free(no);  // Libera o no

    return 1;
}

int remove_lista_final(Lista *li){
    if(li == NULL){ // Verifica se a lista existe
        return 0; 
    }

    if(*li == NULL){ // Verifica se a Lista está Vazia 
        return 0;
    }

    Elem *no = *li;  // Cria nó no e aponta para li

    while (no->prox != NULL){  // Percorre a lista até o final
        no = no->prox;  // Aponta no para no->prox
    }

    if(no == (*li)){  // No aponta pro conteudo de li? Ou seja, lista está vazia
        *li = no->prox; // Conteudo de li aponta para o proximo elemento de no
    }else{
        no->ant->prox = NULL;  // Se não, o proximo elemento do anterior aponta para o proximo elemento de no
    }

    free(no);  // Libera o nó
    
    return 1;
}

int remove_lista_meio(Lista *li, int mat){
    if(li == NULL) return 0;  // Verifica se a lista existe
     
    Elem *no = *li; // Cria nó no e aponta para li
    
    while(no->prox != NULL && no->dados.matricula != mat){ // Percorrte a lista até o final ou até encontrar a matricula
        no = no->prox;  // Aponta no para no->prox
    }

    if(no == NULL) return 0; // Não Encontrado

    if(no = *li){ // No aponta pro conteudo de li? Ou seja, lista está vazia
        *li = no->prox;    // Conteudo de li aponta para o proximo elemento de no
    } else{
        no->ant->prox = no->prox; // Se não, o proximo elemento do anterior aponta para o proximo elemento de no
        if(no->prox != NULL){ // Verifica se nao é um ultimo elemento
            no->prox->ant = no->ant;
        }
    } 

    free(no); // libera o no

    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0){  // Verifica se a lista existe ou se a posição é válida
        return 0;
    }

    Elem *no = *li;  // Cria nó e aponta para o conteudo de li(início da lista)
    int i = 1; 

    while(no != NULL && i < pos){ // Percorre a lista até o final ou até que i for igual a posição que o usuário quer
        no = no->prox;
        i++;
    }

    if(no == NULL){ // Lista vazia?
        return 0;
    }else{
        *al = no->dados;  // O conteúdo de al vai receber os dados na posição que o usuário pediu
        return 1;
    }
}