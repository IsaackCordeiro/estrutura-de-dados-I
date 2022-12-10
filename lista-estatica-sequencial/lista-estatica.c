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
    int tamLista, op;
    int mat, result;
    int pos, resConsult;
    
    // Criando struct al1
    struct aluno al1, al2, al3;

    do{
        printf("\n========== LISTA SEQUENCIAL ESTATICA ==============\n");
        printf("1 -> Criar lista\n");
        printf("2 -> Ver tamanho da lista\n");
        printf("3 -> Verifica se a lista esta vazia\n");
        printf("4 -> Insere no inicio da lista\n");
        printf("5 -> Insere no fim da lista\n");
        printf("6 -> Insere ordenado na lista\n");
        printf("7 -> Remove no do inicio da lista\n");
        printf("8 -> Remove no do final da lista\n");
        printf("9 -> Remove no do meio da lista\n");
        printf("10 -> Consultar lista em uma posicao\n");
        printf("11 -> Imprimir lista\n");
        printf("12 -> Libera lista\n");
        printf("0 -> Sair do programa\n");
        printf("==========================================================\n");
        
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);   

    
        switch (op){
            case 1:
                li = cria_lista();
                printf("Lista criada!!\n");
                break;
            case 2:
                printf("Tamanho da lista: %d\n", tamanho_lista(li));
                break;
            case 3:
                printf("Lista esta vazia? %d\n", lista_vazia(li));
                break;
            case 4:
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

                insere_lista_inicio(li, al1);
                break;
            case 5:
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

                insere_lista_final(li, al1);            
                break;
            case 6:
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

                insere_lista_ordenada(li, al1);
                break;
            case 7:
                remove_lista_inicio(li);
                printf("Item removido do inicio da lista!!\n");
                break;
            case 8:
                remove_lista_final(li);
                printf("Item removido do final da lista");
                break;
            case 9:
                printf("Digite a matricula que quer remover: ");
                scanf("%d", &mat);
                result = remove_lista_meio(li, mat);
                if(result == 1){
                    printf("Voce removeu a pessoa de matricula %d\n", mat);
                }else{
                    printf("Nao foi possivel remover\n");
                }
            case 10:
                printf("Digite a posicao que quer consultar: ");
                scanf("%d", &pos);
                
                resConsult = consulta_lista_pos(li, pos, &al2);

                if(resConsult == 1){
                    printf("\n====== IMPRIMINDO DADOS POSICAO %d ======\n", pos);
                    printf("Nome: %s\n", al2.nome);
                    printf("Matricula: %d\n", al2.matricula);
                    printf("Nota da prova 1: %.2f\n", al2.nota1);
                    printf("Nota da prova 2: %.2f\n", al2.nota2);
                    printf("Nota da prova 3: %.2f\n", al2.nota3);
                }else{
                    printf("Posicao invalida\n");
                }
                break;
            case 11:
                imprime_lista(li);
                break;
            case 12:
                libera_lista(li);
                printf("Lista liberada!!\n");
                break;
            case 0:
                printf("Voce saiu do programa...\n");
                break;
            default:
                printf("ERROR! Numero nao encontrado!!! \n\n");
                break;
        }
    } while (op != 0);
    

    // li = cria_lista();

    // Recebendo valores para al1
    // printf("Informe a matricula: ");
    // scanf("%d", &al1.matricula);

    // printf("Informe o nome: ");
    // scanf("%s", &al1.nome);

    // printf("Informe a nota 1: ");
    // scanf("%f", &al1.nota1);

    // printf("Informe a nota 2: ");
    // scanf("%f", &al1.nota2);

    // printf("Informe a nota 3: ");
    // scanf("%f", &al1.nota3);


    // // Inserindo ordenado na lista
    // int res_li = insere_lista_ordenada(li, al1);

    // printf("Inseriu? %d\n", res_li);
    
    // printf("Informa a posicao de consulta: ");
    // int pos, res;
    // scanf("%d", &pos);

    // res = consulta_lista_pos(li, pos, al2);

    // if(res == 1){
    //     printf("Nome: %s\n", al2->nome);
    //     printf("Matricula: %d\n", al2->matricula);
    //     printf("Nota 1: %.2f\n", al2->nota1);
    // }else{
    //     printf("Posicao invalida\n");
    // } 

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
    
    // int resposta = lista_vazia(li);

    

    // printf("Lista vazia: %d\n", resposta);

    // imprime_lista(li);

    // //Liberando lista
    // libera_lista(li);

    return 0;
}