#ifndef LISTAS_H
#define LISTAS_H
//Definicao das constantes (mensagens de ERRO)
#define ERRO_LISTA_VAZIA -1;
#define ERRO_FALTA_DE_MEMORIA -2;


//Definicao da struct elemento da lista
typedef struct Elemento{
    void *info;
    struct Elemento *proximo;
}Elemento;

//Define struct cabecalho de lista
typedef struct Lista{
    int tamanho_info;
    Elemento *cabeca;
    int qtd;
}Lista;

void inicializa_lista (Lista *l, int tamanho);
int lista_vazia (Lista l);
int insere_inicio (Lista *l, void *info);
int remove_inicio (Lista *l, void *info);
int insere_fim (Lista *l, void *info);
int remove_fim (Lista *l, void *info);
void mostra_lista (Lista l, void (*mostra_info)(void*));
int posicaoDoElemento(Lista *l, void *info, int(*comp)(void *, void*));
int leNaPos(Lista *l, void *info, int pos);
int removeDoInicio(Lista *l, void *info);
int removeDoFim(Lista *l, void *info);
int removeDaPos(Lista *l, void *info, int pos);
void esvaziaLista(Lista *l);
void desalocaElementosLista(Elemento *e);

#endif