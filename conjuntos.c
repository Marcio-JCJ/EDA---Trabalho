#include <stddef.h>
#include <stdio.h>
#include "listas.h"
#include "stdlib.h"
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
    insere_inicio(&l, representante);
    insere_fim(&c->multi, &l);
}

int uniao(Conjuntos *c, void* rep1, void* rep2, int(*comp)(void*,void*)){
    int posRep1 = -1, posRep2 = -1;
    if(!lista_vazia(c->multi)){
        Elemento *e= c->multi.cabeca;
        for(int i=0; i<c->multi.qtd; i++){
            Lista *sub = (Lista*)e->info;
            if(comp(sub->cabeca->info, rep1)){
                posRep1 = i;
            }else if(comp(sub->cabeca->info, rep2)){
                posRep2 = i;
            }
            e=e->proximo;
        }
        if(posRep1 >= 0 && posRep2 >= 0){
            Lista *subLista1 = malloc(sizeof(Lista*));
            Lista *subLista2 = malloc(sizeof(Lista*));
            leNaPos(&c->multi, subLista1, posRep1);
            leNaPos(&c->multi, subLista2, posRep2);
            Elemento *e = subLista1->cabeca;
            while(e->proximo!=NULL){
                e=e->proximo;
            }
            e->proximo=subLista2->cabeca;
            subLista1->qtd+=subLista2->qtd;
            void *info;
            free(subLista1);
            free(subLista2);
            removeDaPos(&c->multi, info, posRep2);
            free (info);
            return 1;
        }
    }

    return 0;
}

void mostra_conjuntos(Conjuntos *c, void(mostra)(void*)){
    if(lista_vazia(c->multi))
        return;
    Elemento *e=c->multi.cabeca;
    int i=1;
    while(e!=NULL){
        Lista *l = e->info;
        printf("Conjunto %d:",i);
        mostra_lista(*l, mostra);
        i++;
        printf("\n");
        e=e->proximo;
    }
}

int insereNoConjunto(Conjuntos *c, void *info, int(*comp)(void*, void*), int pos){
    if(lista_vazia(c->multi) || pos >= c->multi.qtd)
        return ERRO_LISTA_VAZIA;
    if(conjuntosPossuemElemento(c, info, comp)== -1)
        return ERRO_LISTA_VAZIA;
    void *subListaPos=malloc((sizeof(Lista*)));
    leNaPos(&c->multi, subListaPos, pos);
    insere_fim((Lista*)subListaPos, info);
    free(subListaPos);
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

int removeConjunto(Conjuntos *c, int pos){
    if(lista_vazia(c->multi) || pos >= c->multi.qtd || pos < 0)
        return -1;
    Elemento *e = c->multi.cabeca;
    for(int i=0; i<pos; i++)
        e = e->proximo;
    desalocaElementosSubLista(e);
    Lista *voido = malloc(sizeof(Lista*));
    removeDaPos(&c->multi, voido, pos);
    free(voido);
}

void limpaConjuntos(Conjuntos *c){
    if(lista_vazia(c->multi))
        return;
    desalocaSubListas(c->multi.cabeca);

}

void desalocaSubListas(Elemento *e){
    if(e->proximo!=NULL) {
        desalocaSubListas(e->proximo);
    }
    Elemento *e1 = ((Lista*)e->info)->cabeca;
    desalocaElementosLista(e1);
    free(e->info);
    free(e);
}

void desalocaElementosSubLista(Elemento *e){
    if(e->proximo!=NULL) {
        desalocaElementosSubLista(e->proximo);
    }
}