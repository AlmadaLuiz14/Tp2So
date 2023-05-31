all: main.o pag.o mem.o substituicao.o
	gcc main.o pag.o mem.o substituicao.o -o tp2virtual

main.o: main.c pag.h
	gcc -g -c main.c

pag.o: pag.h pag.c
	gcc -g -c pag.c

mem.o: mem.h mem.c
	gcc -g -c mem.c

substituicao.o: substituicao.h substituicao.c mem.h pag.h
	gcc -g -c substituicao.c