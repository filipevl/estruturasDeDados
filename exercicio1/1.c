#include <stdio.h>
#include <stdlib.h>

int main () {
    int *p, *q;
    p = malloc ( sizeof (int));
    q = p;
    if (p != NULL) {
        *p = 10;
        *q = 20;
        free(p);
    }
    return 0;
}