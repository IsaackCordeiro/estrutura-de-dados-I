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
    // Cria um ponteiro de Lista
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista)); // Aloca memória para a lista

    if(li != NULL){ // Verifica se foi alocado memória corretamente
        li->qtd = 0; // Define a quantidade de nós na lista
    }

    return li;
}

void libera_lista(Lista *li){
    free(li); // Libera a lista
}


/*
    Verificar o tamanho da lista:
    1° passo: Verifica se existe
        1.1° passo: Se existe, retorna quantidade
        1.2° passo: Se não existe, retorna -1
*/
int tamanho_lista(Lista *li){
    if(li != NULL){ // LISTA EXISTE?
        return li->qtd;
    }else{
        return -1;
    }
}

int verificaListaCheia(Lista *li){
    if(li == NULL){
        return -1;
    }
    if(li->qtd == MAX){ // Verifica se a lista está cheia
        return 1;
    }else{
        return 0;
    }
}


int lista_vazia(Lista *li){
    if(li == NULL){
        return -1;
    }

    return (li->qtd == 0); // Retorna se a quantidade de nós na lista é 0
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
    li->dados[li->qtd] = al; // Insere nó na posição final da lista
    li->qtd++; // Incrementa a quantidade de nós da lista

    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(verificaListaCheia(li)){
        return 0;
    }

    // Passa todos os elementos da lista para uma posição a frente
    for(int i = li->qtd-1 ; i>=0 ; i--){
        li->dados[i+1] = li->dados[i];
    }   

    li->dados[0] = al; // Insere nó na posição inicial da lista
    li->qtd++; // Incrementa a quantidade de nós da lista

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
    // Pega a posição onde é preciso ser inserido o Nó
    while(i < li->qtd && li->dados[i].matricula < al.matricula){
        i++;
    }

    // Percorre a lista de trás para frente até a posição onde 
    // vai ser inserido, passando os Nós para uma posição a frente
    for(k = li->qtd-1 ; k >= i ; k--){
        li->dados[k+1] = li->dados[k];
    }

    li->dados[i] = al; // Insere Nó na posição que i armazena
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
    
    li->qtd--; // Decremente a quantidade de Nós na lista

    return 1;
}

int remove_lista_inicio(Lista *li){
    if(li == NULL){
        return 0;
    }
    if(lista_vazia(li)){
        return 0;
    }

    // Percorre toda a lista trazendo os item para uma posição antes
    for(int i = 0 ; i < li->qtd-1 ; i++){
        li->dados[i] = li->dados[i+1];
    }

    li->qtd--; // Decrementa a quantidade de Nós da lista

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

    // Percorre a lista até que a matricula da lista
    // seja igual a matricula passada para a função
    // i armazena essa posição.
    while(i < li->qtd && li->dados[i].matricula != mat){
        i++;
    }

    if(i == li->qtd){ // Matricula inválida
        return 0;
    }
    
    // Ex 1(b) - Ajuste a funcao de remocao em qualquer posicao para que a mesma retorne o elemento
    // removido e a posicão na qual o mesmo foi removido
    printf("Matricula do item removido: %d\n", li->dados[i].matricula);
    printf("Posicao: %d\n", i);

    // Movendo os itens uma posição atrás a partir da posição da matricula que você quer remover
    for(k = i ; k < li->qtd-1 ; k++){
        li->dados[k] = li->dados[k+1];
    }

    li->qtd--; // Decrementa a quantidade de Nós da lista

    return 1;
}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd){
        return 0;
    }

    *al = li->dados[pos-1]; // *al recebe os dados da lista na posição passada como parâmetro

    return 1;
}

//Ex 1(a):  Implemente uma funcao que imprima todos os elementos da lista.
void imprime_lista(Lista *li){
    if(li == NULL){
        printf("Lista inexistente\n");
    }
    if(lista_vazia(li)){
        printf("Lista vazia\n");
    }

    printf("\n====== IMPRIMINDO DADOS ======\n");

    for(int i = 0 ; i < li->qtd ; i++){ // Percorre a lista imprimindo os dados de cada Nó
        
        printf("\nNome: %s\n", li->dados[i].nome);
        printf("Matricula: %d\n", li->dados[i].matricula);
        printf("Nota da prova 1: %.2f\n", li->dados[i].nota1);
        printf("Nota da prova 2: %.2f\n", li->dados[i].nota2);
        printf("Nota da prova 3: %.2f\n", li->dados[i].nota3);
        printf("\n ------------------------------------- \n");
    }
}

// 1 (c) Implemente uma funcao que ordene os elementos da lista. Assuma a premissa de que os
//       elementos foram inseridos sempre no final.
int orderna_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    if(lista_vazia(li)){
        return 0;
    }
    
    struct aluno aux;

    for(int j = 0 ; j < li->qtd ; j ++){
        for(int i = 0 ; i < li->qtd ; i++){
            if(li->dados[i].matricula > li->dados[i+1].matricula && i+1 < li->qtd){
                aux = li->dados[i];
                li->dados[i] = li->dados[i+1];
                li->dados[i+1] = aux;
            }
        }
    }

    return 1;
}

// 2. Considerando listas estaticas, faca um funcao em C que verifique se a lista esta ordenada.
//    A funcao deve ainda permitir determinar o tipo de ordenacao (crescente ou decrescente).
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

// 3. Para listas estaticas, implemente uma funcao que elimine de uma determinada lista, todas as
//    ocorrencias de um dado elemento. Considere que a lista esta ordenada.

int remove_todas_ocorrencias(Lista *li, int elem){
    if(li == NULL){
        return -1;
    } else if(lista_vazia(li)){
        return -1;
    } else {
        for(int i = 0 ; i < li->qtd ; i++){
            for(int z = 0 ; z < li->qtd ; z++){
                if(li->dados[i].matricula = elem){
                    for(int j = i ; j < li->qtd-1 ; j++){
                        li->dados[j] = li->dados[j+1];
                    }
                    li->qtd--;
                }
            }
        }
        return 1;
    }
}

/*
    4. Em que circunstancias seria preferıvel utilizar a implementacao estatica ao inves da dinamica
    para listas? Cite algumas vantagens e desvantagens que podem contribuir para esta justificativa.

    É melhor usar em listas pequenas e para remoção e inserção no fim da lista
    Vantagens: as posições já são definidas com o índice i
    Desvantagens: tamanho máximo pre-definido, inexistencia de grandes espaços sequenciais na memória,
                  maior esforço computacional na inserção e remoção de nós 

*/