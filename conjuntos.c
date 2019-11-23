#include <stddef.h>
#include <stdio.h>
#include "listas.h"
#include "conjuntos.h"

void inicializaConjuntos(Conjuntos *p, int x){
    Lista lista;
    inicializa_lista(&lista, sizeof(Lista));
    p->multi=lista;
    p->tamanho_info=x;
}

int cria_conjunto (Conjuntos *c, void *representante, int (*comp)(void*, void*)){
    if(!lista_vazia(c->multi)){
        if(conjuntosPossuemElemento(c, representante, comp ) == -1)
            return -1;
    }
    Lista l;
    inicializa_lista(&l, c->tamanho_info);
    return insere_fim(&c->multi, &l);
}

int uniao(Conjuntos *c, void* rep1, void* rep2, int(*comp)(void*,void*)){
    int posRep1 = -1, posRep2 = -1;
    if(!lista_vazia(c->multi)){
        Elemento* subListas= c->multi.cabeca;
        for(int i=0; i< c->multi.qtd; i++){
            if(comp(subListas->info, rep1))
                posRep1 = i;
            if(comp(subListas->info, rep2))
                posRep2 = i;
        }
        if(posRep1 >= 0 && posRep2 >= 0){
            Lista *subLista1, *subLista2;
            leNaPos(&c->multi, subLista1, c->tamanho_info);
            leNaPos(&c->multi, subLista2, c->tamanho_info);
            Elemento *e = subLista1->cabeca;
            while(e->proximo!=NULL){
                e=e->proximo;
            }
            e->proximo=subLista2->cabeca;
            subLista1->qtd+=subLista2->qtd;
            void *info;
            return removeDaPos(&c->multi, info, posRep2);
        }
    }
    return 0;
}

void mostra_conjuntos(Conjuntos *c, void(mostra)(void*)){
    if(lista_vazia(c->multi))
        return;
    Elemento *e=c->multi.cabeca;
    while(e!=NULL){
        mostra_lista(*(Lista*)e->info, mostra);
        e=e->proximo;
    }
}

int insereNoConjunto(Conjuntos *c, void *info, int(*comp)(void*, void*), int pos){
    if(lista_vazia(c->multi) || pos >= c->multi.qtd)
        return ERRO_LISTA_VAZIA;
    if(conjuntosPossuemElemento(c, info, comp)== -1)
        return ERRO_LISTA_VAZIA;
    Lista *subListaPos;
    leNaPos(&c->multi, subListaPos, pos);
    insere_fim(subListaPos, info);
}

int conjuntosPossuemElemento(Conjuntos *c, void *info, int(*comp)(void*, void*)){
    Elemento* subListas = c->multi.cabeca;
    while(subListas!=NULL){
        if(posicaoDoElemento(subListas->info, info, comp)!=-1){
            printf("Conjuntos já possuem o elemento!\n");
            return ERRO_LISTA_VAZIA;
        }
        subListas=subListas->proximo;
    }
    return 1;
}