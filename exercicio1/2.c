#include <stdio.h>
#include <stdlib.h>

// Adicao do free(q);

int main () {
    int *p, *q;
    p = malloc ( sizeof (int));
    q = malloc ( sizeof (int));
    if (p != NULL) {
        *p = 10;
        *q = 20;
        free(p);
        free(q);
    }
    return 0;
}