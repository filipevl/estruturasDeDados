#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sFuncionario {
    char nome [25], dataDeNascimento [11];
    float salario;
} Funcionario;

void setFuncionario ( Funcionario *funcionario, char *nome, char *dataDeNascimento, float salario ) {
    strcpy ( funcionario->nome, nome );
    strcpy ( funcionario->dataDeNascimento, dataDeNascimento );
    funcionario->salario = salario;
    return;
}

void getFuncionario ( Funcionario *funcionario ) {
    printf ("Funcionario: %s\nData de nascimento: %s\nSalario: %.2f\n", funcionario->nome, funcionario->dataDeNascimento, funcionario->salario );
    return;
}


void setFuncionarios ( Funcionario *funcionarios, int quantidade ) {
    for ( int i = 0; i < quantidade; i++ ) {
        char nome[25], dataDeNascimento [11];
        float salario;

        printf ("\nDigite o nome do funcionario: ");
        scanf ("%s",nome);
        printf ("\nDigite a data de nascimento do funcionario: ");
        scanf ("%s",dataDeNascimento);
        printf ("Digite o salario do funcionario: ");
        scanf ("%f",&salario);

        strcpy ( funcionarios[i].nome, nome );
        strcpy ( funcionarios[i].dataDeNascimento, dataDeNascimento );
        funcionarios[i].salario = salario;
    }
    return;
}

void getFuncionarios ( Funcionario *funcionarios, int quantidade ) {
    for ( int i = 0; i < quantidade; i++ ) {
        printf ("Funcionario: %s\n", funcionarios[i].nome );
        printf ("Data de nascimento: %s\n", funcionarios[i].dataDeNascimento );
        printf ("Salario: %.2f\n", funcionarios[i].salario );
    }
    return;
}

void limparMemoria (Funcionario *ponteiro) {
    free(ponteiro);
    ponteiro = 0;
    return;
}
