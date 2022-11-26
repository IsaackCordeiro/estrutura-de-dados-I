#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncad.h"

// Struct que controla a lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista(){
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if(li != NULL){
        *li = NULL;
    }

    return li;
}

void libera_lista(Lista *li){
    if(li != NULL){
        Elem *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    
    int cont = 0;
    Elem *no = *li;

    while(no != NULL){
        cont++;
        no = no->prox;
    }

    return cont;
}

int lista_vazia(Lista *li){
    if(li == NULL){ 
        return 1;
    }
    if(*li == NULL){
        return 1;
    }

    return 0;
}

int insere_lista_inicio(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    
    if (no == NULL){
        return 0;
    }

    no->dados = al; // Atribui os dados
    no->prox = (*li); // Aponta prox para o local em que li aponta
    *li = no; // Aponta li para o nó que passa a ser o primeiro

    return 1;
}

int insere_lista_final(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }

    Elem *no = (Elem*)malloc(sizeof(Elem));
    
    if (no == NULL){
        return 0;
    }

    no->dados = al; // Atribui dados
    no->prox = NULL; // Aponta prox do novo nó para NULL, pois vai ser o último

    if((*li) == NULL){
        *li = no;
    }else{
        Elem *aux = *li;
        while (aux->prox != NULL){ // Buscando a última posição
            aux = aux->prox;
        }
        aux->prox = no; // Apontando o último para o novo nó último

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
        no->prox = (*li); // Aponta prox para NULL
        *li = no; // Aponta li para o nó que passa a ser o primeiro
    }else{
        // Procurar o local para inserir novo nó
        Elem *ant, *atual = *li;

        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }    

        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }

        return 1;
    }
}

int remove_lista_inicio(Lista *li){
    if(li == NULL){
        return 0;
    }

    if(*li == NULL){ //Lista Vazia 
        return 0;
    }

    Elem *no = *li;
    *li = no->prox;
    free(no);

    return 1;
}

int remove_lista_final(Lista *li){
    if(li == NULL){
        return 0;
    }

    if(*li == NULL){
        return 0;
    }

    Elem *ant, *no = *li;

    while (no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li)){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }

    free(no);
    
    return 1;
}