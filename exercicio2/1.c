#include "Funcionario.c"
#include <stdlib.h>

void main () {
    Funcionario * func = malloc (sizeof (Funcionario));
    setFuncionario(func,"Filipe","07/11/2000",1149.50);
    getFuncionario(func);
    limparMemoria(func);
    getchar();
}