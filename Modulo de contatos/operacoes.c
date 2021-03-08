#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contatos.c"

#define true 1
#define false 0

void initLista ( Contatos *ptrContatos ) {
    ptrContatos -> lenght = -1;
}

int listaCheia ( Contatos *ptrContatos ) {
    if ( ptrContatos -> lenght + 1 == TAMLIST ) {
        return true;
    } else {
        return false;
    }
}

int listaVazia ( Contatos *ptrContatos ) {
    if ( ptrContatos -> lenght < 0 ) {
        return true;
    } else {
        return false;
    }
}

int inserirContatoNoFim ( Contatos *ptrContatos, Contato contato ) {
    if ( listaCheia ( ptrContatos ) ) {
        printf("Erro - lista cheia\n");
        return false;
    }
    ptrContatos -> lenght = ptrContatos -> lenght + 1;
    ptrContatos -> contato [ ptrContatos -> lenght ] = contato;
    return true;
}

int inserirContatoNoMeio ( Contatos *ptrContatos, int indice, Contato contato ) {
    if ( listaCheia ( ptrContatos ) ) {
        printf("Erro - lista cheia\n");
        return false;
    }
    if ( indice < 0 || indice > ptrContatos -> lenght  ) {
        printf ("Erro posicao invalida\n");
        return false;
    }
    for ( int i = ptrContatos -> lenght + 1; i > indice; i-- ) {
        ptrContatos->contato[i] = ptrContatos->contato[i-1];
    }
    ptrContatos->contato[indice] = contato;
    ptrContatos->lenght++;
    return true;
}

int atualizarContato ( Contatos *ptrContatos, int indice, Contato contato ) {
    if ( indice < 0 || indice > ptrContatos -> lenght + 1  ) {
        printf ("Erro posicao invalida\n");
        return false;
    }
    ptrContatos->contato[indice] = contato;
    return true;
}

Contato BucarContato ( Contatos *ptrContatos, int indice ) {
    if ( indice < 0 || indice > ptrContatos -> lenght + 1  ) {
        printf ("Erro posicao invalida\n");
        return;
    }
    return ptrContatos->contato[indice];
}

int RemoverContato ( Contatos *ptrContatos, int indice ) {
    if ( listaVazia ( ptrContatos ) ) {
        printf ("Erro lista vazia\n");
        return false;
    }
    if ( indice < 0 || indice > ptrContatos -> lenght + 1  ) {
        printf ("Erro posicao invalida\n");
        return false;
    }
    for ( int i = indice; i < ptrContatos->lenght; i++ ) {
        ptrContatos->contato[i] = ptrContatos->contato[i+1];
    }
    ptrContatos->lenght--;
    return true;
}

int PesquisarContato ( Contatos *ptrContatos, Contato contato ) {
    for ( int i = 0; i < ptrContatos -> lenght; i++ ) {
        if ( ptrContatos->contato[i].id == contato.id ) {
            return i;
        } else {
            if ( ptrContatos->lenght == i ) {
                return -1;
            }
        }
    }
}
 