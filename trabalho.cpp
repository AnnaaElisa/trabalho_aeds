#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

//precisa arrumar os horarios para que tenham 30 minutos de diferenca 
//fazer o historico de paciente, medico, consulta e salvar todos os dados quando terminar o programa.


class Paciente {
public:
    int codigoPaciente;
    string nomePaciente;
    string enderecoPaciente;
    long int telefonePaciente;
    string dataNascimentoPaciente;

    Paciente(int cod, string nome, string endereco, long int telefone, string dataNascimento)
        : codigoPaciente(cod), nomePaciente(nome), enderecoPaciente(endereco), telefonePaciente(telefone), dataNascimentoPaciente(dataNascimento) {}
};

class Medico {
public:
    int codigoMedico;
    string nomeMedico;
    long int telefoneMedico;
    string especialidadeMedico;

    Medico(int cod, string nome, long int telefone, string especialidade)
        : codigoMedico(cod), nomeMedico(nome), telefoneMedico(telefone), especialidadeMedico(especialidade) {}
};

class Consulta {
public:
    int codigoConsulta;
    string dataConsulta;
    string horaConsulta;
    int codigoM;
    int codigoP;

    Consulta(int cod, string data, string hora, int codM, int codP)
        : codigoConsulta(cod), dataConsulta(data), horaConsulta(hora), codigoM(codM), codigoP(codP) {}
};

vector<Paciente> pacientes;
vector<Medico> medicos;
vector<Consulta> consultas;

void menu();
void cadastrarPaciente();
void cadastrarMedico();
void salvarArquivoPaciente();
void salvarArquivoMedico();
void cadastrarConsulta();
void salvarArquivoConsulta();
void cancelarConsulta();
void consultasDia();
//void historicoPaciente();
//void historicoMedico();
//void salvar();

void salvarArquivoPaciente() {
    ofstream arquivo("pacientes.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo de pacientes\n";
        return;
    }

    for (const auto& paciente : pacientes) {
        arquivo << "\nCodigo: " << paciente.codigoPaciente << "\n"
                << "Nome: " << paciente.nomePaciente << endl
                << "Telefone: " << paciente.telefonePaciente << endl
                << "Endereco: " << paciente.enderecoPaciente << endl
                << "Data de nascimento: " << paciente.dataNascimentoPaciente << endl;
    }

    arquivo.close();
}

void salvarArquivoMedico() {
    ofstream arquivo("medicos.txt");

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo de medicos\n";
        return;
    }

    for (const auto& medico : medicos) {
        arquivo << "\nCodigo: " << medico.codigoMedico << endl
                << "Nome: " << medico.nomeMedico << endl
                << "Telefone: " << medico.telefoneMedico << endl
                << "Especialidade: " << medico.especialidadeMedico << endl;
    }

    arquivo.close();
}

void salvarArquivoConsulta() {
    ofstream arquivo("consultas.txt");

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo de consultas\n";
        return;
    }

    for (const auto& consulta : consultas) {
        arquivo << "\nCodigo: " << consulta.codigoConsulta << endl
                << "Data: " << consulta.dataConsulta << endl
                << "Hora: " << consulta.horaConsulta << endl
                << "Codigo do Medico: " << consulta.codigoM << endl
                << "Codigo do Paciente: " << consulta.codigoP << "\n";
    }

    arquivo.close();
}

void cadastrarPaciente() {
    int codigo = pacientes.size() + 1;
    string nome, endereco, dataNascimento;
    long int telefone;

    cout << "\nNome do paciente: ";
    getline(cin, nome);

    cout << "Endereco: ";
    getline(cin, endereco);

    cout << "Telefone: ";
    cin >> telefone;
    cin.ignore();

    cout << "Data de nascimento (dd/mm/aa): ";
    getline(cin, dataNascimento);

    Paciente cadastroPaciente(codigo, nome, endereco, telefone, dataNascimento);
    pacientes.push_back(cadastroPaciente);

    salvarArquivoPaciente();

    cout << "\nNovo paciente cadastrado!\n";
    cout <<"O codigo do paciente eh: " << codigo << endl;
}

void cadastrarMedico() {
    int codigo = medicos.size() + 1;
    string nome, especialidade;
    long int telefone;

    cout << "\nNome do medico: ";
    getline(cin, nome);

    cout << "Telefone: ";
    cin >> telefone;
    cin.ignore();

    cout << "Especialidade: ";
    getline(cin, especialidade);

    Medico cadastroMedico(codigo, nome, telefone, especialidade);
    medicos.push_back(cadastroMedico);

    salvarArquivoMedico();

    cout << "\nNovo medico cadastrado!\n";
    cout <<"O codigo do medico eh: " << codigo << endl;
}

void cadastrarConsulta() {
    int codigoConsulta = consultas.size() + 1;
    string data, hora;
    int codigoM, codigoP;
    int consultasMedico = 0;
    bool medicoEncontrado = false;
    bool pacienteEncontrado = false;

    cout << "\nDigite o codigo do medico: ";
    cin >> codigoM;
    cout << "Digite o codigo do paciente: ";
    cin >> codigoP;
    cin.ignore();

    for (const auto& medico : medicos) {
        if (medico.codigoMedico == codigoM) {
            medicoEncontrado = true;
            break;
        }
    }

    if (!medicoEncontrado) {
        cout << "\nMedico nao encontrado\n";
        return;
    }

    for (const auto& paciente : pacientes) {
        if (paciente.codigoPaciente == codigoP) {
            pacienteEncontrado = true;
            break;
        }
    }

    if (!pacienteEncontrado) {
        cout << "\nPaciente nao encontrado\n";
        return;
    }

    cout << "Digite a data da consulta (dd/mm/aa): ";
    getline(cin, data);
    cout << "Digite a hora da consulta: ";
    getline(cin, hora);

    for (const auto& consulta : consultas) {
        if (consulta.codigoM == codigoM && consulta.dataConsulta == data) {
            consultasMedico++;
        }
    }

    if (consultasMedico >= 2) {
        cout << "\nO medico ja tem duas consultas cadastradas nesse dia.\n";
        return;
    }

    Consulta consultaCadastrada(codigoConsulta, data, hora, codigoM, codigoP);
    consultas.push_back(consultaCadastrada);
    salvarArquivoConsulta();
    cout << "\nNova consulta cadastrada.\n";
    cout <<"O codigo da consulta eh: " << codigoConsulta << endl;
}

void consultasDia() {
    string data;

    cout << "\nDigite a data (dd/mm/aa): ";
    cin.ignore();
    getline(cin, data);

    for (const auto& consulta : consultas) {
        if (consulta.dataConsulta == data) {
            cout << "\nConsulta codigo: " << consulta.codigoConsulta << endl
                 << "Hora: " << consulta.horaConsulta << endl
                 << "Medico: " << consulta.codigoM << endl
                 << "Paciente: " << consulta.codigoP << endl;
        }
    }
}

void cancelarConsulta() {
    int codigo;
    cout << "\nDigite o codigo da consulta para cancelar: ";
    cin >> codigo;
    cin.ignore();

    auto it = remove_if(consultas.begin(), consultas.end(), [codigo](Consulta& c) {
        return c.codigoConsulta == codigo;
    });

    if (it != consultas.end()) {
        consultas.erase(it, consultas.end());
        salvarArquivoConsulta();
        cout << "Consulta cancelada\n";
    } else {
        cout << "Consulta nao encontrada.\n";
    }
}

void salvar() {
    salvarArquivoPaciente();
    salvarArquivoMedico();
    salvarArquivoConsulta();
}

void menu() {
    int opcao;

    do {
        cout << endl;
        cout << "1 - Cadastrar paciente\n";
        cout << "2 - Cadastrar medico\n";
        cout << "3 - Cadastrar consulta\n";
        cout << "4 - Consultas do dia\n";
        cout << "5 - Historico de consultas do paciente\n";
        cout << "6 - Historico de consultas do medico\n";
        cout << "7 - Cancelar consulta\n";
        cout << "8 - Sair\n";
        cout << "Escolha uma das opcoes acima: ";
        cin >> opcao; 
        cout << endl;
        cin.ignore();

        switch (opcao) {
        case 1:
            cadastrarPaciente();
            break;
        case 2:
            cadastrarMedico();
            break;
        case 3:
            cadastrarConsulta();
            break;
        case 4:
            consultasDia();
            break;
       /* case 5:
            historicoPaciente();
            break;
        case 6:
            historicoMedico();
            break;*/
        case 7:
            cancelarConsulta();
            break;
        case 8:
            //salvar();
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opcao invalida!\n";    
        }
    } while (opcao != 8);
}

int main() {
    menu();
    return 0;
}
