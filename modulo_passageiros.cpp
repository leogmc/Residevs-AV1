#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* PROTÓTIPOS DAS FUNÇÕES */

void exibirMenuOpcoesPassageiro(void);
void inserirPassageiro(vector<Passageiro> &passageiros);
int excluirPassageiro(vector<Passageiro> &passageiros);
int alterarPassageiro(vector<Passageiro> &passageiros);
int listarPassageiros(vector<Passageiro> &passageiros);
int localizarPassageiro(vector<Passageiro> &passageiros);

/* FUNÇÃO PRINCIPAL */ 

int executarModuloPassageiros (void) 
{
    // inicializando vetores
    vector<Passageiro> passageiros;

    int opcao_usuario = 0;

    do {
        exibirMenuOpcoesPassageiro();
        cin >> opcao_usuario;
        
        cout << endl; 

        switch (opcao_usuario)
        {
            case 0:
                cout << "Aviso: Fim do programa!";
                break;
            case 1: //inserir
            {
                inserirPassageiro(passageiros);
                break;
            }
            case 2: //excluir
            {
                if(excluirPassageiro(passageiros))
                {
                    cout << "Aviso: CPF inválido ou inexistente." << endl;
                }
                break;
            }
            case 3: //alterar
            {
                if(alterarPassageiro(passageiros))
                {
                    cout << "Aviso: CPF inválido ou inexistente." << endl;
                }
                break;
            }
            case 4: //listar
            {
                if ( listarPassageiros(passageiros) )
                {
                    cout << "Não há nenhum passageiro registrado." << endl;
                }
                break;
            }
                
            case 5: //localizar
                if (localizarPassageiro(passageiros))
                {
                    cout << "Aviso: CPF inválido ou inexistente." << endl;
                }
                break;
            
            default:
                cout << "Aviso: Insira um dos números válidos." << endl;
                break;
        }
    } while (opcao_usuario != 0);

    return 0;
}

/* FUNÇÕES */

void exibirMenuOpcoesPassageiro(void) 
{
    cout << "\nPASSAGEIROS: MENU DE OPÇÕES - Digite um número" << endl <<
    LINHA << endl <<
    "1. Incluir;" << endl <<
    "2. Excluir;" << endl <<
    "3. Alterar (apenas por CPF);" << endl <<
    "4. Listar;" << endl <<
    "5. Localizar (por CPF);" << endl <<
    "0. Sair." << endl << endl <<
    "Número: ";
}

void inserirPassageiro(vector<Passageiro> &passageiros)
{
    cout << "OPÇÃO - INSERIR PASSAGEIRO" << endl
    << LINHA << endl;

    Passageiro pessoa;
    Data data;
    bool flag;

    // pedir CPF e verificar validade do CPF
    do {
        cout << "CPF: ";
        cin >> pessoa.cpf;

        if( !validarCPF(pessoa.cpf) || !pegarIndicePorCPF(passageiros, pessoa.cpf) == -1 ) 
        {
            cout << "Aviso: CPF inválido ou já existente." << endl;
            flag = false;
        }
        else {
            flag = true;
        }
    } while (!flag);

    // pedir nome e verificar se está vazio ou não
    do {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, pessoa.nome);

        if (pessoa.nome.empty())
        {
            cout << "Aviso: Campo vazio. Favor inserir algum valor." << endl;
            flag = false;
        }
        else {
            flag = true;
        }
    } while (!flag);

    do {
        cout << "Data de nascimento:" << endl <<
        "Dia - "; //se menor de idade, pedir num autorizacao
        cin >> data.dia;
        cout << "Mês - ";
        cin >> data.mes;
        cout << "Ano - ";
        cin >> data.ano;

        if ( !validarData(data) ) {
            cout << "Aviso: Data de nascimento inválida." << endl;
            flag = false;
        }
        else { 
            flag = true;
            pessoa.data_nascimento = transformarDataParaString(data);
        }
    } while ( !validarData(data) );
    
    // verificar se é maior de idade. se não for, adicionar 0
    if (!verificarMaioridade(data)) {
        cout << "Número de autorização: "; 
        cin >> pessoa.num_autorizacao;

    } else {
        pessoa.num_autorizacao = 0;
    }

    // inserir dados do passageiro na coleção
    passageiros.push_back(pessoa);
}

int excluirPassageiro(vector<Passageiro> &passageiros) 
{
    cout << "OPÇÃO - EXCLUIR PASSAGEIRO" << endl
    << LINHA << endl;

    string cpf = pedirCPF("excluído"); 

    int indice_passageiro = pegarIndicePorCPF(passageiros, cpf);

    if (indice_passageiro == -1)
    {
        return 1;
    }
    else {
        vector<Passageiro>::iterator it;
        it = passageiros.begin();
        advance(it, indice_passageiro);
        passageiros.erase(it);
    }

    return 0;    
}

int alterarPassageiro(vector<Passageiro> &passageiros)
{
    cout << "OPÇÃO - ALTERAR PASSAGEIRO" << endl
    << LINHA << endl;

    string cpf = pedirCPF("alterado");

    int indice_passageiro = pegarIndicePorCPF(passageiros, cpf);

    if (indice_passageiro == -1)
    {
        return 1;
    }
    else 
    {
        Passageiro passageiro = passageiros[indice_passageiro];

        cout << 
        "CPF: " << passageiro.cpf << endl <<
        "Nome: " << passageiro.nome << endl <<
        "Data de nascimento: " << passageiro.data_nascimento  << endl <<
        "Número de autorização: " << passageiro.num_autorizacao << endl <<
        LINHA << endl;

        string flag;
        bool maior_de_idade = true;

        cout << "Deseja alterar o CPF (s/n)? ";
        cin >> flag;

        if (flag == "s")
        {
            do {
                cout << "CPF: ";
                cin >> passageiros[indice_passageiro].cpf;
            } while ( !validarCPF(passageiros[indice_passageiro].cpf) || !pegarIndicePorCPF(passageiros, passageiros[indice_passageiro].cpf) == -1 );
        }

        cout << "Deseja alterar o nome (s/n)? ";
        cin >> flag;

        if (flag == "s")
        {
            cout << "Nome: ";
            cin.ignore();
            getline(cin, passageiros[indice_passageiro].nome);
        }

        cout << "Deseja alterar a data de nascimento (s/n)? ";
        cin >> flag;

        if (flag == "s")
        {
            Data data_nascimento;

            cout << "Dia - ";
            cin >> data_nascimento.dia;
            cout << "Mês - ";
            cin >> data_nascimento.mes;
            cout << "Ano - ";
            cin >> data_nascimento.ano;

            if (!validarData(data_nascimento))
            {
                cout << "Aviso: Data inválida. Tente novamente.";
            }
            else {
                passageiros[indice_passageiro].data_nascimento = transformarDataParaString(data_nascimento);
                maior_de_idade = verificarMaioridade(data_nascimento);
            }
        }

        if (!maior_de_idade) 
        {
            cout << "Deseja alterar o número de autorização (s/n)? ";
            cin >> flag;

            if (flag == "s")
            {
                cout << "Número de autorização: ";
                cin >> passageiros[indice_passageiro].num_autorizacao;
            }
        }   
    }

    return 0; 
}

int listarPassageiros(vector<Passageiro> &passageiros) 
{
    cout << "OPÇÃO - LISTAR PASSAGEIROS REGISTRADOS" << endl <<
    LINHA << endl;

    int i = 0;

    // verificar se tem passageiro
    if (passageiros.size() == 0)
    {
        return 1;
    }
    else 
    {
        for (Passageiro passageiro: passageiros)
        {
            i++;
            
            cout << "Passageiro " << i << endl <<
            "CPF: " << passageiro.cpf << endl <<
            "Nome: " << passageiro.nome << endl <<
            "Data de nascimento: " << passageiro.data_nascimento  << endl <<
            "Número de autorização: " << passageiro.num_autorizacao << endl <<
            LINHA << endl;
        }
        cout << "Total de passageiros: " << i << endl;
    }

    return 0;
}

int localizarPassageiro(vector<Passageiro> &passageiros) 
{
    cout << "OPÇÃO - LOCALIZAR PASSAGEIRO" << endl
    << LINHA << endl;

    string cpf = pedirCPF("localizado");

    int indice_passageiro = pegarIndicePorCPF(passageiros, cpf);

    if (indice_passageiro == -1)
    {
        return 1;
    }
    else 
    {
        Passageiro passageiro = passageiros[indice_passageiro];

        cout << 
        "CPF: " << passageiro.cpf << endl <<
        "Nome: " << passageiro.nome << endl <<
        "Data de nascimento: " << passageiro.data_nascimento  << endl <<
        "Número de autorização: " << passageiro.num_autorizacao << endl <<
        LINHA << endl;
    }

    return 0;
}