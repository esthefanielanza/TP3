#include "resolucao.h"

int calculaMax(int a, int b){
	
	if(a > b)
		return a;
	else
		return b;
}

void resolveProblema(TMatriz *mapa, int nThreads, pthread_t *threads){
	
	int *vetorSolucao;
	int i, solucao;
	Parametro *arg;

	arg = criaThreads(nThreads, mapa, threads);

	//Espera que as threads terminem//
	for(i = 0; i < nThreads; i++){
		//Se forem threads válidas//
		if(arg[i].start != -1)
			pthread_join(threads[i], NULL);
		else
			break; 
	}

	//Como já terminou de ser utilizado liberamos o 
	//espaço utilizado para o vetor de parametros//
	free(arg);
	
	//Para imprimir os máximos de cada linha//
	//printf("\nSoluções para filas\n");
	//imprimeMapa(*mapa);
	
	//Calcula solução usando a coluna que guarda os máximos
	//das linhas
	vetorSolucao = criaVetorSolucoes(*mapa);
	solucao = calculaSolucao(vetorSolucao, mapa->x + 2);
	printf("%d\n", solucao);

	free(vetorSolucao);

}

void *calculaSolucaoLinha(void *arg){

	int j, i;
	Parametro p = *(Parametro *)arg;

	//printf("Começou a Thread %d %d\n", p.start, p.end);

	for(i = p.start; i < p.end; i++){
		for(j = 2; j < p.mapa->y; j++){
			p.mapa->m[i][j] = calculaMax(p.mapa->m[i][j-1], p.mapa->m[i][j] + p.mapa->m[i][j-2]);
		}
	}

	//printf("Terminou a Thread %d %d\n", p.start, p.end);
	//pthread_exit((void *)NULL);
	return(NULL); 
}

int* criaVetorSolucoes(TMatriz mapa){

	int *vetor;
	int i;

	vetor = malloc((mapa.x + 2) * sizeof(int));

	//As duas primeiras colunas são preenchidas com zeros//
	for(i = 0; i < 2; i++)
		vetor[i] = 0;
	
	//O resto do vetor é preenchido com a última coluna//	
	for(i = 2; i < mapa.x + 2; i++)
		vetor[i] = mapa.m[i - 2][mapa.y - 1];

	return vetor;
}

int calculaSolucao(int *vetorSolucao, int tamanhoVetor){

	int i;

	for(i = 2; i < tamanhoVetor; i++){
		vetorSolucao[i] = calculaMax(vetorSolucao[i-1], vetorSolucao[i]+vetorSolucao[i-2]);
	}

	return vetorSolucao[tamanhoVetor - 1];
}