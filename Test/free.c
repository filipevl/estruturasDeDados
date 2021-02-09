#include <stdlib.h>
#include <stdio.h>

// Descoberta de que a função free não armazena NULL no conteúdo do ponteiro

void main () {
    int *ptr;
    ptr = malloc ( sizeof ( int ));
    *ptr = 2000;
    printf("Conteudo: %d\tPonteiro: %p\n",*ptr,ptr);
    free(ptr);
    printf("Conteudo: %d\tPonteiro: %p",*ptr,ptr);
    getchar();
}
