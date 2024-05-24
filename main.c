#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib/Grafo.h"
#include "lib/Pilha.h"
#include "lib/Fila.h"

#define N 7

int int_ver( char c );
char alt_min( char c );

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");
	
	Grafo g;
	carrega_grafo( "lib/entrada.txt", &g );
	
	char ini, fim;
	
	printf("\n Insira o Vértice Inicial ( A - G ): ");
	scanf(" %c", &ini);
	while(!int_ver( ini )) {
		system("CLS");
		printf("\n Valor Inválido! Insira o Vértice Inicial ( A - G ): ");
		scanf(" %c", &ini);
	}
	if( ini>=97 && ini<=103 ) {
		ini -= 32;
	}
	
	system("CLS");
	printf("\n Insira o Vértice Final ( A - G ): ");
	scanf(" %c", &fim);
	while(!int_ver( fim )) {
		system("CLS");
		printf("\n Valor Inválido! Insira o Vértice Final ( A - G ): ");
		scanf(" %c", &fim);
	}
	if( fim>=97 && fim<=103 ) {
		fim -= 32;
	}
	
	system("CLS");
	int vs[N] = { 0 };
	char va[N];
	Fila f;
	inicializa_fila( &f, N );
	
	vs[ini-65] = 1;
	inserir( &f, ini );
	int i, achou = 0;
	char x;
	while( !fila_vazia( f ) && !achou ) {
		remover( &f, &x );
		if( x == fim ) {
			achou = 1;
		} else {
			for( i=0; i<N; i++) {
				if( g.dados[x-65][i] == 1 ) {
					if( vs[i] == 0 ) {
						vs[i] = 1;
						va[i] = x;
						inserir( &f, i+65 );
					}
				}
			}
		}
	}
	
	Pilha p;
	if( achou ) {
		inicializa_pilha( &p, N );
		while( x != 0 ) {
			empilha( &p, x );
			x = va[x-65];
		}
		printf("\n Caminho Mais Rápido de %c a %c:\n\n ", ini, fim);
		while( !pilha_vazia( p ) ) {
			desempilha( &p, &x );
			if( int_ver( x ) ) {
				printf("%c", x);
				if(!pilha_vazia( p )) {
					printf(" -> ");
				}
			}
		}
		printf("\n");
	} else {
		printf("\n %c NÃO é Alcançável a Partir de A!\n");
	}
	
	desaloca_grafo( &g );
	
	return 0;
}

int int_ver( char c ) {
	if( c<65 || ( c>71 && c<97 ) || c>103 ) {
		return 0;
	}
	return 1;
}
