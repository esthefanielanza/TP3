#ifndef PARALELA_H
#define PARALELA_H

#include <pthread.h>
#include "leitura.h"
#include "resolucao.h"


/*---------------------------------------------------------------------------------------------
Protótipo: pthread_t *inicializaThreads(int nThreads);
Função: Aloca memória para um vetor de threads;
Entrada: O número de Threads;
Saída: O vetor de pthreads;
---------------------------------------------------------------------------------------------*/
pthread_t *inicializaThreads(int nThreads);

/*---------------------------------------------------------------------------------------------
Protótipo: Parametro* criaParametros(int nThreads, int nLinhasPorThread, TMatriz *mapa);
Função: Cria um vetor de parametros para serem utilizados ao criar novas threads;
Entrada: O número de threads, o número de linhas por thread e o mapa;
Saída: Retorna o vetor com parametros;
---------------------------------------------------------------------------------------------*/
Parametro* criaParametros(int nThreads, int nLinhasPorThread, TMatriz *mapa);

/*---------------------------------------------------------------------------------------------
Protótipo: Parametro *criaThreads(int nThreads, TMatriz *mapa, pthread_t *threads);
Função: Cria as threads e as inicializa para calcular os máximos das linhas;
Entrada: O número de threads, o mapa e o vetor de threads;
Saída: O vetor com os parametros para ser desalocado posteriormente;
---------------------------------------------------------------------------------------------*/
Parametro *criaThreads(int nThreads, TMatriz *mapa, pthread_t *threads);

#endif