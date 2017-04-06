#include "leitura.h"

void leituraMapa(TMatriz *mapa){

	int i, j;

	//Leitura do tamanho do mapa//
	scanf("%d %d", &mapa->x, &mapa->y);
	mapa->y += 2;

	mapa->m = alocaMapa(mapa->x, mapa->y);

	//Inicializa as duas primeiras colunas com zeros//
	for(i = 0; i < mapa->x; i++){
		for(j = 0; j < 2; j++){
			mapa->m[i][j] = 0;
		}
	}

	//Realiza a leitura do mapa//
	for(i = 0; i < mapa->x; i++){
		for(j = 2; j < mapa->y; j++){
			scanf("%d", &mapa->m[i][j]);
		}
	}
}

int **alocaMapa(int m, int n){

	int i;
	int **mapa;
	
	mapa = (int**) malloc(m * sizeof(int*));
	for(i = 0; i < m; i++)
		mapa[i] = (int*) malloc(n * sizeof(int));

	return mapa;
}

void imprimeMapa(TMatriz mapa){

	int i, j;

	printf("- Mapa -\n");
	for(i = 0; i < mapa.x; i++){
		for(j = 0; j < mapa.y; j++){
			printf("%d ", mapa.m[i][j]);
		}
		printf("\n");
	}
}

void destroiMapa(TMatriz *mapa){

	int i;

	for(i = 0; i < mapa->x; i++){
		free(mapa->m[i]);
	}
	free(mapa->m);
}
