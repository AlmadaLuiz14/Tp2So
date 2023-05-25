#include"matriz.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Matriz** criaM(char *str){
    Matriz **M;
    
    M = (Matriz**)malloc(sizeof(Matriz*));
    M[0] = (Matriz*)malloc(sizeof(Matriz));
    M[0]->end = strtok(str, " ");
    M[0]->rw = strtok(NULL, " ");
    
    return M;
}

void modificaM(Matriz **M, char *str, int q){
    M = realloc(M, sizeof(Matriz*)*q);
    M[q] = (Matriz*)malloc(sizeof(Matriz));
    M[q]->end = strtok(str, " ");
    M[q]->rw = strtok(NULL, " ");
    
}

void apagaM(Matriz **M, int tam){
    for(int i = 0; i < tam; i++){
        free(M[i]);
    }
    
    free(M);
}