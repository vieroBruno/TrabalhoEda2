#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct{
	int *dados;		// dados da fila
	int inicio;		// �ndice do in�cio da fila
	int n;			// qtd. de elementos da fila
	int capacidade; // capacidade do vetor 'dados'
} Fila;

void inicializa_fila( Fila *p, int c );
int fila_vazia( Fila f );
int fila_cheia( Fila f );
int inserir_fila( Fila *p, char info );
int remover_fila( Fila *p, char *info );
void mostra_fila( Fila f );
void desaloca_fila( Fila *p );

