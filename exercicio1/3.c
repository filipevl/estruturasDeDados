#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sProduto {
    char nome[50];
    int quantidade;
    float preco;
    int id;
} Produto;

void setProduto ( Produto *produto, char *nome, int quantidade, float preco, int id ){
    strcpy ( produto->nome, nome );
    produto->id = id;
    produto->preco = preco;
    produto->quantidade = quantidade;
}

Produto maiorPreco ( Produto *p, int lenght ) {
    int flutuante;
    for(int i = 0; i < lenght; i++ ) {
        if ( i == 0 ){
            flutuante = 0;
            continue;
        }
        if ( p[flutuante].preco < p[i].preco ){
            flutuante = i;
        }
    }
    return p[flutuante];
}

Produto findByPk ( Produto *p, int lenght, int pk ){
    for( int i = 0; i < lenght; i++ ) {
        if ( p[i].id == pk ){
            return p[i];
        }
    }
}

void main () {
    int lenght;
    scanf ( "%d", &lenght );
    Produto *produtos = malloc( sizeof (Produto));
    for (int i = 0; i < lenght; i++ ) {
        setProduto(&produtos[i],"fvdsecfvgedw",44,32.9,i);
    }
    Produto maisCaro = maiorPreco(produtos,lenght);
    Produto id22 = findByPk(produtos,lenght,22);
    free(produtos);
}