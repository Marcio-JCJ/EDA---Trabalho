
//Definicao das constantes (mensagens de ERRO)
#define ERRO_LISTA_VAZIA -1;	
#define ERRO_FALTA_DE_MEMORIA -2;


//Definicao da struct elemento da lista
typedef struct elemento{
	void *info;
	struct elemento *proximo;
}Elemento;

//Define struct cabecalho de lista
typedef struct{
	int tamanho_info;
	Elemento *cabeca;
}Lista;

//Define struct conjunto 
typedef struct{
	Lista multi;
	int tamanho_info;
}Conjuntos;


void inicializa_lista (Lista *l, int tamanho);
int lista_vazia (Lista l);
int insere_inicio (Lista *l, void *info);
int remove_inicio (Lista *l, void *info);
int insere_fim (Lista *l, void *info);
int remove_fim (Lista *l, void *info);
void mostra_lista (Lista l, void (*mostra_info)(void*));

void inicializa_conjuntos (Conjuntos *c, int x);
int cria_conjunto (Conjuntos c, void *representante, int (*comp)(void*, void*));
int uniao (Conjuntos c, void* rep1, void* rep2, int (*comp)(void*, void*));
void mostra_conjuntos (Conjuntos c, void (mostra)(void));
