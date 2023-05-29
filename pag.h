#ifndef PAG
#define PAG

typedef struct hash{ //tam = o numero de molduras de pags na mem fisica
    int ind;
    int bitV;
    int bitMod;
    int pid;
    int pgVirtual;
    int pgFisica;
    struct hash *prox;
    struct hash *ult;
    //struct hash *prim;
}Hash;

typedef struct mem{
    int ind;
    int dados;
    int tam;
}Mem;

int determinaPag(int, unsigned);
Hash** criaH(int);
int preencheH(Hash**, int, int/*, Mem**, int*/);
int funcHash(int, int);
void removeH(Hash**, int);

Mem** criaMem(int);
int escreveMem(Mem**, int);
void apagaMem(Mem**);
int procuraPgV(Hash**, int, int);
#endif