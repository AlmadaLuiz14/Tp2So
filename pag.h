#ifndef PAG
#define PAG

typedef struct hash{ //tam = o numero de molduras de pags na mem fisica
    int ind;
    int bitV;
    int bitMod;
    int pgVirtual;
    int pgFisica;
    int endFisico;
    
    int tamMax;
    int tamAtual;
    int tamH;

    struct hash *prox;
    struct hash *ult;
}Hash;

int determinaPag(int, unsigned);
Hash** criaH(int, int);
int preencheH(Hash**, int, int/*, Mem**, int*/);
int funcHash(int, int);
Hash* procuraPgV(Hash**, int, int);
int procuraVazia(Hash**);
void removeH(Hash**, int);

#endif