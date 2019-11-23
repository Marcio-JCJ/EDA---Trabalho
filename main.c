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

int compara_int(void *info1, void *info2){
    int *a = info1, *b= info2;
    return *a==*b;
}

int main (){
    printf("Tainha Vinho e muito...");
    return 0;
}