#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;
struct Passageiro
{
    string cpf;
    string nome;
    string dtNascimento;
    int numAutorizacao;
};

//FUNÇÕES AUXILIARES
string formatarData(int dia, int mes, int ano) // função que transforma a data de int para string no formato dd/mm/aaaa
{
    string diaString = to_string(dia),
           mesString = to_string(mes),
           anoString = to_string(ano);
    if (dia < 10)
    {
        diaString = "0" + to_string(dia);
    }
    if (mes < 10)
    {
        mesString = "0" + to_string(mes);
    }
    return diaString + "/" + mesString + "/" + anoString;
}
bool validarData(int dia, int mes, int ano) // Função validadora de datas
{
    if (dia < 1 || dia > 31)
    {
        cout << "Dia inválido. O dia deve estar entre 1 e 31." << endl;
        return false;
    }

    if (mes < 1 || mes > 12)
    {
        cout << "Mês inválido. O mês deve estar entre 1 e 12." << endl;
        return false;
    }

    if (ano < 1900 || ano > 2023) // Ano atual: 2023
    {
        cout << "Ano inválido. O ano deve estar entre 1900 e 2023." << endl;
        return false;
    }
    return true;
}

// Compara dois passageiros pelo CPF
bool compararPorCPF(const Passageiro &a, const Passageiro &b)
{
    return a.cpf < b.cpf;
}

int encontrarPassageiro(vector<Passageiro> passageiros)
{
    string referencia;

    cout << "CPF do passageiro procurado: ";
    cin >> referencia;

    for (vector<Passageiro>::size_type i = 0; i < passageiros.size(); i++)
    {
        if (passageiros[i].cpf == referencia)
        {
            // Encontrou o passageiro com o CPF especificado
            cout << "Passageiro que possui o CPF " << referencia << " encontrado!" << endl;
            return i; // Retorna o índice dele na lista
        }
        else if (passageiros[i].cpf > referencia)
        {
            // Chegou a um passageiro com CPF maior, o passageiro não está na lista
            cout << "Passageiro que possui o CPF " << referencia << " não encontrado." << endl;
            return -1; // Passageiro não encontrado
        }
    }

    // Se o loop terminar sem encontrar o passageiro, significa que ele não está na lista
    cout << "Passageiro com CPF " << referencia << " não encontrado." << endl;
    return -1; // Passageiro não encontrado
}


void menuPassageiro(){
    cout << "     TransPaGente - Menu passageiro" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "[1] - Incluir um Novo Passageiro"<< endl;
    cout << "[2] - Excluir um Passageiro inserido"<< endl;
    cout << "[3] - Alterar (apenas por CPF)"<< endl;
    cout << "[4] - Listar " << endl; 
    cout << "[5] - Localizar Passageiro(Por CPF)" << endl;
    cout << "[0] - Sair" <<endl;
    cout << "Digite uma opção: ";
}

//FUNÇÕES PRINCIPAIS 

//função de incluir um passageiro.
bool incluirPassageiro(vector<Passageiro> &passageiros)
{
    int verifica_idade;

    cout << "--- Inclusão de Passageiro ---" << endl;

    Passageiro passageiro;
    int dia, mes, ano;

    cout << "Insira o CPF do passageiro (Apenas números): ";
    cin >> passageiro.cpf;

    cout << "Insira o nome do passageiro: ";
    cin >> passageiro.nome;

    cout << "Insira o dia de nascimento do passageiro: ";
    cin >> dia;

    cout << "Insira o mês de nascimento do passageiro: ";
    cin >> mes;

    cout << "Insira o ano de nascimento do passageiro: ";
    cin >> ano;

    if (!validarData(dia, mes, ano)) // caso a data esteja inválida.
    {
        return false;
    }

    passageiro.dtNascimento = formatarData(dia, mes, ano); // os valores que antes eram int, são convertidos no tipo string.

    cout << "O passageiro é menor de idade? digite [1] para SIM ou [Qualquer outra tecla] para NÃO: ";
    cin >> verifica_idade;
    cout << "*Importante: No momento da compra, deve-se solicitar o documento de identificação para comprovação.";

    if (verifica_idade == 1){
    cout << "Insira o número de autorização do responsável: ";
    cin >> passageiro.numAutorizacao;
    cout << "Cadastro realizado com sucesso!" << endl;
    } else {
    cout << "Cadastro realizado com sucesso!" << endl;
    }

    // Encontra a posição correta para inserir o passageiro com base no CPF
    auto it = lower_bound(passageiros.begin(), passageiros.end(), passageiro, compararPorCPF);

    // Inserindo o passageiro na posição encontrada
    passageiros.insert(it, passageiro);
    
    return true; // O passageiro foi adicionado sem problemas 
}

//função de excluir um passageiro.
bool excluirPassageiro(vector<Passageiro> &passageiros){

    cout << "--- exclusão de Passageiro ---" << endl;
    int posicao = encontrarPassageiro(passageiros); //A variável "posicao" recebe o indice no qual o CPF está (caso seja positivo).

    if (posicao == -1) // Ocorre quando a função "encontrarPassageiro" não encontra o CPF inserido pelo usuário e retorna
    {
        return false;
    }
    else
    {
        passageiros.erase(passageiros.begin() + posicao);
        cout << "Passageiro excluído." << endl;
        return true;
    }

    return false; // O passageiro informado não existe.
}

//função de localizar um passageiro específico.
bool localizarPassageiro(vector<Passageiro> passageiros){
int posicao = encontrarPassageiro(passageiros);

    if (posicao == -1) // CPF informado não está na coleção.
    {
        return false;
    }
    else
    {
        cout << "Nome: " << passageiros[posicao].nome << endl;
        cout << "CPF: " << passageiros[posicao].cpf << endl;
        cout << "Data de nascimento: " << passageiros[posicao].dtNascimento << endl;
        cout << "Número de autorização: " << passageiros[posicao].numAutorizacao << endl;

        return true; // Passageiro encontrado e informações puderam ser impressas na tela.
    }
}

//função de alterar os dados de um passageiro.
void alterarPassageiro(vector<Passageiro> &passageiros){

    int posicao = encontrarPassageiro(passageiros);
    char resposta;
    if (posicao == -1)
    {
        return; //Sai da função.
    }
    else
    {
        int decisao;
        cout << "Insira o número correspondente a informação que deseja alterar ( Entre [1] e [4] ) ou qualquer outro para voltar: " << endl;
        do
        {
            cout << "---" << endl;

            cout << "[1] - Nome" << endl;
            cout << "[2] - CPF" << endl;
            cout << "[3] - Data de nascimento" << endl;
            cout << "[4] - Número de autorização" << endl;
            cout << "Opção: ";
            cin >> decisao;

            switch (decisao)
            {
            case 1:
                cin.ignore();
                getline(cin, passageiros[posicao].nome);
                break;
            case 2:
                cout << "Novo CPF: ";
                cin >> passageiros[posicao].cpf;
                break;
            case 3:
                int dia, mes, ano;
                cout << "Novo dia de nascimento: ";
                cin >> dia;
                cout << "Novo mês de nascimento: ";
                cin >> mes;
                cout << "Novo ano de nascimento: ";
                cin >> ano;
                if (!validarData(dia, mes, ano)) // Se data estiver inválida.
                {
                    break;
                }
                else
                {
                    passageiros[posicao].dtNascimento = formatarData(dia, mes, ano); // Se a data estiver válida.
                }
                break;
            case 4:
                cout << "Novo número de autorização: ";
                cin >> passageiros[posicao].numAutorizacao;
                break;
            default:
                cout << "Campo não reconhecido. Nenhuma alteração foi feita." << endl;
                break;
            }

            cout << "Deseja altera outro dado? (s/n)";
            cin >> resposta;

        } while (resposta == 's' || resposta == 'S');
    }
}

//função de listar todos os passageiros.
void listarPassageiros(vector<Passageiro> passageiros){

    int contador_passageiros = 0;

    for (vector<Passageiro>::size_type posicao = 0; posicao < passageiros.size(); posicao++)
    {
        cout << "--------------------------------->>" << endl;
        cout << "Nome: " << passageiros[posicao].nome << endl;
        cout << "CPF: " << passageiros[posicao].cpf << endl;
        cout << "Data de nascimento: " << passageiros[posicao].dtNascimento << endl;
        cout << "Número de autorização do responsável: " << passageiros[posicao].numAutorizacao << endl;

        contador_passageiros++;
    }

  if (contador_passageiros == 0)
    {
        cout << "(sem passageiros na lista.)" << endl;
    }
    else
    {   
        cout << endl << "Quantidade de passageiros: " << contador_passageiros << endl;
    }    
}

//menu de opcoes.
int gestaoPassageiro(vector<Passageiro> &passageiros){

    bool validar = true;
    int op;

    do{
        menuPassageiro();
        cin >> op;
        switch (op){
            case 1:
                    incluirPassageiro(passageiros);
                break;
            case 2:
                    excluirPassageiro(passageiros);
                break;
            case 3:
                    alterarPassageiro(passageiros);
                break;
            case 4: 
                    listarPassageiros(passageiros);
                break;
            case 5:
                    localizarPassageiro(passageiros);
                break;
            case 0:
                validar = false;
                break;
            default:
                cout << "Opção Invalida!" <<endl;
                break;
        }
    } while (validar == true);
    return 0;
}
