#include "BBT_LDE.c"

void menu ( No *ptrLista ) {
    int opcao;
    printf ( "1. Inserir elemento no início da lista\n" );
    printf ( "2. Inserir elemento no final da lista\n" );
    printf ( "3. Remover elemento do início da lista\n" );
    printf ( "4. Remover determinado elemento da lista\n" );
    printf ( "5. Remover do final da lista\n" );
    printf ( "6. Exibir os elementos da lista na ordem inversa\n" );
    printf ( "7. Exibir a soma de todos os elementos da lista\n" );
    printf ( "8 - Sair\n" );
    switch (opcao)
    {
        case 1:
            float elem;
            printf ( "Digite o elemento: " );
            scanf ( "%f", &elem );
            inserir_inicio( ptrLista, elem );
            menu ( ptrLista );
            break;
        case 2:
            float elem;
            printf ( "Digite o elemento: " );
            scanf ( "%f", &elem );
            inserir_fim( ptrLista, elem );
            menu ( ptrLista );
            break;
        case 3:
            remover_inicio ( ptrLista );
            menu ( ptrLista );
            break;
        case 4:
            float elem;
            printf ( "Digite o elemento: " );
            scanf ( "%f", &elem );
            remover_valor ( ptrLista, elem );
            menu ( ptrLista );
            break;
        case 5:
            remover_fim ( ptrLista );
            menu ( ptrLista );
            break;
        case 6:
            ordem_inversa ( ptrLista );
            menu ( ptrLista );
            break;
        case 7:
            printf ( "Soma: %f\n", soma ( ptrLista ) );
            menu ( ptrLista );
            break;
        case 8:
            exit (1);
            break;
        default:
            printf ( "Opcao invalida. Escolha uma opcao\n" );
            break;
    }
}

void main () {
    No *ptrLista;
    init ( ptrLista );
    menu ( ptrLista );
}
