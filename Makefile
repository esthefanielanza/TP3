CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Werror -std=c99 -pthread

all: main

main: main.o resolucao.o paralela.o leitura.o
	$(CC) $(CFLAGS) main.o resolucao.o paralela.o leitura.o -o tp3

main.o: main.c resolucao.h paralela.h leitura.h
	$(CC) $(CFLAGS) -c main.c

resolucao.o: resolucao.c resolucao.h
	$(CC) $(CFLAGS) -c resolucao.c

paralela.o: paralela.c paralela.h
	$(CC) $(CFLAGS) -c paralela.c

leitura.o: leitura.c leitura.h
	$(CC) $(CFLAGS) -c leitura.c

clean:
	rm *.o tp3
