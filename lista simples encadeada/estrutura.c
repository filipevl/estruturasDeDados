#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
    int info;
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

No* inserirNoInicio ( No* ptrLista, int elem ) {
    No* novo = 0;
    novo = alocar();
    if ( novo != 0) {
        novo -> info = elem;
        novo -> prox = ptrLista;
        ptrLista = novo;
        return ptrLista;
    }
    return 0;
}

No* inserirNoFim ( No* ptrLista, int elem ) {
    No* novo = 0;
    No *aux = 0;

    novo = alocar();
    if ( novo != 0 ) {
        novo -> info = elem;
        novo -> prox = 0;
        if ( listaVazia ( ptrLista ) ) {
            ptrLista = novo;
            return ptrLista;
        } else {
            aux = ptrLista;
            while ( aux -> prox != 0 ){
                aux = aux -> prox;
            }
            aux -> prox = novo;
        }
        return ptrLista;
    }
    return 0;
}

No* pesquisar ( No* ptrLista, int elem ) {
    No* aux = 0;
    aux = ptrLista;
    if ( !listaVazia ( ptrLista ) ) {
        while ( aux != 0 ) {
            if ( aux -> info == elem ) {
                return aux;
            }
            aux = aux -> prox;
        }
    }
    return 0;
}

No* removerInicio ( No* ptrLista) {
    No *aux = 0;
    aux = ptrLista;
    if ( !listaVazia( ptrLista ) ) {
        ptrLista = aux -> prox;
        desalocarNo ( aux );
        return ptrLista;
    }
    return 0;
}

No* removerValor ( No* lista, int elem ) {
    No* q;
    No* aux;

    if ( (q = pesquisar ( lista, elem ) ) != 0 ) {
        aux = lista;
        if ( aux == q ) {
            removerInicio ( lista );
        } else {
            while ( aux -> prox != q ) {
                aux = aux -> prox;
            }
            aux -> prox = q -> prox;
            desalocarNo ( q );
        }
        return lista;
    }
    return 0;
}
