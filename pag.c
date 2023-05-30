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
        H[i]->ind = i;
        H[i]->prox = NULL;
        H[i]->ult = NULL;
    }

    return H;
}

int preencheH(Hash **H, int key, int pgV/*, Mem **Mf, int dados*/){
    Hash *aux;
    //printf("50\n");
    //printf("key = %d\n", key);
    if(H[key]->prox == NULL){
        //printf("51\n");
        aux = (Hash*)malloc(sizeof(Hash));
        aux->ind = key;
        aux->bitV = 1;
        aux->bitMod = 0;
        //aux->pid = pid;
        aux->pgVirtual = pgV;
        //aux->pgFisica = pgF;
        aux->prox = NULL;
        H[key]->prox = aux;
        H[key]->ult = aux;

        return 1;
    }else{
        //printf("52\n");
        //printf("pag = %d\n", pgV);
        if(procuraPgV(H, key, pgV) == NULL){
            //printf("53\n");
            aux = (Hash*)malloc(sizeof(Hash));
            aux->ind = key;
            aux->bitV = 1;
            aux->bitMod = 0;
            //aux->pid = pid;
            aux->pgVirtual = pgV;
            //aux->pgFisica = pgF;
            aux->prox = NULL;
            H[key]->ult->prox = aux;
            H[key]->ult = aux;
        
            return 1;
        }
        //printf("54\n");
    }

    return 0;
}

Hash* procuraPgV(Hash **H, int key, int pgV){
    Hash *aux = H[key]->prox;

    do{
        //printf("pg = %d; pgV = %d\n", aux->pgVirtual, pgV);
        if(aux->pgVirtual == pgV){
            return aux;
        }
        aux = aux->prox;
        //printf("aaaaaaaa\n");
    }while(aux != NULL);

    return NULL;
}

int funcHash(int tam, int pag){
    //printf("%d %d\n", tam, pag);

    return pag % tam;
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