#include <stdio.h>
#include <stdlib.h>

typedef struct sCanais {
    int numeroCanal;
    char nomeCanal [100];
    struct sCanais *dir, *esq;
} Canal;
