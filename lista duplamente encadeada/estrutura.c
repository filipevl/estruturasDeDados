#include <stdio.h>
#include <stdlib.h>
typedef struct sNo {
    int info;
    struct sNo *dir, *esq;
} No;

No* init ( No* lista ) {
    lista = 0;
    return lista;
}

int listaVazia ( No* ptrLista ) {
    if ( ptrLista == 0 ) {
        return 1;
    }
    return 0;
}

No* alocar () {
    return malloc ( sizeof ( No ) );
}

void desalocarNo ( No* q ) {
    free (q);
}
