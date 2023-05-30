#include"mem.h"
#include<stdio.h>
#include<stdlib.h>

Mem** criaMem(int tam){
    Mem **Mf = (Mem**)malloc(sizeof(Mem*)*tam);

    for(int i  = 0; i < tam; i++){
        Mf[i] = (Mem*)malloc(sizeof(Mem));
        Mf[i]->ind = i;
        Mf[i]->ocupado = 0;
    }
    Mf[0]->tam = tam;

    return Mf;
}

int escreveMem(Mem **Mf){
    int c = -1;
    
    for(int i = 0; i < Mf[0]->tam; i++){
        if(Mf[i]->ocupado == 0){
            Mf[i]->ocupado = 1;
            c = i;
            break;
        }
    }

    return c; //c != -1 -> mem cheia; c != -1 -> conseguiu alocar e c é a pgF
}

void apagaMem(Mem **Mf){
    for(int i = 0; i < Mf[0]->tam; i++){
        free(Mf[i]);
    }
    free(Mf);
}