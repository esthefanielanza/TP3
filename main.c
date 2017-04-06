#include "leitura.h"
#include "resolucao.h"
#include "paralela.h"

int main (int argc, char *argv[]){

	TMatriz mapa;
	int nThreads;
	
	//Inicializa threads//
	pthread_t *threads;
	nThreads = atoi(argv[1]);
	threads = inicializaThreads(nThreads);

	//Resolução do problema//
	leituraMapa(&mapa);
	resolveProblema(&mapa, nThreads, threads);

	//Encerramento do código//
	destroiMapa(&mapa);	
	free(threads);

	(void)argc;
	return 0;	
}