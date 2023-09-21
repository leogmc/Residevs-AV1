#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* PROTÓTIPOS DAS FUNÇÕES */

void exibirMenuOpcoesRoteiro(void);
void inserirRoteiro(vector<Roteiro> &roteiros);
int excluirRoteiro(vector<Roteiro> &roteiros);
int alterarRoteiro(vector<Roteiro> &roteiros);
int listarRoteiros(vector<Roteiro> &roteiros);
int localizarRoteiro(vector<Roteiro> &roteiros);

/* FUNÇÃO PRINCIPAL */ 

int executarModuloRoteiros (void) 
{
    // inicializando vetores
    vector<Roteiro> roteiros;

    int opcao_usuario = 0;

    do {
        exibirMenuOpcoesRoteiro();
        cin >> opcao_usuario;
        
        cout << endl; 

        switch (opcao_usuario)
        {
            case 0:
                cout << "Aviso: Fim do programa!";
                break;
            case 1: //inserir
            {
                inserirRoteiro(roteiros);
                break;
            }
            case 2: //excluir
            {
                if ( excluirRoteiro(roteiros) )
                {
                    cout << "Aviso: Código inválido ou inexistente." << endl;
                }
                break;
            }
            case 3: //alterar
            {
                if (alterarRoteiro(roteiros))
                {
                    cout << "Aviso: Código inválido ou inexistente." << endl;
                }
                break;
            }
            case 4: //listar
            {
                if ( listarRoteiros(roteiros) )
                {
                    cout << "Não há nenhum roteiro registrado." << endl;
                }
                break;
            }
                
            case 5: //localizar
                if (localizarRoteiro(roteiros))
                {
                    cout << "Aviso: Código inválido ou inexistente." << endl;
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

void exibirMenuOpcoesRoteiro(void) 
{
    cout << "\nROTEIROS: MENU DE OPÇÕES - Digite um número" << endl <<
    LINHA << endl <<
    "1. Incluir;" << endl <<
    "2. Excluir;" << endl <<
    "3. Alterar (apenas por código);" << endl <<
    "4. Listar;" << endl <<
    "5. Localizar (por código);" << endl <<
    "0. Sair." << endl << endl <<
    "Número: ";
}

void inserirRoteiro(vector<Roteiro> &roteiros)
{
    cout << "OPÇÃO - INSERIR ROTEIRO" << endl
    << LINHA << endl;

    Roteiro roteiro;
    Data data;
    bool flag;

    // pedir código e validá-lo
    do {
        cout << "Código: ";
        cin >> roteiro.codigo;

        if( isdigit(roteiro.codigo) != 0 || !pegarIndicePorCodigo(roteiros, roteiro.codigo) ) 
        {
            cout << "Aviso: Código inválido." << endl;
            flag = false;
        }
        else {
            flag = true;
        }
    } while (!flag);

    // pegar data e validá-la
    do {
        cout << "Data prevista:" << endl <<
        "Dia - "; //se menor de idade, pedir num autorizacao
        cin >> data.dia;
        cout << "Mês - ";
        cin >> data.mes;
        cout << "Ano - ";
        cin >> data.ano;

        if ( !validarData(data) ) {
            cout << "Aviso: Data inválida." << endl;
            flag = false;
        }
        else { 
            
            flag = true;
            roteiro.data_prevista = transformarDataParaString(data);
        }
    } while ( !validarData(data) );

    // pedir hora e validá-la
    do {
        cout << "Hora: ";
        cin >> roteiro.hora_prevista;

        if( isdigit(roteiro.codigo) != 0 ) 
        {
            cout << "Aviso: Hora inválida." << endl;
            flag = false;
        }
        else {
            flag = true;
        }
    } while (!flag);

    // pedir duração e validá-la
    do {
        cout << "Duração: ";
        cin >> roteiro.duracao_prevista;

        if( isdigit(roteiro.duracao_prevista) != 0 ) 
        {
            cout << "Aviso: Duração inválida." << endl;
            flag = false;
        }
        else {
            flag = true;
        }
    } while (!flag);

    // pedir origem e verificar se está vazio ou não
    do {
        cout << "Origem: ";
        cin.ignore();
        getline(cin, roteiro.origem);

        if (roteiro.origem.empty())
        {
            cout << "Aviso: Campo vazio. Favor inserir algum valor." << endl;
            flag = false;
        }
        else {
            flag = true;
        }
    } while (!flag);

    // pedir destino e verificar se está vazio ou não
    do {
        cout << "Destino: ";
        //cin.ignore();
        getline(cin, roteiro.destino);

        if (roteiro.destino.empty())
        {
            cout << "Aviso: Campo vazio. Favor inserir algum valor." << endl;
            flag = false;
        }
        else {
            flag = true;
        }
    } while (!flag);

    // inserir dados do passageiro na coleção
    roteiros.push_back(roteiro);
}

int excluirRoteiro(vector<Roteiro> &roteiros) 
{
    cout << "OPÇÃO - EXCLUIR ROTEIRO" << endl
    << LINHA << endl;

    int codigo = pedirCodigo("excluído"); 

    int indice_roteiro = pegarIndicePorCodigo(roteiros, codigo);

    if (indice_roteiro == -1)
    {
        return 1;
    }
    else {
        vector<Roteiro>::iterator it;
        it = roteiros.begin();
        advance(it, indice_roteiro);
        roteiros.erase(it);
    }

    return 0;    
}

int alterarRoteiro(vector<Roteiro> &roteiros)
{
    cout << "OPÇÃO - ALTERAR ROTEIRO" << endl
    << LINHA << endl;

    int codigo = pedirCodigo("alterado");

    int indice_roteiro = pegarIndicePorCodigo(roteiros, codigo);

    if (indice_roteiro == -1)
    {
        return 1;
    }
    else 
    {
        Roteiro roteiro = roteiros[indice_roteiro];

        cout << 
        "Código: " << roteiro.codigo << endl <<
        "Data prevista: " << roteiro.data_prevista << endl <<
        "Hora prevista: " << roteiro.hora_prevista << endl <<
        "Duração prevista: " << roteiro.hora_prevista << endl <<
        "Origem: " << roteiro.origem << endl <<
        "Destino: " << roteiro.destino << endl <<
        LINHA << endl;

        string flag;

        //código
        cout << "Deseja alterar o código (s/n)? ";
        cin >> flag;

        if (flag == "s")
        {
            do {
                cout << "Código: ";
                cin >> roteiros[indice_roteiro].codigo;
            } while ( !pegarIndicePorCodigo(roteiros, roteiros[indice_roteiro].codigo == -1) );
        }

        //data
        cout << "Deseja alterar a data prevista (s/n)? ";
        cin >> flag;

        if (flag == "s")
        {
            Data data_prevista;

            cout << "Dia - ";
            cin >> data_prevista.dia;
            cout << "Mês - ";
            cin >> data_prevista.mes;
            cout << "Ano - ";
            cin >> data_prevista.ano;

            if (!validarData(data_prevista))
            {
                cout << "Aviso: Data inválida. Tente novamente.";
            }
            else {
                roteiros[indice_roteiro].data_prevista = transformarDataParaString(data_prevista);
            }
        }

        //hora
        cout << "Deseja alterar a hora prevista (s/n)? ";
        cin >> flag;

        if (flag == "s")
        {
            do {
                cout << "Hora prevista: ";
                cin >> roteiros[indice_roteiro].hora_prevista;
            } while ( !pegarIndicePorCodigo(roteiros, roteiros[indice_roteiro].hora_prevista == -1) );
        }

        //duração
        cout << "Deseja alterar a duração prevista (s/n)? ";
        cin >> flag;

        if (flag == "s")
        {
            do {
                cout << "Duração prevista: ";
                cin >> roteiros[indice_roteiro].duracao_prevista;
            } while ( !pegarIndicePorCodigo(roteiros, roteiros[indice_roteiro].duracao_prevista == -1) );
        }

        // origem
        cout << "Deseja alterar a origem (s/n)? ";
        cin >> flag;

        if (flag == "s")
        {
            do {
                cout << "Origem: ";
                cin.ignore();
                getline(cin, roteiros[indice_roteiro].origem);
            } while ( roteiros[indice_roteiro].origem.empty() );
        }

        // destino
        cout << "Deseja alterar o destino (s/n)? ";
        cin >> flag;

        if (flag == "s")
        {
            do {
                cout << "Destino: ";
                cin.ignore();
                getline(cin, roteiros[indice_roteiro].destino);
            } while ( roteiros[indice_roteiro].destino.empty() );
        }
    }

    return 0; 
}

int listarRoteiros(vector<Roteiro> &roteiros) 
{
    cout << "OPÇÃO - LISTAR ROTEIROS REGISTRADOS" << endl <<
    LINHA << endl;

    int i = 0;

    // verificar se tem roteiro
    if (roteiros.size() == 0)
    {
        return 1;
    }
    else 
    {
        for (Roteiro roteiro: roteiros)
        {
            i++;
            
            cout << "Roteiro " << i << endl <<
            "Código: " << roteiro.codigo << endl <<
            "Data prevista: " << roteiro.data_prevista << endl <<
            "Hora prevista: " << roteiro.hora_prevista << endl <<
            "Duração prevista: " << roteiro.duracao_prevista << endl <<
            "Origem: " << roteiro.origem << endl <<
            "Destino: " << roteiro.destino << endl <<
            LINHA << endl;
        }
        cout << "Total de roteiros: " << i << endl;
    }

    return 0;
}

int localizarRoteiro(vector<Roteiro> &roteiros) 
{
    cout << "OPÇÃO - LOCALIZAR ROTEIRO" << endl
    << LINHA << endl;

    int codigo = pedirCodigo("localizado");

    int indice_roteiro = pegarIndicePorCodigo(roteiros, codigo);

    if (indice_roteiro == -1)
    {
        return 1;
    }
    else 
    {
        Roteiro roteiro = roteiros[indice_roteiro];

        cout << "Código: " << roteiro.codigo << endl <<
        "Data prevista: " << roteiro.data_prevista << endl <<
        "Hora prevista: " << roteiro.hora_prevista << endl <<
        "Duração prevista: " << roteiro.duracao_prevista << endl <<
        "Origem: " << roteiro.origem << endl <<
        "Destino: " << roteiro.destino << endl <<
        LINHA << endl;
    }

    return 0;
}