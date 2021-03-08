#include "estrutura.c"

void main () {
    No *prtLista;
    prtLista = init (prtLista);
    prtLista = inserirNoInicio ( prtLista, 1 ) ;
    prtLista = inserirNoInicio ( prtLista, 2 ) ;
    prtLista = inserirNoFim ( prtLista, 3 ) ;
}
