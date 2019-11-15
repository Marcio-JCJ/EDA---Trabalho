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
/*
int CriaConjunto(Lista* list, int* n) {
	Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
	if (novo == NULL) {
		return 0;
	}
	novo->n = malloc(list->tamanhoInfo);
	if (novo->n == NULL) {
		free(novo);
		return 0;
	}
	Elemento* p = list->cabeca;
	while (p->proximo != NULL) {
		// se nao fiz nada errado ele vai checar se o elemento
		// nao e igual ao elemento que tem
		// o problema e que pode ser uma lista dentro de um lista
		if (novo->n == p->proximo) {
			return ERRO;
		}
		p = p->proximo;
	}
	memcpy(novo->n, n, list->tamanhoInfo);
	novo->proximo = list->cabeca;
	list->cabeca = novo;
	return 1; // Sucesso. } 
}
*/
