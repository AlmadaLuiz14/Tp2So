#include <stdio.h>
#include<stdlib.h>
#include"pag.h"
#include"mem.h"

int main(int argc, char *argv[]){
    //argv[] -> [1] = algoritmo; [2] = arquivo; [3] = tam da pagina(2 a 64)KB; [4] = tam total da mem fisica(128 a 16382)KB
    int tamH, page, key, c, x, write = 0, read = 0;
    FILE *file;
    unsigned end;
    char rw;
    Mem **Mf;
    Hash **H;

    tamH = atoi(argv[4])/atoi(argv[3]);
    H = criaH(tamH);
    Mf = criaMem(atoi(argv[4]));


    file = fopen(argv[2], "r");
    
    if(file == NULL){
        printf("Arquivo nao pode ser aberto ou nao existe\n");
        return 0;
    }
    
    fscanf(file, "%x %c", &end, &rw);
    //printf("end = %x; rw = %c\n", end, rw);
    while(fscanf(file, "%x %c", &end, &rw) != EOF){
        //printf("end = %x; rw = %c\n", end, rw);

        //printf("0\n");
        page = determinaPag(atoi(argv[3]), end);
        //printf("1\n");
        key = funcHash(tamH, page);
        //printf("2\n");
        c = preencheH(H, key, page);
        //printf("3\n");

        if((c == 1) || (rw == 'W')){
            //printf("4\n");
            x = escreveMem(Mf);
            //printf("5\n");
            if(x != -1){
                Hash *p1 = procuraPgV(H, key, page);
                p1->pgFisica = x;
            }else{
                //aqui é onde ocorre a page fault
            }

            write++;
        }else if(rw == 'L'){
            Hash *p1 = procuraPgV(H, key, page);
            if(p1->bitV == 0){
                //tem q atualizar a memoria para deixar a info valida = colocar a info la de novo;
            }
        }

    }


    /*for(int i = 0; i < atoi(argv[4]); i++){
        printf("Mf[%d]->ocupado = %d\n", i, Mf[i]->ocupado);
    }*/


    fclose(file);
    removeH(H, tamH);
    apagaMem(Mf);
    return 0;
}