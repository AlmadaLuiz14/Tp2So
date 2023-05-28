#include"arquivo.h"
#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

void escrever_arquivo(){
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

int calculaTam(FILE *file){
    unsigned a;
    char b;
    int tam = 0;

    while(fscanf(file, "%x %c", &a, &b) != EOF){
        tam++;
    }

    return tam;
}

Matriz** ler_arquivo(char *arq){
    int x = 0, tam;
    unsigned end;
    char rw;
    Matriz **M;
    FILE *file;
    
    file = fopen(arq, "r");
    
    if(file == NULL){
        printf("Arquivo nao pode ser aberto ou nao existe\n");
    }

    tam = calculaTam(file);
    M = criaM(tam);
    while(x != tam){
        fscanf(file, "%x %c", &end, &rw);
        modificaM(M, end, rw, x);
        
        x++;
    }
    
    M[0]->tam = tam; //o primeiro elemento possui a info do tamanho da matriz

    fclose(file);
    return M;
}