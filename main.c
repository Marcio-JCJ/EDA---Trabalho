#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"
#include <string.h>

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
    int a = *(int*)info1, b= *(int*)info2;
    return a==b;
}

void copia(void *info, Lista *l, int tamanho){
    memcpy(info, l, tamanho);
}

int main (){
	Lista l;
	inicializa_lista(&l, sizeof(int));
	int i=12;
	insere_inicio(&l, &i);
	void *batata;
	copia(batata, &l, sizeof(Lista));
	//memcpy(batata, &l, sizeof(Lista));
	Lista *lis=(Lista*)batata;
	printf("%d", *(int*)lis->cabeca->info);
    Conjuntos conj;
    int repre1 = 1, repre2=2, repre3=3 ,repre11 = 11, repre12=12, repre13=13;
    inicializaConjuntos(&conj, sizeof(int));
    cria_conjunto(&conj, &repre1, compara_int);
    cria_conjunto(&conj, &repre2, compara_int);
    cria_conjunto(&conj, &repre3, compara_int);
    cria_conjunto(&conj, &repre13, compara_int);
    cria_conjunto(&conj, &repre12, compara_int);
    cria_conjunto(&conj, &repre11, compara_int);
    uniao(&conj, &repre1, &repre2, compara_int);
    //uniao(&conj, &repre1, &repre3, compara_int);
    //insereNoConjunto(&conj, &repre11, compara_int, 0);
    //insereNoConjunto(&conj, &repre12, compara_int, 1);
    mostra_conjuntos(&conj, mostra_int);
}