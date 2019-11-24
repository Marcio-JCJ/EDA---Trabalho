
#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"

void mostra_float (void *info){ //Mostra um dado float a partir de um ponteiro void
    float *p = (float*)info;
    printf("%.2f\n", *p);
}

void mostra_int (void *info){ //Mostra um dado int a partir de um ponteiro void
    int *p = (int*)info;
    printf("[%d]", *p);
}

void mostra_char (void *info){ //Mostra um dado char a partir de um ponteiro void
    char *p = (char*)info;
    printf("%c\n", *p);
}

int inteiroIgual(void *info1, void *info2){
    int a = *(int*)info1, b= *(int*)info2;
    return a==b;
}

int main (){
    Conjuntos conj;

    int acao = 0;
    int repre, repre2, valor, conjunto;
    char resposta;

    inicializaConjuntos(&conj, sizeof(int));
    while(acao != 7) {
        printf("==================================================================\n");
        printf("Digite o valor correspondente a interacao desejada:\n");
        printf("1- Cria Conjunto\n");
        printf("2- Insere no Conjunto\n");
        printf("3- Mostra Conjuntos\n");
        printf("4- Uniao de Conjuntos\n");
        printf("5- Remove Conjunto\n");
        printf("6- Limpa Conjuntos\n");
        printf("7- Sair do Menu\n");

        printf("Opcao:");
        scanf("%d", &acao);
        printf("==================================================================\n");

        switch (acao) {
            case 1:
                printf("Digite o representante do conjunto a ser criado:\n");
                scanf("%d", &repre);
                cria_conjunto(&conj, &repre, inteiroIgual);
                break;

            case 2:
                printf("Digite o conjunto que sera inserido o valor, e o valor a ser inserido:\n");
                printf("Conjunto:");
                scanf("%d", &conjunto);
                printf("Valor:");
                scanf("%d", &valor);
                insereNoConjunto(&conj, &valor, inteiroIgual, conjunto-1);
                break;

            case 3:
                printf("Os conjuntos sao:\n");
                mostra_conjuntos(&conj, mostra_int);
                break;

            case 4:
                printf("Digite o representante do conjunto que recebera a uniao, e o representante do conjunto que sera anexado:\n");
                printf("Os conjuntos sao:\n");
                mostra_conjuntos(&conj, mostra_int);
                printf("Representante da uniao:");
                scanf("%d", &repre);
                printf("Representante que sera anexado:");
                scanf("%d", &repre2);
                uniao(&conj, &repre, &repre2, inteiroIgual);
                break;

            case 5:
                printf("Digite o conjunto a ser removido:");
                scanf("%d", &conjunto);
                removeConjunto(&conj, conjunto-1);
                break;

            case 6:
                limpaConjuntos(&conj);
                printf("Limpeza Concluida!\n");
                printf("Deseja inicializar conjuntos(s/n)?\n");
                scanf(" %c", &resposta);
                if(resposta == 's') {
                    inicializaConjuntos(&conj, sizeof(int));
                }else{
                    acao = 7;
                }
                break;

            case 7:
                printf("Fechando programa");
                break;

            default:
                printf("Acao invalida!\n");

        }
    }

    return 0;
}