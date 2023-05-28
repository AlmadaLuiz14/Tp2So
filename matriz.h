#ifndef MATRIZ
#define MATRIZ

typedef struct matriz{
    unsigned end;
    char rw;
    int tam;
}Matriz;

Matriz** criaM(int);
void modificaM(Matriz**, unsigned, char, int);
void apagaM(Matriz**, int);

#endif