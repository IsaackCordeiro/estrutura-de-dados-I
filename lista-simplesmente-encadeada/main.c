#include <stdio.h>
#include <stdlib.h>
#include "listaDinEncad.h"

int main(){
    Lista *li;

    struct aluno al2;

    int op;
    do{
        printf("\n========== LISTA DINAMICAMENTE ENCADEADA ==============\n");
        printf("1 -> Criar lista\n");
        printf("2 -> Ver tamanho da lista\n");
        printf("3 -> Verifica se a lista esta vazia\n");
        printf("4 -> Insere no inicio da lista\n");
        printf("5 -> Insere no fim da lista\n");
        printf("6 -> Insere ordenado na lista\n");
        printf("7 -> Remove no do inicio da lista\n");
        printf("8 -> Remove no do final da lista\n");
        printf("9 -> Remove no do meio da lista\n");
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
                scanf("%d", &al2.matricula);

                printf("Informe o nome: ");
                scanf("%s", &al2.nome);

                printf("Informe a nota 1: ");
                scanf("%f", &al2.nota1);

                printf("Informe a nota 2: ");
                scanf("%f", &al2.nota2);

                printf("Informe a nota 3: ");
                scanf("%f", &al2.nota3);

                insere_lista_inicio(li, al2);
                break;
            case 5:
                printf("Informe a matricula: ");
                scanf("%d", &al2.matricula);

                printf("Informe o nome: ");
                scanf("%s", &al2.nome);

                printf("Informe a nota 1: ");
                scanf("%f", &al2.nota1);

                printf("Informe a nota 2: ");
                scanf("%f", &al2.nota2);

                printf("Informe a nota 3: ");
                scanf("%f", &al2.nota3);

                insere_lista_final(li, al2);            
                break;
            case 6:
                printf("Informe a matricula: ");
                scanf("%d", &al2.matricula);

                printf("Informe o nome: ");
                scanf("%s", &al2.nome);

                printf("Informe a nota 1: ");
                scanf("%f", &al2.nota1);

                printf("Informe a nota 2: ");
                scanf("%f", &al2.nota2);

                printf("Informe a nota 3: ");
                scanf("%f", &al2.nota3);

                insere_lista_ordenado(li, al2);
                break;
            case 7:
                remove_lista_inicio(li);
                printf("Item removido do inicio da lista!!\n");
                break;
            case 8:
                remove_lista_final(li);
                printf("Item removido do final da lista");
                break;
            case 12:
                libera_lista(li);
                printf("Lista liberada!!\n");
                break;
            case 0:
                printf("Você saiu do programa...\n");
                break;
            default:
                printf("ERROR! Numero nao encontrado!!! \n\n");
                break;
        }
    } while (op != 0);
    
    
    return 0;
}