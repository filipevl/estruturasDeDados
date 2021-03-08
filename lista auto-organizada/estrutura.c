#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNo{
    char dado;
    struct sNo *prox;
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

No* inserirOrdenado ( No* lista, char elem ) {
    No* atual = lista;
    No* anterior = 0;
    No* novo = 0;
    novo = alocar();
    if ( novo != 0 ) {
        novo -> dado = elem;
        novo -> prox = 0;
        while ( atual != 0 && atual -> dado < elem ) {
            anterior = atual;
            atual = atual->prox;
        }
        if ( atual == lista ) {
            novo -> prox = lista;
            lista = novo;
        }
        else {
            anterior -> prox = novo;
            novo -> prox = atual;
        }
        return lista;
    }
    else {
        printf("\n Erro na alocacao do no");
        return 0;
    }
}
