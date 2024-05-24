#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib/Grafo.h"
#include "lib/Pilha.h"

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
	int status[N] = { 0 }, ant[N] = { 0 };
		
	desaloca_grafo( &g );
	
	return 0;
}

int int_ver( char c ) {
	if( c<65 || ( c>71 && c<97 ) || c>103 ) {
		return 0;
	}
	return 1;
}
