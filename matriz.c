#include"matriz.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Matriz** criaM(int tam){
    Matriz **M;
    
    M = (Matriz**)malloc(sizeof(Matriz*)*tam);
    
    return M;
}

void modificaM(Matriz **M, unsigned end, char rw, int x){
    M[x] = (Matriz*)malloc(sizeof(Matriz));
    M[x]->end = end;
    M[x]->rw = rw;
}

void apagaM(Matriz **M, int tam){
    for(int i = 0; i < tam; i++){
        free(M[i]);
    }
    
    free(M);
}