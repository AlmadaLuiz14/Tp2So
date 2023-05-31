#ifndef MEM
#define MEM

typedef struct mem{
    int ind;
    int tam;
    int pagH;

    int vetLru[3];
    int vetNru[2];
    int segC;
}Mem;

Mem** criaMem(int, int);
int escreveMem(Mem**, int);
void apagaMem(Mem**);

#endif