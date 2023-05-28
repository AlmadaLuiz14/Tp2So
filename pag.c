#include"pag.h"
#include<stdio.h>
#include<stdlib.h>

int determinaPag(int page_size, unsigned end){
    int s = 0, tmp = page_size, page;

    while(tmp > 1){
        tmp = tmp >> 2;
        s++;
    }

    page = end >> s;

    return page; //pag virtual
} 

Hash** criaH(int tam){
    Hash **H = (Hash**)malloc(sizeof(Hash*)*tam);

    for(int i = 0; i < tam; i++){
        H[i] = (Hash*)malloc(sizeof(Hash));
        H[i]->key = i;
        H[i]->prox = NULL;
        H[i]->ult = NULL;
    }

    return H;
}

void preencheH(Hash **H, int key, int bitV, int pid, int pgV, int pgF){
    Hash *aux;
    
    if(H[key]->prox == NULL){
        aux = (Hash*)malloc(sizeof(Hash));
        aux->key = key;
        aux->bitV = bitV;
        aux->pid = pid;
        aux->pgVirtual = pgV;
        aux->pgFisica = pgF;
        aux->prox = NULL;
        H[key]->prox = aux;
        H[key]->ult = aux;
    }else{
        aux = (Hash*)malloc(sizeof(Hash));
        aux->key = key;
        aux->bitV = bitV;
        aux->pid = pid;
        aux->pgVirtual = pgV;
        aux->pgFisica = pgF;
        aux->prox = NULL;
        H[key]->ult->prox = aux;
        H[key]->ult = aux;
    }
}

void removeH(Hash **H, int tam){
    Hash *aux;
    
    for(int i = 0; i < tam; i++){
        if(H[i]->prox != NULL){
            do{
                aux = H[i]->prox;
                H[i]->prox = aux->prox;
                free(aux);
            }while(H[i]->prox != NULL);
            free(H[i]);
        }else{
            free(H[i]);
        }
    }

    free(H);
}