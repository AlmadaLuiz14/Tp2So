#include <stdio.h>
#include<stdlib.h>
#include "arquivo.h"
#include"pag.h"

int main(int argc, char *argv[]){
    //argv[] -> [1] = algoritmo; [2] = arquivo; [3] = tam da pagina(2 a 64)KB; [4] = tam total da mem fisica(128 a 16382)KB
    Matriz **M;
    int tamM, tamH;

    tamH = atoi(argv[4])/atoi(argv[3]);
    
    /*Hash **H = criaH(tamH);
    preencheH(H, 1, 2, 3, 4, 5);
    preencheH(H, 1, 2, 3, 4, 5);
    removeH(H, tamH);
    return 0;*/

    M = ler_arquivo(argv[2]);
    tamM = M[0]->tam;
    apagaM(M, tamM);

    return 0;
}