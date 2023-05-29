#include <stdio.h>
#include<stdlib.h>
#include "arquivo.h"
#include"pag.h"

int main(int argc, char *argv[]){
    //argv[] -> [1] = algoritmo; [2] = arquivo; [3] = tam da pagina(2 a 64)KB; [4] = tam total da mem fisica(128 a 16382)KB
    int tamM, tamH, page, key, c, x;
    Matriz **M;
    Mem **Mf;
    Hash **H;

    M = ler_arquivo(argv[2]);
    Mf = criaMem(atoi(argv[4]));
    tamH = atoi(argv[4])/atoi(argv[3]);
    H = criaH(tamH);
    //M = ler_arquivo(argv[2]);

    tamM = M[0]->tam;
    //printf("tamH = %d\n", tamH);

    for(int i = 0; i < tamM; i++){
        page = determinaPag(atoi(argv[3]), M[i]->end);
        printf("4\n");
        key = funcHash(tamH, page);
        printf("5\n");
        c = preencheH(H, key, page/*, Mf, -1*/);
        printf("6\n");

        if((c == 1) || (M[i]->rw == 'W')){
            printf("7\n");
            x = escreveMem(Mf, 0);
            if(x != -1){
                printf("8\n");
                int a = procuraPgV(H, key, page);
                int ih = funcHash(tamH, a);
                printf("9\n");
                //printf("a = %d; ih = %d\n", a, ih);
                H[ih]->pgFisica = x;
                printf("10\n");
            }
        }else if(M[i]->rw == 'R'){
            //le a memoria
        }
    }

    
    apagaM(M, tamM);
    removeH(H, tamH);
    apagaMem(Mf);

    return 0;
}