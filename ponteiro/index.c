#include <stdio.h>
#include <stdlib.h>

typedef struct sNo {
    char elem;
    struct sNo *prox;
} No;

void init ( No **ptr ) {
    *ptr = 0;
}

int listaVazia ( No **ptr ) {
    if ( *ptr == 0 ) {
        return 1;
    }
    return 0;
}

void main () {
    No *ptrNo;
    init ( &ptrNo );
}