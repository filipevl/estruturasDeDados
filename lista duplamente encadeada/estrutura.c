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

void inserir_fim ( No **lista, int elem ) {
    No *novo;
    No *aux;
    novo = alocar ();
    if ( novo != 0 ) {
        novo -> info = elem;
        novo -> dir = 0;
        novo -> esq = 0;
        if ( listaVazia ( *lista ) ) {
            *lista = novo;
            return;
        }
        else {
            aux = *lista;
            while ( aux -> dir != 0 ) {
                aux = aux -> dir;
            }
            aux -> dir = novo;
            novo -> esq = aux;
        }

    }
    else { 
        printf ( "\nErro: falha na alocacao do noh!\n" );
        exit (1);
    }
}

void remover_inicio ( No **lista) {
    if ( listaVazia  (*lista) ) {
        printf ( "Erro: lista vazia" );
        exit (1);
        return;
    }
    else {
        No *q;
        q = *lista;
        *lista = q -> dir;
        (*lista) -> esq = 0;
        desalocarNo ( q );
        q=0;
    }
}

No* pesquisar ( No *ptrLista, int elem ) {
    No *aux = ptrLista;
    while ( aux -> info != elem ) {
        aux = aux -> dir;
    }
    return aux;
}
