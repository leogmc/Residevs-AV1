#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Passageiro {
    string cpf;
    string nome;
    string dtnascimento;
    string numAutorizacao;
};

struct Roteiro {
    int codigo;
    string dataHora;
    string duracao;
    string origem;
    string destino;
};

void systemPause();

void systemClear();

void incluir(vector<Passageiro> &listaPassageiros);

void excluir(vector<Passageiro> &listaPassageiros);

void alterar(string cpf);

void listar(vector<Passageiro> &listaPassageiros);

void localizar(string cpf);

void menu(vector<Passageiro> &listaPassageiros);

int main(void) {
    vector<Passageiro> listaPassageiros;

    menu(listaPassageiros);
    return 0;
}

void menu(vector<Passageiro> &listaPassageiros) {
    int opcao;

    cout << "\n###### TransPaGente Ltda ######\n";

    cout << "\nSelecione uma opção:\n";

    cout << "[ 1 ] Incluir" << endl;
    cout << "[ 2 ] Excluir" << endl;
    cout << "[ 3 ] Alterar" << endl;
    cout << "[ 4 ] Listar" << endl;
    cout << "[ 5 ] Localizar" << endl;
    cout << "[ 0 ] Sair" << endl;

    cin >> opcao;
    cout << endl;

    switch (opcao)
    {
        case 1:
            incluir(listaPassageiros);
            menu(listaPassageiros);
            break;
        
        case 2:
            excluir(listaPassageiros);
            break;

        case 4:
            listar(listaPassageiros);
            menu(listaPassageiros);
            break;
        
        default:
            break;
    }
}

void incluir(vector<Passageiro> &listaPassageiros) {
    Passageiro passageiro;

    cout << "\n###### Incluir passageiros ######\n";
    
    cout << "Nome: ";
    cin >> passageiro.nome;
    cout << endl;

    cout << "CPF: ";
    cin >> passageiro.cpf;
    cout << endl;

    cout << "Data nascimento: ";
    cin >> passageiro.dtnascimento;
    cout << endl;

    cout << "Numero de autorização: ";
    cin >> passageiro.numAutorizacao;
    cout << endl << endl;

    listaPassageiros.push_back(passageiro);
}

void excluir(vector<Passageiro> &listaPassageiros) {
    int tamanho = listaPassageiros.size();

    cout << "\n###### Passageiros cadastrados ######\n\n";
    cout << "\n###### Excluir passageiros ######\n";

    if (tamanho > 0)
    {
        cout << "codigo\t\tCPF\t\tNome" << endl; 
        for (int i = 0; i < tamanho; i++)
        {
            cout << "[ " << i << " ]";
            cout << "\t\t" << listaPassageiros[i].nome;
            cout << "\t\t" << listaPassageiros[i].cpf;

            cout << endl;
        }

        cout << "Passageiros encontrados: " << listaPassageiros.size() << endl;
        cout << endl << endl;
    }
    else
    {
        cout << "\nNão existem dados para serem exibidos.\n";
    }
}

void listar(vector<Passageiro> &listaPassageiros) {
    cout << "\n###### Listar passageiros ######\n";

    if (listaPassageiros.size() > 0)
    {
        for (Passageiro passageiro : listaPassageiros)
        {
            cout << "Nome: " << passageiro.nome << endl;
            cout << "CPF: " << passageiro.cpf << endl;
            cout << "Data nascimento: " << passageiro.dtnascimento << endl;
            cout << "Número de autorização: " << passageiro.numAutorizacao << endl;

            cout << endl << endl;
        }

        cout << "Passageiros encontrados: " << listaPassageiros.size() << endl;
        cout << endl << endl;
    }
    else
    {
        cout << "\nNão existem dados para serem exibidos.\n";
    }
}

void systemPause() {
    cout << "\nPressione ENTER para continuar...\n";
    cin.sync();
    cin.get();
}

void systemClear() {
    system("echo ''") != 0 ? system("clear") : system("cls");
}