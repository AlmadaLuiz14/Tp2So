all: main.o arquivo.o matriz.o
	gcc main.o arquivo.o matriz.o -o tp2virtual

main.o: main.c arquivo.h
	gcc -g -c main.c

arquivo.o: arquivo.h arquivo.c matriz.h
	gcc -g -c arquivo.c

mulPipe.o: matriz.h matriz.c
	gcc -g -c matriz.c