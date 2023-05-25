#include <stdio.h>
#include "arquivo.h"

void main(){
    char *file = "t.txt";
    Matriz **M;
    int tam;
    
    M = ler_arquivo(file);
    tam = M[0]->tam;
    apagaM(M, tam);
}