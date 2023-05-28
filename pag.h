#ifndef PAG
#define PAG

typedef struct hash{ //tam = o numero de molduras de pags na mem fisica
    int key;
    int bitV;
    int pid;
    int pgVirtual;
    int pgFisica;
    struct hash *prox;
    struct hash *ult;
    //struct hash *prim;
}Hash;

int determinaPag(int, unsigned);
Hash** criaH(int);
void preencheH(Hash**, int, int, int, int, int);
void removeH(Hash**, int);

#endif