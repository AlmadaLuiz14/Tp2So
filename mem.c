#include"mem.h"
#include<stdio.h>
#include<stdlib.h>

Mem** criaMem(int tam, int tamPag){
    Mem **Mf = (Mem**)malloc(sizeof(Mem*)*tam);

    for(int i = 0; i < tam; i++){
        Mf[i] = (Mem*)malloc(sizeof(Mem));
        Mf[i]->pagH = -1;
        Mf[i]->ind = i;
        Mf[i]->vetLru[0] = 0;
        Mf[i]->vetLru[1] = 0;
        Mf[i]->vetLru[2] = 0;
        Mf[i]->vetNru[0] = 0;
        Mf[i]->vetNru[1] = 0;
        Mf[i]->vetNru[2] = 0;
        Mf[i]->segC = 0;

    }
    Mf[0]->tam = tam;

    return Mf;
}

int escreveMem(Mem **Mf, int pagH){
    int c = -1;
    
    for(int i = 0; i < Mf[0]->tam; i++){
        if(Mf[i]->pagH == -1){
            Mf[i]->pagH = pagH;
            c = i;
            break;
        }
    }

    return c; //c == -1 -> mem cheia; c != -1 -> conseguiu alocar e c é o indice da hash
}

void apagaMem(Mem **Mf){
    for(int i = 0; i < Mf[0]->tam; i++){
        free(Mf[i]);
    }
    free(Mf);
}