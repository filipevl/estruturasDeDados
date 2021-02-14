#include "Funcionario.c"

void main () {
    int quantidade;
    Funcionario *func = calloc (quantidade, sizeof (Funcionario));
    printf("Digite o numero de funcionarios: ");
    scanf ("%d", &quantidade);
    setFuncionarios ( func, quantidade );
    getFuncionarios ( func, quantidade );
    limparMemoria ( func );
}