#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define char_max 100

menu()
{
    int opcao;

    do{

        printf("1 - Cadastrar paciente");
        printf("2 - Cadastrar medico");
        printf("3 - Cadastrar consulta");
        printf("4 - Relatorio de consultas do dia");
        printf("5 - Historico de consultas do paciente");
        printf("6 - Consultas realizadas pelo medico");
        printf("7 - Sair\n");
        printf("Escolha uma das opcoes acima: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            paciente_cadastrar();
            break;
        case 2:
            medico_cadastrar();
            break;
        case 3:
            consulta_cadastrar();
            break;
        case 4:
            char data[char_max];
            printf("Digite uma data para ver as consultas agendadas: \n");
            printf("DD/MM/AA: \n");
            scanf("%[^\n]", data); //
            break;
        case 5:
            cadastrar_paciente();
            break;
        
        default:
            break;
        }



    }while();
}


int main (void)
{
    menu();
}



