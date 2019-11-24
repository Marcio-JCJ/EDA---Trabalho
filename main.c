#include <stdio.h>
#include "conjuntos.h"

void mostra_float (void *info){ //Mostra um dado float a partir de um ponteiro void
    float *p = (float*)info;
    printf("%.2f\n", *p);
}

void mostra_int (void *info){ //Mostra um dado int a partir de um ponteiro void
    int *p = (int*)info;
    printf("%d ", *p);
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
    int repre1 = 1, repre2=2, repre3=3 ,repre11 = 11, repre12=12, repre13=13;
    inicializaConjuntos(&conj, sizeof(int));
    cria_conjunto(&conj, &repre1, inteiroIgual);
    cria_conjunto(&conj, &repre2, inteiroIgual);
    cria_conjunto(&conj, &repre3, inteiroIgual);
    cria_conjunto(&conj, &repre13, inteiroIgual);
    printf("====================================\n");
    mostra_conjuntos(&conj, mostra_int);
    //cria_conjunto(&conj, &repre12, inteiroIgual);
    //cria_conjunto(&conj, &repre11, inteiroIgual);
    printf("====================================\n");
    uniao(&conj, &repre1, &repre2, inteiroIgual);
    mostra_conjuntos(&conj, mostra_int);
    printf("====================================\n");
    uniao(&conj, &repre1, &repre3, inteiroIgual);
    mostra_conjuntos(&conj, mostra_int);
    printf("====================================\n");
    insereNoConjunto(&conj, &repre11, inteiroIgual, 0);
    mostra_conjuntos(&conj, mostra_int);
    printf("====================================\n");
    insereNoConjunto(&conj, &repre12, inteiroIgual, 1);
    mostra_conjuntos(&conj, mostra_int);
    printf("====================================\n");
    removeConjunto(&conj, 1);
    mostra_conjuntos(&conj, mostra_int);
    printf("====================================\n");
    limpaConjuntos(&conj);
    mostra_conjuntos(&conj, mostra_int);
}