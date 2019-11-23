#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include "listas.h"

//Define struct conjunto
typedef struct{
    Lista multi;
    int tamanho_info;
}Conjuntos;

void inicializa_conjuntos (Conjuntos *c, int x);
int cria_conjunto (Conjuntos c, void *representante, int (*comp)(void*, void*));
int uniao (Conjuntos c, void* rep1, void* rep2, int (*comp)(void*, void*));
void mostra_conjuntos (Conjuntos c, void (mostra)(void*));
int insereNoConjunto(Conjuntos c, void *info, int(*comp)(void*, void*), int pos);
int conjuntosPossuemElemento(Conjuntos c, void *info, int(*comp)(void*, void*));

#endif