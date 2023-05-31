#include"mem.h"
#include"pag.h"
#include<stdio.h>
#include<stdlib.h>
  
void lru(Mem** mF, int indPagHash){
    int tamMF = mF[0]->tam, contVal = 0, maior = 0, indSubs;

    for(int i = 0; i < tamMF; i++){
        
        for(int j = 0; j < 3; j++){
            
            if(mF[i]->vetLru[j] == 0){
               contVal++; 
            }

            if(maior < contVal){
                maior = contVal;
                indSubs = i;
            }

        }
        
        contVal = 0;
    }
    
    if(maior == 0){
        indSubs = 0;
    }

    mF[indSubs]->pagH = indPagHash;

}

void modificaVetLru(Mem **Mf, int i){
    
    if((Mf[i]->vetLru[0] == 0) && (Mf[i]->vetLru[1] == 0) && (Mf[i]->vetLru[2] == 0)){
        Mf[i]->vetLru[0] = 1;
    }else if((Mf[i]->vetLru[0] == 1) && (Mf[i]->vetLru[1] == 0) && (Mf[i]->vetLru[2] == 0)){
        Mf[i]->vetLru[1] = 1;
    }else if((Mf[i]->vetLru[0] == 1) && (Mf[i]->vetLru[1] == 1) && (Mf[i]->vetLru[2] == 0)){
        Mf[i]->vetLru[2] = 1;
    }else if((Mf[i]->vetLru[0] == 1) && (Mf[i]->vetLru[1] == 1) && (Mf[i]->vetLru[2] == 1)){
        Mf[i]->vetLru[1] = 0;
        Mf[i]->vetLru[2] = 0;
    }
    
}

void nru(Mem** mF, int indPagHash){
    int tamMF = mF[0]->tam, indSubs;

    for(int i = 0; i < tamMF; i++){
       
        if(mF[i]->vetNru[0] == 0 && mF[i]->vetNru[1] == 0){
            indSubs = i;
            break;
        } else if(mF[i]->vetNru[0] == 1 && mF[i]->vetNru[1] == 0){
            indSubs = i;
            break;
        } else if(mF[i]->vetNru[0] == 0 && mF[i]->vetNru[1] == 1){
            indSubs = i;
            break;
        } else if(mF[i]->vetNru[0] == 1 && mF[i]->vetNru[1] == 1){
            indSubs = i;
            break;
        }

    }

    mF[indSubs]->pagH = indPagHash;

}

void modificaVetNru(Mem **Mf, char rw, int i){
    if(rw == 'W'){
        Mf[i]->vetNru[0] = 1;
        Mf[i]->vetNru[1] = 1;
    }else if(rw == 'R'){
        Mf[i]->vetNru[1] = 1;
    }
}

void segChanc(Mem** mF, int indPagHash){
    int tamMF = mF[0]->tam, indSubs;

    if(mF[0]->segC == 1){
        mF[0]->segC == 0;

        mF[tamMF]->pagH = mF[0]->pagH;
        for(int i = 0; i < tamMF-1; i++){
            mF[i]->pagH = mF[i+1]->pagH;
        }    
        mF[tamMF]->pagH = indPagHash;
            
    } else if(mF[0]->segC == 0){
        mF[0]->pagH = indPagHash;
    }

}