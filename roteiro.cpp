#include <iostream>
#include <string>
#include <vector>

using namespace std;
void menuRoteiro();
struct Roteiro
{
   int codigo;
   string data;
   int hora;
   int duracao;
   string origem;
   string destino;
};

//FUNÇÕES AUXILIARES
string formatarData(int dia, int mes, int ano);
bool validarData(int dia, int mes, int ano);

bool compararPorCodigo(const Roteiro &a, const Roteiro &b)
{
    return a.codigo < b.codigo;
}

int encontrarRoteiro(vector<Roteiro> roteiros)
{
    int referencia;

    cout << "Código do roteiro procurado: ";
    cin >> referencia;

    for (vector<Roteiro>::size_type i = 0; i < roteiros.size(); i++)
    {
        if (roteiros[i].codigo == referencia)
        {
            // Encontrou o roteiro com o código especificado
            cout << "Roteiro que possui o código " << referencia << " encontrado!" << endl;
            return i; // Retorna o índice dele na lista
        }
        else if (roteiros[i].codigo > referencia)
        {
            // Chegou a um roteiro com código maior, o roteiro não está na lista
            cout << "Roteiro que possui o código " << referencia << " não encontrado." << endl;
            return -1; // Roteiro não encontrado
        }
    }
    return 0;
}


//FUNÇÕES PRINCIPAIS

//Função que adiciona um novo roteiro.
void incluirRoteiro(vector<Roteiro> &roteiros)
{
    cout << "--- Inclusão de Roteiro ---" << endl;

    Roteiro roteiro;
    int dia, mes, ano;

    cout << "Insira o código do roteiro: (Apenas números) ";
    cin >> roteiro.codigo;

    cout << "Insira o dia previsto: ";
    cin >> dia;

    cout << "Insira o mês previsto: ";
    cin >> mes; 

    cout << "Insira o ano previsto: ";
    cin >> ano; 

    cout << "Insira a hora prevista: ";
    cin >> roteiro.hora;

    cout << "Insira a duração prevista: ";
    cin >> roteiro.duracao;

    cout << "Insira a origem: ";
    cin >> roteiro.origem;

    cout << "Insira o destino: ";
    cin >> roteiro.destino;

    if (!validarData(dia, mes, ano)) // caso a data esteja inválida, seja o dia, mês ou ano.
    {
        return;
    }
    roteiro.data = formatarData(dia, mes, ano); // os valores que antes eram int, são convertidos no tipo string.
    cout << "Cadastro realizado com sucesso!";

      // Encontrando a posição correta para inserir o roteiro com base no código
    auto it = lower_bound(roteiros.begin(), roteiros.end(), roteiro, compararPorCodigo);

    // Inserindo o roteiro na posição encontrada
    roteiros.insert(it, roteiro); 

   return;  
}

//Função de excluir um roteiro.
bool excluirRoteiro(vector<Roteiro> &roteiros){

    cout << "--- exclusão de Roteiro ---" << endl;

    int posicao = encontrarRoteiro(roteiros); //A variável "posicao" recebe o indice no qual o código está (caso seja positivo).

    if (posicao == -1) // Ocorre quando a função "encontrarRoteiro" não encontra o código inserido pelo usuário e retorna
    {
        return false;
    }
    else
    {
        roteiros.erase(roteiros.begin() + posicao);
        cout << "Roteiro excluído." << endl;
        return true;
    }
    return false; // O roteiro informado não existe.
}

//função de alterar os dados de um roteiro.
void alterarRoteiro(vector<Roteiro> &roteiros){

    int posicao = encontrarRoteiro(roteiros);
    char resposta;

    if (posicao == -1)
    {
        return; //Sai da função.
    }
    else
    {
        int decisao;

        cout << "Insira o número correspondente a informação que deseja alterar ( Entre [1] e [6] ) ou qualquer outro para voltar: " << endl;

        do
        {
            cout << "-------------------------------" << endl;

            cout << "[1] - Código" << endl;
            cout << "[2] - Data prevista" << endl;
            cout << "[3] - Hora prevista" << endl;
            cout << "[4] - Duração prevista" << endl;
            cout << "[5] - Origem" << endl;
            cout << "[6] - Destino" << endl;

            cout << "Opção: ";
            cin >> decisao;

            switch (decisao)
            {
            case 1:
                cout << "Novo código: ";
                cin >> roteiros[posicao].codigo;
                break;
            case 2:
                int dia, mes, ano;
                cout << "Novo dia previsto: ";
                cin >> dia;
                cout << "Novo mês previsto: ";
                cin >> mes;
                cout << "Novo ano previsto: ";
                cin >> ano;
                if (!validarData(dia, mes, ano)) // Se data estiver inválida.
                {
                    break;
                }
                else
                {
                    roteiros[posicao].data = formatarData(dia, mes, ano); // Se a data estiver válida.
                }
                break;
            case 3:
            cout << "Nova hora prevista: ";
                cin >> roteiros[posicao].hora;
                break;
               
            case 4:
                cout << "Nova duração prevista: ";
                cin >> roteiros[posicao].duracao;
                break;

            case 5:
                cout << "Nova origem: ";
                cin >> roteiros[posicao].origem;
                break;
            
            case 6:
                cout << "Novo destino: ";
                cin >> roteiros[posicao].destino;
                break;

            default:
                cout << "Campo não reconhecido. Nenhuma alteração foi feita." << endl;
                break;
            }

            cout << "Deseja altera outro dado? (s/n)";
            cin >> resposta;

        } while (resposta == 's' || resposta == 'S');
    }
    return;
}

//função de listar todos os roteiros.
void listarRoteiros(vector<Roteiro> roteiros){

    for (vector<Roteiro>::size_type posicao = 0; posicao < roteiros.size(); posicao++)
    {
        cout << "--------------------------------->>" << endl;
        cout << "Código: " << roteiros[posicao].codigo << endl;
        cout << "Data prevista: " << roteiros[posicao].data << " às " << roteiros[posicao].hora << "h." << endl;
        cout << "Origem: " << roteiros[posicao].origem << endl;
        cout << "Destino: " << roteiros[posicao].destino << endl;
    }

}

//função de localizar um roteiro específico.
bool localizarRoteiro(vector<Roteiro> roteiros){

int posicao = encontrarRoteiro(roteiros);

    if (posicao == -1) // Código informado não está na coleção.
    {
        return false;
    }
    else
    {
        cout << "Código: " << roteiros[posicao].codigo << endl;
        cout << "Data prevista: " << roteiros[posicao].data << " às " << roteiros[posicao].hora << "h." << endl;
        cout << "Origem: " << roteiros[posicao].origem << endl;
        cout << "Destino: " << roteiros[posicao].destino << endl;

        return true; // Roteiro encontrado e informações puderam ser impressas na tela.
    }
}

//Função principal

void menuRoteiro(){
    cout << "Bem vindo ao app TransPaGente" << endl;
    cout << "[1] - Incluir Roteiro"<< endl;
    cout << "[2] - Excluir Roteiro"<< endl; // pode ser por cpf
    cout << "[3] - Alterar (apenas código)"<< endl; //buscar por cpf
    cout << "[4] - Listar " << endl; //listar o que os pasageiros e seus respectivos roteiro?
    cout << "[5] - Localizar (Por codigo)" << endl;
    cout << "[0] - Sair" <<endl;
    cout << "Digite uma opção:";
    return;
}

int gestaoRoteiro(vector<Roteiro> &roteiros){

    bool validar = true;
    int op;

    do{
        menuRoteiro();
        cin >> op;
        switch (op){
            case 1:
                    //incluir
                    incluirRoteiro(roteiros);
                break;
            case 2:
                    // excluir
                    excluirRoteiro(roteiros);
                break;
            case 3:
                    // Alterar;
                    alterarRoteiro(roteiros);
                break;
            case 4: 
                    // Lista;
                    listarRoteiros(roteiros);
                break;
            case 5:
                    //Localizar(por código);
                    localizarRoteiro(roteiros);
                break;

            case 0:
                validar = false;
                break;
            default:
                cout << "Opção Invalida!!!" <<endl;
                break;
        }
    } while (validar); 
    return 0;
}