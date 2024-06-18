#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define char_max 100

paciente_cadastrar();
medico_cadastrar();
consulta_cadastrar();
totalConsultas_dias();
historico_paciente();
historico_medico();

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {

    int codigo;
    char nome [char_max];
    long int telefone;

    Data data_nascimento;

}Paciente;

typedef struct {
    int codigo;
    char nome [char_max];
    long int telefone;
    char especialidade [char_max];
}Medico;

typedef struct{
    int codigoConsulta;
    Data data_consulta;
    int hora;
    int codigoMedico;
    int codigoPaciente;
} Consulta;

void paciente_cadastrar()
{
    Paciente paciente;
    
    printf("Nome: ");
    scanf("%s", paciente.nome); //%[^\n]
}



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
        {
            paciente_cadastrar();
            break;
        }
        case 2:
        {
            medico_cadastrar();
            break;
        }
        case 3:
        {
            consulta_cadastrar();
            break;
        }
        case 4:
        {
             char data[char_max];
            printf("Digite uma data para ver as consultas agendadas: \n");
            printf("DD/MM/AA: \n");
            scanf("[^\n]", data);
            totalConsultas_dia(data);
            break;
        }
        case 5:
        {
            int codigoPaciente;
            printf("Digite o codigo do paciente para ver suas consultas passadas: ");
            scanf("%d", &codigoPaciente);
            historico_paciente(codigoPaciente);
            break;
        }
        case 6:
        {
            int codigoMedico;
            printf("Digite o codigo do medico para ver suas consultas realizadas: ");
            scanf("%d", &codigoMedico);
            historico_medico(codigoMedico);
            break;
        }
        
        case 7:
        {
            printf("Sair\n");
            break;
        }

        default:
        {
            printf("Opcao invalida\n");
            break;
        }

        }

    }while(opcao != 7);
}


int main (void)
{
    menu();
}



