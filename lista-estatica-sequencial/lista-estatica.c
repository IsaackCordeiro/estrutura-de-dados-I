/*
    Lista são uma sequencia de elementos chamados nós

    Nó = parte da estrutura de dados que armazena uma informação

    Seja n a quantidade de nós de uma lista, então
    Xn -> Se n = 0 lista está vazia

    - A memória é alocada de forma sequencial

    func-lista.h recebe os protótipos das funções
    lista.c recebe os métodos
*/

#include <stdio.h>
#include <stdlib.h>
#include "func-lista.h"


int main(){
    Lista *li;
    int tamLista;

    li = cria_lista();


    // Criando struct al1
    struct aluno al1, *al2;


    // Recebendo valores para al1
    printf("Informe a matricula: ");
    scanf("%d", &al1.matricula);

    printf("Informe o nome: ");
    scanf("%s", &al1.nome);

    printf("Informe a nota 1: ");
    scanf("%f", &al1.nota1);

    printf("Informe a nota 2: ");
    scanf("%f", &al1.nota2);

    printf("Informe a nota 3: ");
    scanf("%f", &al1.nota3);


    // Inserindo ordenado na lista
    int res_li = insere_lista_ordenada(li, al1);

    printf("Inseriu? %d\n", res_li);
    
    printf("Informa a posicao de consulta: ");
    int pos, res;
    scanf("%d", &pos);

    res = consulta_lista_pos(li, pos, al2);

    if(res == 1){
        printf("Nome: %s\n", al2->nome);
        printf("Matricula: %d\n", al2->matricula);
        printf("Nota 1: %.2f\n", al2->nota1);
    }else{
        printf("Posicao invalida\n");
    } 

    // Verificando o tamanho da lista
    //tamLista = tamanho_lista(li);

    //printf("Tamanho da lista: %d\n", tamLista);
    
    // Remove nó no inicio da lista
    //remove_lista_inicio(li);

    // Verificando o tamanho da lista apos remover
    //tamLista = tamanho_lista(li);

    //printf("Tamanho da lista apos remover: %d\n", tamLista);

    //Verificando se lista está cheia
    // if(verificaListaCheia(li)){
    //     printf("Lista cheia\n");
    // }else{
    //     printf("Lista nao esta cheia\n");
    // }
    
    int resposta = lista_vazia(li);

    printf("Lista vazia: %d\n", resposta);


    //Liberando lista
    libera_lista(li);

    return 0;
}