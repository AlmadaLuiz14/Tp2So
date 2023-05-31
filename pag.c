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

Hash** criaH(int tam, int tamPag){
    Hash **H = (Hash**)malloc(sizeof(Hash*)*tam);

    for(int i = 0; i < tam; i++){
        H[i] = (Hash*)malloc(sizeof(Hash));
        H[i]->ind = i;
        H[i]->tamMax = tamPag;
        H[i]->tamAtual = 0;
        H[i]->prox = NULL;
        H[i]->ult = NULL;
    }
    H[0]->tamH = tam;

    return H;
}

int preencheH(Hash **H, int key, int pgV){
    Hash *aux;
   
    if(H[key]->prox == NULL){
        aux = (Hash*)malloc(sizeof(Hash));
        aux->ind = key;
        aux->bitV = 1;
        aux->bitMod = 0;
        aux->pgVirtual = pgV;
        aux->prox = NULL;
        H[key]->tamAtual++;
        H[key]->prox = aux;
        H[key]->ult = aux;

        return key;
    }else{
        if((procuraPgV(H, key, pgV) == NULL)){
            if(H[key]->tamAtual < H[key]->tamMax){
                aux = (Hash*)malloc(sizeof(Hash));
                aux->ind = key;
                aux->bitV = 1;
                aux->bitMod = 0;
                aux->pgVirtual = pgV;
                aux->prox = NULL;
                H[key]->tamAtual++;
                H[key]->ult->prox = aux;
                H[key]->ult = aux;

                return key;
            }else{
                int x = procuraVazia(H);
                if(x != -1){
                    aux = (Hash*)malloc(sizeof(Hash));
                    aux->ind = x;
                    aux->bitV = 1;
                    aux->bitMod = 0;
                    aux->pgVirtual = pgV;
                    aux->prox = NULL;
                    H[x]->tamAtual++;
                    if(H[x]->ult == NULL){
                        aux->prox = NULL;
                        H[x]->prox = aux;
                        H[x]->ult = aux;
                    }else{
                        H[x]->ult->prox = aux;
                        H[x]->ult = aux;
                    }

                    return x;
                }else{
                    H[0]->ult->pgVirtual = pgV;
                    return 0;
                }

            }
            
        }
        
    }

    return -1;
}

Hash* procuraPgV(Hash **H, int key, int pgV){
    Hash *aux = H[key]->prox;

    do{
        if(aux->pgVirtual == pgV){
            return aux;
        }
        aux = aux->prox;
    }while(aux != NULL);

    return NULL;
}

int procuraVazia(Hash **H){
    int tMax = H[0]->tamMax;

    for(int i = 0; i < H[0]->tamH; i++){
        if(H[i]->tamAtual < tMax){
            return i;
        }
    }

    return -1;
}

int funcHash(int tam, int pag){
    return pag % tam;
}

void removeH(Hash **H, int tam){
    Hash *aux;
    int t = H[0]->tamH;
    
    for(int i = 0; i < t; i++){
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