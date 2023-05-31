#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pag.h"
#include"mem.h"
#include"substituicao.h"

/*argv[] -> [1] = algoritmo; [2] = arquivo; 
[3] = tam da pagina(2 a 64)KB; [4] = tam total da mem fisica(128 a 16382)KB*/

int main(int argc, char *argv[]){
    int qPag, pgEl, pagH, c, x, write = 0, read = 0, access = 0;
    FILE *file;
    unsigned end;
    char rw;
    Mem **Mf;
    Hash **H;
    Hash *p1;

    printf("Executando o algoritmo...\n");

    /*Cria a Hash(tabela de paginas) e a Memoria fisica*/
    qPag = atoi(argv[4])/atoi(argv[3]);
    H = criaH(atoi(argv[4]), atoi(argv[3]));
    Mf = criaMem(qPag, atoi(argv[3]));

    /*Abre o arquivo*/
    file = fopen(argv[2], "r");
    
    /*Verifica se ele existe*/
    if(file == NULL){
        printf("Arquivo nao pode ser aberto ou nao existe\n");
        return 0;
    }
    
    /*Começa a leitura do arquivo*/
    fscanf(file, "%x %c", &end, &rw);
    while(fscanf(file, "%x %c", &end, &rw) != EOF){
        pgEl = determinaPag(atoi(argv[3]), end);
        pagH = funcHash(qPag, pgEl);
        c = preencheH(H, pagH, pgEl);
        if((c != -1) || (rw == 'W')){
            /*A instrução é de escrita, ou o endereço n estava
            na tabela, consequentemente n estava na memoria*/
            if(c == -1){
                c = pagH;
            }
            x = escreveMem(Mf, c);
            
            write++;
            access++; 
            if(x != -1){
                p1 = procuraPgV(H, c, pgEl);

                p1->pgFisica = x;
            }else{
                
                if(strcmp(argv[1], "lru")){
                    lru(Mf, c);
                    read = read + 3;
                    write++;
                    access = access + 4;
                } else if(strcmp(argv[1], "nru")){
                    nru(Mf, c);
                    read = read + 3;
                    write++;
                    access = access + 4;
                } else if(strcmp(argv[1], "segunda_chance")){
                    segChanc(Mf, c);
                    read = read + 3;
                    write++;
                    access = access + 4;
                }
                
            }

        }else if(rw == 'R'){
            /*Instrução é de leitura e o endereço ja estava na tabela*/
            p1 = procuraPgV(H, pagH, pgEl);
            read++;
            access++;
        }

        if(strcmp(argv[1], "lru")){
            modificaVetLru(Mf, p1->pgFisica);
        } else if(strcmp(argv[1], "nru")){
            modificaVetNru(Mf, rw, p1->pgFisica);
        } else if(strcmp(argv[1], "segunda_chance")){
            Mf[p1->pgFisica]->segC = 1;
        }
        
    }

    /*Saida do programa com todas as infos sobre a execução*/
    printf("Arquivo de entrada: %s\n", argv[2]);
    printf("Tamanho da memoria: %d\n", atoi(argv[4]));
    printf("Tamanho da pagina: %d\n", atoi(argv[3]));
    printf("Tecnica de reposicao: %s\n", argv[1]);
    printf("Paginas lidas: %d\n", read);
    printf("Paginas escritas: %d\n", write);
    printf("Quantidade de acessos a memoria: %d\n", access);

    fclose(file);
    removeH(H, qPag);
    apagaMem(Mf);
    return 0;
}