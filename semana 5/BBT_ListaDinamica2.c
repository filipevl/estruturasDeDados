#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
    char elemento;
    struct sNo *prox;
} No;

void init ( No** lista ) {
    *lista = 0;
}

int listaVazia ( No** ptrLista ) {
    if ( *ptrLista == 0 ) {
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

No* pesquisar ( No* ptrLista, char elem ) {
    No* aux = 0;
    aux = ptrLista;
    if ( !listaVazia ( ptrLista ) ) {
        while ( aux != 0 ) {
            if ( aux -> elemento == elem ) {
                return aux;
            }
            aux = aux -> prox;
        }
    }
    return 0;
}

void inserirOrdenado ( No** lista, char elem ) {
    No* atual = *lista;
    No* anterior = 0;
    No* novo = 0;
    novo = alocar();
    if ( novo != 0 ) {
        novo -> elemento = elem;
        novo -> prox = 0;
        while ( atual != 0 && atual -> elemento < elem ) {
            anterior = atual;
            atual = atual->prox;
        }
        if ( atual == lista ) {
            novo -> prox = *lista;
            *lista = novo;
        }
        else {
            anterior -> prox = novo;
            novo -> prox = atual;
        }
    }
    else {
        printf("\n Erro na alocacao do no");
        return 0;
    }
}

void removerInicio ( No** ptrLista) {
    No *aux = 0;
    aux = *ptrLista;
    if ( !listaVazia( *ptrLista ) ) {
        *ptrLista = aux -> prox;
        desalocarNo ( aux );
    }
    return;
}

void removerValor ( No** lista, int elem ) {
    No* q = pesquisar ( *lista, elem );
    No* aux;

    if ( q != 0 ) {
        aux = *lista;
        if ( aux == q ) {
            removerInicio ( *lista );
        } else {
            while ( aux -> prox != q ) {
                aux = aux -> prox;
            }
            aux -> prox = q -> prox;
            desalocarNo ( q );
        }
    }
    return;
}

void pesquisarMoverPraFrente ( No** ptrLista, char elem ) {
    No *aux = pesquisar ( *ptrLista, elem );
    No *anterior = *ptrLista;
    while ( anterior != aux ) {
        anterior = anterior -> prox;
    }
    anterior -> prox = aux -> prox;
    aux -> prox = *ptrLista;
    *ptrLista = aux;
}
