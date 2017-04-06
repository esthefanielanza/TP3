#include "paralela.h"

pthread_t *inicializaThreads(int nThreads){

	pthread_t *threads;
	threads = malloc(nThreads * sizeof(pthread_t));

	return threads;
}

Parametro* criaParametros(int nThreads, int nLinhasPorThread, TMatriz *mapa){

	Parametro *arg;
	int i, linhasRestantes;
	arg = malloc(nThreads*sizeof(Parametro));
	
	//Número total de linhas no mapa//
	linhasRestantes = mapa->x;

	//O primeiro processador sempre começa a processar a partir da linha zero//
	arg[0].start = 0;

	for(i = 0; i < nThreads; i++){
		
		//Flag para identificar quando temos mais threads do que linhas//
		if(linhasRestantes <= 0)
			arg[i].start = -1;
		
		else{

			//O próximo processardor começa apartir da ultima linha do anterior//
			if(i != 0)
				arg[i].start = arg[i-1].end;
			
			//Caso o número de linhas não seja divisível o último processador fica
			//com as linhas restantes
			if(nThreads - 1 == i && linhasRestantes > nLinhasPorThread)
				arg[i].end = arg[i].start + linhasRestantes;

			//Cada processador deve pegar as nLinhas calculas anteriormente//
			else
				arg[i].end = arg[i].start + nLinhasPorThread;
			
			arg[i].mapa = mapa;
		}

		//Diminuímos o nº de linhas restantes//
		linhasRestantes = linhasRestantes - nLinhasPorThread;
	}
	
	return arg;
}

Parametro *criaThreads(int nThreads, TMatriz *mapa, pthread_t *threads){
	
	int i, nLinhasPorThread;
	Parametro *arg;
	int error;

	nLinhasPorThread = (int)(mapa->x/nThreads);

	//Caso o número de linhas seja menor que o número de threads 
	//fixamos o nLinhasPorThread como 1
	if(nLinhasPorThread < 1)
		nLinhasPorThread = 1;

	arg = criaParametros(nThreads, nLinhasPorThread, mapa);

	for(i = 0; i < nThreads; i++){
		
		//Se for uma thread válida//		
		if(arg[i].start != -1){
			error = pthread_create(&(threads[i]), NULL, calculaSolucaoLinha, (void *)&(arg[i]));
			if(error){ printf("Erro ao criar pthread %d", i); exit(EXIT_FAILURE);}
		}

		else
			break;
	}

	return arg;
}