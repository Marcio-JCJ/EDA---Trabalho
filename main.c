#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


void mostra_float (void *info){ //Mostra um dado float a partir de um ponteiro void
    float *p = (float*)info;
    printf("%.2f\n", *p);
}

void mostra_int (void *info){ //Mostra um dado int a partir de um ponteiro void
    int *p = (int*)info;
    printf("%d\n", *p);
}

void mostra_char (void *info){ //Mostra um dado char a partir de um ponteiro void
    char *p = (char*)info;
    printf("%c\n", *p);
}

int compara_int(void *x, void *y) {
    int *a = x, *b = y;
    if (*a > *b) return 1;
    if (*a < *b) return -1;
    return 0;
}

int main (){
    Conjuntos conj;

    inicializa_conjuntos(&conj, sizeof(char));
    int repre = 2;
    cria_conjunto(conj, &repre, compara_int);
    repre = 5;
    mostra_conjuntos(conj, mostra_int);
    /*cria_conjunto(conj, &repre, compara_int);
    uniao(conj, &repre);*/

    //printf("Tainha");
    return 0;
}

