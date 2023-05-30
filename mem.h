#ifndef MEM
#define MEM

typedef struct mem{
    int ind;
    int ocupado;
    int tam;
}Mem;


Mem** criaMem(int);
int escreveMem(Mem**);
void apagaMem(Mem**);

#endif