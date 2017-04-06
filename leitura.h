#ifndef LEITURA_H
#define LEITURA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TMatriz{
	//Matriz//
	int **m;
	//Dimensões//
	int x; int y;
} TMatriz;

/*---------------------------------------------------------------------------------------------
Protótipo: void leituraMapa(TMatriz *mapa);
Função: Lê o mapa com as populações das cidades;
Entrada: A matriz para realizar a leitura;
Saída: Não retorna nada;
---------------------------------------------------------------------------------------------*/
void leituraMapa(TMatriz *mapa);

/*---------------------------------------------------------------------------------------------
Protótipo: int **alocaMapa(int x, int y);
Função: Aloca espaço para o mapa;
Entrada: O tamanho do mapa;
Saída: Retorna uma matriz de inteiros alocada
---------------------------------------------------------------------------------------------*/
int **alocaMapa(int x, int y);

/*---------------------------------------------------------------------------------------------
Protótipo: void imprimeMapa(TMatriz mapa);
Função: Usada para debugar, imprime a matriz no stdout.
Entrada: O mapa.
Saída: Não retorna nada;
---------------------------------------------------------------------------------------------*/
void imprimeMapa(TMatriz mapa);

/*---------------------------------------------------------------------------------------------
Protótipo: void destroiMapa(TMatriz *mapa);
Função: Desaloca memória utilizada pelo mapa;
Entrada: O mapa.
Saída: Não retorna nada;
---------------------------------------------------------------------------------------------*/
void destroiMapa(TMatriz *mapa);

#endif