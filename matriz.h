#ifndef MATRIZ
#define MATRIZ

typedef struct matriz{
    char *end;
    char *rw;
    int tam;
}Matriz;

Matriz** criaM(char*);
void modificaM(Matriz**, char*, int);
void apagaM(Matriz**, int);

#endif