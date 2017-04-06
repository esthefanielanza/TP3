#ifndef RESOLUCAO_H
#define RESOLUCAO_H	

#include "leitura.h"

typedef struct Parametro{
	TMatriz *mapa;
	int start, end;
} Parametro;

#include "paralela.h"

/*---------------------------------------------------------------------------------------------
Protótipo: void resolveProblema(TMatriz *mapa, int nThreads, pthread_t *threads);
Função: Responsável por organizar o cálculo da execução, cria as threads e calcula a resposta
final;
Entrada: A matriz, o número de threads e o vetor de pthreads;
Saída: Não retorna nada;
---------------------------------------------------------------------------------------------*/
void resolveProblema(TMatriz *mapa, int nThreads, pthread_t *threads);

/*---------------------------------------------------------------------------------------------
Protótipo: void *calculaSolucaoLinha(void *arg);
Função: Função utilizada pelas threads, calcula a população máxima de uma linha.
Entrada: O mapa, a linha de inicio e fim;
Saída: Não retorna nada;
---------------------------------------------------------------------------------------------*/
void *calculaSolucaoLinha(void *arg);

/*---------------------------------------------------------------------------------------------
Protótipo: int* criaVetorSolucoes(TMatriz mapa);
Função: Cria um vetor para armazenar os máximos das linhas(ultima coluna da matriz)
Entrada: O mapa;
Saída: Um vetor de inteiros;
---------------------------------------------------------------------------------------------*/
int* criaVetorSolucoes(TMatriz mapa);

/*---------------------------------------------------------------------------------------------
Protótipo: int calculaSolucao(int *vetorSolucao, int tamanhoVetor);
Função: Calcula a solução final a partir do veter de soluções;
Entrada: O vetor de soluções e o seu tamanho;
Saída: Retorna a população máxima daquele mapa;
---------------------------------------------------------------------------------------------*/
int calculaSolucao(int *vetorSolucao, int tamanhoVetor);


#endif