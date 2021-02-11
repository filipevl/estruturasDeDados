#include <stdio.h>
#include <stdlib.h>

// 

void copiar (char *substituir, char *palavra) {
    for (int i = 0; i < 200; i++) {
        substituir[i] = palavra [i];
    }
}

void main () {
    char nome[50];
    copiar ( nome, "joao");
    printf ("%s\n", nome);
    getchar();
}