#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

void inicializa_lista (Lista *l, int tamanho){
	l->tamanho_info = tamanho;
	l->cabeca = NULL;
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

	return 1; //Sucesso
}

int insere_fim (Lista *l, void *info){
	if (lista_vazia(*l))
		return insere_inicio (l, info);

	Elemento *novo = malloc(sizeof(Elemento));
	if (novo == NULL)
		return ERRO_FALTA_DE_MEMORIA; 
	
	novo->info = malloc(l->tamanho_info);
	if (novo->info = NULL){
		free(novo);
		return ERRO_FALTA_DE_MEMORIA;
	}
	Elemento *p = l->cabeca;
	while(p->proximo != NULL){
		p = p->proximo;
	}

	memcpy(novo->info, info, l->tamanho_info);
	novo->proximo = NULL;
	p->proximo = novo;

	return 1; //Sucesso
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

	return 1; //Sucesso
}

void mostra_lista (Lista l, void (*mostra_info)(void*)){
	if(lista_vazia(l))
		printf("Lista vazia!\n");
	else{
		printf("Dados da lista:\n");
		Elemento *p = l.cabeca;
		while(p != NULL){
			mostra_info(p->info); //Invocacao por callback
			p = p->proximo;
		}
	}
}

int posicaoDoElemento(Lista *l, void *info, int(*comparaInfo)(void *, void*)){
    if(lista_vazia(*l)){
        printf("Lista vazia!\n");
        return -2;
    }
    int pos=0;
    Elemento *e=l->cabeca;
    while(e!=NULL){
        if(comparaInfo(info,e->info))
            return pos;
        pos++;
        e=e->proximo;
    }
    return -1;
}

void inicializaConjuntos(Conjuntos *p, int x){
    Lista lista;
    inicializa_lista(&lista, sizeof(Lista));
    p->multi=lista;
    p->tamanho_info=x;
}

int cria_conjunto (Conjuntos c, void *representante, int (*comp)(void*, void*)){
    if(!lista_vazia(c.multi)){
        Elemento* subListas = c.multi.cabeca->info;
        while(subListas!=NULL){
            if(posicaoDoElemento(subListas->info, representante, comp)!=-1){
                return -1;
            }
            subListas=subListas->proximo;
        }
    }
    Lista *l=malloc(sizeof(Lista));
    inicializa_lista(l, c.tamanho_info);
    if(insere_inicio(l,representante)==1) {
        return insere_fim(&c.multi, l);
    }
    return -1;
}

int uniao(Conjuntos c, void* rep1, void* rep2, int(*comp)(void*,void*)){
    
}

void mostra_conjuntos(Conjuntos c, void(mostra)(void*)){
    if(lista_vazia(c.multi))
        return;
    Elemento *e=c.multi.cabeca;
    while(e!=NULL){
        mostra_lista(*(Lista*)e->info, mostra);
        e=e->proximo;
    }
}