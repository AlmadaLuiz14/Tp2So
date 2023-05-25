#include"arquivo.h"
#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

void escrever_arquivo()
{
    char string[100];
    FILE *file;
    file = fopen("shellso.txt", "a");
    if (file == NULL)
    {
        printf("Arquivo nao pode ser aberto\n");
    }
    fputs(string, file);
    fclose(file);

}

Matriz** ler_arquivo(char *arq){
    int x = 0, tam = 0;
    char line[100];
    Matriz **M;
    FILE *file;
    file = fopen(arq, "r");
    
    if(file == NULL){
        printf("Arquivo nao pode ser aberto ou nao existe\n");
    }

    while(x == 0){
        if(fgets(line, 100, file) == NULL){
            x = 1;
        }else{
            if(tam == 0){
                //printf("0\n");
                M = criaM(line);
            }else{
                //printf("1\n");
                modificaM(M, line, tam);
            }

            tam++;
        }
    }
    
    M[0]->tam = tam; //o primeiro elemento possui a info do tamanho da matriz

    fclose(file);
    return M;
}