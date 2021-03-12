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

void inserir_inicio ( No **lista, int elem ) {
    No *novo;
    novo = alocar();
    if ( novo != 0 ) {
        novo -> info = elem;
        novo -> esq = 0;
        novo -> dir = *lista;
        if ( ! listaVazia ( *lista ) ) {
            (*lista) -> esq = novo;
            return;
        }
        else {
            *lista = novo;
        }
    }
    else {
        printf ( "\nErro: falha na alocacao do noh!\n" );
        exit (1);
    }
}
