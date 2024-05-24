#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2

typedef struct {
	int *dados;
	int topo, capacidade;
} Pilha;

void inicializa_pilha( Pilha *p, int c );
int pilha_vazia( Pilha p );
int pilha_cheia( Pilha p );
int empilha(Pilha *p, char info );
int desempilha( Pilha *p, char *info );
int le_topo( Pilha p, char *info );
void mostra_pilha( Pilha p );
void desaloca_pilha( Pilha *p );

