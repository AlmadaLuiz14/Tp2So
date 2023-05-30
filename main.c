#include <stdio.h>
#include<stdlib.h>
#include"pag.h"
#include"mem.h"

/*argv[] -> [1] = algoritmo; [2] = arquivo; 
[3] = tam da pagina(2 a 64)KB; [4] = tam total da mem fisica(128 a 16382)KB*/
int main(int argc, char *argv[]){
    int tamH, page, key, c, x, write = 0, read = 0;
    FILE *file;
    unsigned end;
    char rw;
    Mem **Mf;
    Hash **H;

    /*Cria a Hash(tabela de paginas) e a Memoria fisica*/
    tamH = atoi(argv[4])/atoi(argv[3]);
    H = criaH(tamH);
    Mf = criaMem(atoi(argv[4]));

    /*Abre o arquivo*/
    file = fopen(argv[2], "r");
    
    /*Verifica se ele existe*/
    if(file == NULL){
        printf("Arquivo nao pode ser aberto ou nao existe\n");
        return 0;
    }
    
    /*Começa a leitura do arquivo*/
    fscanf(file, "%x %c", &end, &rw);
    //printf("end = %x; rw = %c\n", end, rw);
    while(fscanf(file, "%x %c", &end, &rw) != EOF){
        //printf("end = %x; rw = %c\n", end, rw);

        page = determinaPag(atoi(argv[3]), end);
        key = funcHash(tamH, page);
        c = preencheH(H, key, page);

        if((c == 1) || (rw == 'W')){
            /*A instrução é de escrita, ou o endereço n estava
            na tabela, consequentemente n estava na memoria*/
            x = escreveMem(Mf);
            if(x != -1){
                Hash *p1 = procuraPgV(H, key, page);
                
                if(p1 == NULL){
                    printf("Deu ruim aqui\n");//tirar depois esse if
                }

                p1->pgFisica = x;
            }else{
                //aqui é onde ocorre a page fault
            }

            if(rw == 'R'){
                read++;
            }
            write++; //deveria estar como um else do if acima?

        }else if(rw == 'R'){
            /*Instrução é de leitura e o endereço ja estava na tabela*/
            Hash *p1 = procuraPgV(H, key, page);
            
            if(p1 == NULL){
                    printf("Deu ruim aqui\n");//tirar depois esse if
            }
            
            if(p1->bitV == 0){
                //tem q atualizar a memoria para deixar a info valida = colocar a info la de novo;
            }

            read++;
        }

    }


    /*for(int i = 0; i < atoi(argv[4]); i++){
        printf("Mf[%d]->ocupado = %d\n", i, Mf[i]->ocupado);
    }*/


    /*Saida do programa com todas as infos sobre a execução*/
    printf("Arquivo de entrada: %s\n", argv[2]);
    printf("Tamanho da memoria: %d\n", atoi(argv[4]));
    printf("Tamanho da pagina: %d\n", atoi(argv[3]));
    printf("Tecnica de reposicao: %s\n", argv[1]);
    printf("Paginas lidas: %d\n", read);
    printf("Paginas escritas: %d\n", write);



    fclose(file);
    removeH(H, tamH);
    apagaMem(Mf);
    return 0;
}