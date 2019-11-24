#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

void inicializa_lista (Lista *l, int tamanho){
    l->tamanho_info = tamanho;
    l->cabeca = NULL;
    l->qtd=0;
}

int lista_vazia (Lista l){
    return l.cabeca == NULL;
}

int insere_inicio (Lista *l, void *info){
    Elemento *novo = malloc(sizeof(Elemento));
    if(novo == NULL)
        return ERRO_FALTA_DE_MEMORIA; //ERRO, falta de memoria!

    novo->info = malloc(l->tamanho_info);
    if(novo->info == NULL){
        free(novo);
        return ERRO_FALTA_DE_MEMORIA;
    }

    memcpy(novo->info, info, l->tamanho_info);
    novo->proximo = l->cabeca;
    l->cabeca = novo;
    l->qtd++;
    return 1; //Sucesso
}

int remove_inicio (Lista *l, void *info){
    if(lista_vazia(*l))
        return ERRO_LISTA_VAZIA;

    Elemento *p = l->cabeca;
    memcpy(info, p->info, l->tamanho_info);
    free(p->info);
    l->cabeca = p->proximo;
    free(p);
    l->qtd--;
    return 1; //Sucesso
}

int insere_fim(Lista *l, void *info){
    if(lista_vazia(*l))
        return insere_inicio(l, info);
    Elemento *novo=(Elemento *) malloc(sizeof(Elemento));
    if(novo==NULL)
        return 0;
    novo->info=malloc(l->tamanho_info);
    if(novo->info==NULL){
        free(novo);
        return 0;
    }
    Elemento *p = l->cabeca;
    while(p->proximo != NULL){
        p=p->proximo;
    }
    memcpy(novo->info, info, l->tamanho_info);
    novo->proximo=NULL;
    p->proximo=novo;
    l->qtd++;
    return 1;
}

int remove_fim (Lista *l, void *info){
    if (lista_vazia(*l))
        return ERRO_LISTA_VAZIA;

    if (l->cabeca->proximo == NULL) //Lista contem apenas um elemento
        return remove_inicio (l, info);

    Elemento *p = l->cabeca;
    while(p->proximo->proximo != NULL){
        p = p->proximo;
    }

    Elemento *ultimo = p->proximo;
    memcpy(info, ultimo->info, l->tamanho_info);
    free(ultimo->info);
    free(ultimo);
    p->proximo = NULL;
    l->qtd--;
    return 1; //Sucesso
}

void mostra_lista (Lista l, void (*mostra_info)(void*)){
    if(lista_vazia(l))
        printf("Lista vazia!\n");
    else{
        Elemento *p = l.cabeca;
        while(p != NULL){
            mostra_info(p->info); //Invocacao por callback
            p = p->proximo;
        }
    }
}

int posicaoDoElemento(Lista *l, void *info, int(*comp)(void *, void*)){
    if(lista_vazia(*l)){
        printf("Lista vazia!\n");
        return -2;
    }
    int pos=0;
    Elemento *e=l->cabeca;
    while(e!=NULL){
        if(comp(info,e->info))
            return pos;
        pos++;
        e=e->proximo;
    }
    return -1;
}

int leNaPos(Lista *l, void *info, int pos){
    if(pos < 0 || pos >= l->qtd) {
        printf("Posição não existe!\n");
        return 1 == 0;
    }
    Elemento *e = l->cabeca;
    for(int i=0; i<pos; i++)
        e=e->proximo;

    memcpy(info, e->info, l->tamanho_info);

    return 1;
}

int removeDaPos(Lista *l, void *info, int pos){
    if(pos<0 || pos>=l->qtd || lista_vazia(*l))
        return ERRO_LISTA_VAZIA;
    if(pos==0)
        return removeDoInicio(l, info);
    if(pos==l->qtd-1)
        return removeDoFim(l, info);
    Elemento *p=l->cabeca;
    for(int i=0; i<pos-1; i++){
        p=p->proximo;
    }
    Elemento *removido=p->proximo;
    p->proximo=p->proximo->proximo;
    memcpy(info, removido->info, l->tamanho_info);
    free(removido->info);
    free(removido);
    l->qtd--;
    return 1;
}

int removeDoInicio(Lista *l, void *info){
    if(lista_vazia(*l))
        return ERRO_LISTA_VAZIA;
    Elemento *p = l->cabeca;
    memcpy(info, p->info, l->tamanho_info);
    free(p->info);
    l->cabeca=p->proximo;
    free(p);
    l->qtd--;
    return 1;
}

int removeDoFim(Lista *l, void *info) {
    if(lista_vazia(*l))
        return ERRO_LISTA_VAZIA;
    if(l->cabeca->proximo==NULL)
        return removeDoInicio(l, info);
    Elemento *p=l->cabeca;
    while(p->proximo->proximo!=NULL){
        p=p->proximo;
    }
    Elemento *ultimo=p->proximo;
    memcpy(info, ultimo->info, l->tamanho_info);
    free(ultimo->info);
    free(ultimo);
    p->proximo=NULL;
    l->qtd--;
    return 1;
}

void esvaziaLista(Lista *l){
    if(!lista_vazia(*l))
        desalocaElementosLista(l->cabeca);
    free(l);
}

void desalocaElementosLista(Elemento *e){
    if(e->proximo!=NULL) {
        desalocaElementosLista(e->proximo);
    }
    free(e->info);
    free(e);
}