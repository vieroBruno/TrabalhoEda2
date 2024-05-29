#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib/Grafo.h"
#include "lib/Pilha.h"
#include "lib/Fila.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
	Grafo g;
	carrega_grafo( "entrada.txt", &g );
	
	int ini, fim, n = g.lin;
	
	printf("\n Insira o Vértice Inicial ( 1 - %d ): ", n);
	scanf("%d", &ini);
	while( ini < 1 || ini > n ) {
		system("CLS");
		printf("\n Valor Inválido! Insira o Vértice Inicial ( 1 - %d ): ", n);
		scanf("%d", &ini);
	}
	
	system("CLS");
	printf("\n Insira o Vértice Final ( 1 - %d ): ", n);
	scanf("%d", &fim);
	while( fim < 1 || fim > n ) {
		system("CLS");
		printf("\n Valor Inválido! Insira o Vértice Final ( 1 - %d ): ", n);
		scanf("%d", &fim);
	}
	
	system("CLS");
	int vs[n], va[n], i;
	for( i=0; i<n; i++ ) {
		vs[i] = 0;
		va[i] = -1;
	}
	Fila f;
	inicializa_fila( &f, n );
	
	vs[ini-1] = 1;
	inserir( &f, ini );
	int x, achou = 0;
	while( !fila_vazia( f ) && !achou ) {
		remover( &f, &x );
		if( x == fim ) {
			achou = 1;
		} else {
			for( i=0; i<n; i++) {
				if( g.dados[x-1][i] == 1 && vs[i] == 0 ) {
					vs[i] = 1;
					va[i] = x;
					inserir( &f, i+1 );
				}
			}
		}
	}
	
	Pilha p;
	if( achou ) {
		inicializa_pilha( &p, n );
		while( x != -1 ) {
			empilha( &p, x );
			x = va[x-1];
		}
		printf("\n Caminho Mais Rápido de %d a %d:\n\n ", ini, fim);
		while( !pilha_vazia( p ) ) {
			desempilha( &p, &x );
			printf("%d", x);
			if(!pilha_vazia( p )) {
				printf(" -> ");
			}
		}
		printf("\n");
	} else {
		printf("\n %d NÃO é Alcançável a Partir de %d!\n", fim, ini);
	}
	
	desaloca_grafo( &g );
	
	return 0;
}
