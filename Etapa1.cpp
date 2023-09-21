#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Passageiro {
    string cpf;
    string nome;
    string dtNascimento;
    string numAutorizacao;
};

struct Roteiro {
    string codigo;
    string dataHora;
    string duracao;
    string origem;
    string destino;
};

/**Métodos passageiro*/
void incluir(vector<Passageiro> &listaPassageiros);

void excluir(vector<Passageiro> &listaPassageiros);

void confirmarExclusao(vector<Passageiro> &listaPassageiros, int indice);

void alterar(vector<Passageiro> &listaPassageiros);

void listar(vector<Passageiro> &listaPassageiros);

void localizar(vector<Passageiro> &listaPassageiros);

int buscarPassageiro(vector<Passageiro> &listaPassageiros, string cpf);

void exibirListaPassageiros(vector<Passageiro> &listaPassageiros);

void exibirPassageiroSelecionado(vector<Passageiro> &listaPassageiros, int indice);

void selecionarCampo(vector<Passageiro> &listaPassageiros, int indice);

void menuPassageiros(vector<Passageiro> &listaPassageiros);

void menuIncluir(vector<Passageiro> &listaPassageiros);

void menuExcluir(vector<Passageiro> &listaPassageiros);

void menuAlterar(vector<Passageiro> &listaPassageiros);

/**Métodos roteiro*/
void incluir(vector<Roteiro> &listaRoteiros);

void excluir(vector<Roteiro> &listaRoteiros);

void confirmarExclusao(vector<Roteiro> &listaRoteiros, int indice);

void alterar(vector<Roteiro> &listaRoteiros);

void listar(vector<Roteiro> &listaRoteiros);

void localizar(vector<Roteiro> &listaRoteiros);

int buscarRoteiro(vector<Roteiro> &listaRoteiros, string codigo);

void exibirListaRoteiros(vector<Roteiro> &listaRoteiros);

void exibirRoteiroSelecionado(vector<Roteiro> &listaRoteiros, int indice);

void selecionarCampo(vector<Roteiro> &listaRoteiros, int indice);

void menuRoteiros(vector<Roteiro> &listaRoteiros);

void menuIncluir(vector<Roteiro> &listaRoteiros);

void menuExcluir(vector<Roteiro> &listaRoteiros);

void menuAlterar(vector<Roteiro> &listaRoteiros);

/**Comum*/
void menu();

int sair();

void systemPause();

void systemClear();

void systemPauseAndClear();

int main(void) {
    menu();
    return 0;
}

void menu() {
    vector<Passageiro> listaPassageiros;
    vector<Roteiro> listaRoteiros;
    int opcao;

    systemClear();
    cout << "\n###### TransPaGente Ltda ######\n";

    cout << "\nSelecione uma opção:\n\n";

    cout << "[ 1 ] Menu passageiros" << endl;
    cout << "[ 2 ] Menu roteiros" << endl;
    cout << "[ 0 ] Sair" << endl << endl;

    cout << "Selecione uma opção: ";
    cin >> opcao;
    cout << endl;

    switch (opcao)
    {
        case 0:
            sair();
            break;

        case 1:
            menuPassageiros(listaPassageiros);
            break;
        
        case 2:
            menuRoteiros(listaRoteiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            menu();
            break;
    }
}

/**Métodos passageiro*/
void menuPassageiros(vector<Passageiro> &listaPassageiros) {
    int opcao;

    systemClear();
    cout << "\n###### Menu passageiros ######\n";

    cout << "\nSelecione uma opção:\n\n";

    cout << "[ 1 ] Incluir" << endl;
    cout << "[ 2 ] Excluir" << endl;
    cout << "[ 3 ] Alterar" << endl;
    cout << "[ 4 ] Listar" << endl;
    cout << "[ 5 ] Localizar" << endl;
    cout << "[ 0 ] Sair" << endl << endl;

    cout << "Selecione uma opção: ";
    cin >> opcao;
    cout << endl;

    switch (opcao)
    {
        case 0:
            menu();
            break;

        case 1:
            incluir(listaPassageiros);
            break;
        
        case 2:
            excluir(listaPassageiros);
            break;

        case 3:
            alterar(listaPassageiros);
            break;

        case 4:
            listar(listaPassageiros);
            break;

        case 5:
            localizar(listaPassageiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            menuPassageiros(listaPassageiros);
            break;
    }
}

void incluir(vector<Passageiro> &listaPassageiros) {
    Passageiro passageiro;

    systemClear();
    cout << "\n###### Incluir passageiros ######\n\n";
    
    cout << "Nome: ";
    cin.sync();
    getline(cin, passageiro.nome);
    cout << endl;

    cout << "CPF: ";
    cin >> passageiro.cpf;
    cout << endl;

    cout << "Data nascimento: ";
    cin >> passageiro.dtNascimento;
    cout << endl;

    cout << "Numero de autorização: ";
    cin >> passageiro.numAutorizacao;
    cout << endl << endl;

    listaPassageiros.push_back(passageiro);
    menuIncluir(listaPassageiros);
}

void menuIncluir(vector<Passageiro> &listaPassageiros) {
    int opcao;

    cout << "\n\nDeseja incluir outro passageiro?\n\n";

    cout << "[ 0 ] Sair\t\t[ 1 ] Incluir\n";
    cout << "\nSelecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 0:
            systemClear();
            menuPassageiros(listaPassageiros);
            break;

        case 1:
            systemClear();
            incluir(listaPassageiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            incluir(listaPassageiros);
            break;
    }
}

void excluir(vector<Passageiro> &listaPassageiros) {
    int tamanho = listaPassageiros.size();
    int indice;
    string cpf;

    systemClear();
    cout << "\n###### Excluir passageiros ######\n\n";

    if (tamanho > 0)
    {
        cout << "\n###### Passageiros cadastrados ######\n\n";

        exibirListaPassageiros(listaPassageiros);
        cout << endl << endl;

        cout << "Informe o CPF do passageiro que deseja excluir: ";
        cin >> cpf;

        indice = buscarPassageiro(listaPassageiros, cpf);

        if (indice >= 0)
        {
            confirmarExclusao(listaPassageiros, indice);
            menuExcluir(listaPassageiros);
            
        }
        else {
            cout << "\nRoteiro não localizado.\n";
            systemPauseAndClear();
            excluir(listaPassageiros);
        }
    }
    else
    {
        cout << "\nNão existem dados para serem exibidos.\n";
        systemPauseAndClear();
        menuPassageiros(listaPassageiros);
    }
}

void menuExcluir(vector<Passageiro> &listaPassageiros) {
    int opcao;

    cout << "\n\nDeseja excluir outro passageiro?\n\n";

    cout << "[ 0 ] Sair\t\t[ 1 ] Excluir\n";
    cout << "\nSelecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 0:
            systemClear();
            menuPassageiros(listaPassageiros);
            break;

        case 1:
            systemClear();
            excluir(listaPassageiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            excluir(listaPassageiros);
            break;
    }
}

void confirmarExclusao(vector<Passageiro> &listaPassageiros, int indice) {
    int opcao;

    systemClear();
    cout << "\n\nDeseja realmente excluir o passageiro\n";
    cout << "\t\t" << listaPassageiros[indice].nome << "?" << endl << endl;

    cout << "[ 1 ] Sim \t\t [ 2 ] Não\n\n";
    cout << "Selecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 1:
            listaPassageiros.erase(listaPassageiros.begin()+indice);
            cout << "\n\nPassageiro excluído com sucesso!\n\n";
            systemPauseAndClear();
            break;

        case 2:
            systemClear();
            excluir(listaPassageiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            confirmarExclusao(listaPassageiros, indice);
            break;
    }
}

void alterar(vector<Passageiro> &listaPassageiros) {
    string cpf;
    int indice;

    systemClear();
    cout << "\n###### Alterar passageiro ######\n\n";

    if (listaPassageiros.size() > 0)
    {
        cout << "Informe o número de CPF para alterar: ";
        cin >> cpf;

        indice = buscarPassageiro(listaPassageiros, cpf);
        if (indice >= 0)
        {
            selecionarCampo(listaPassageiros, indice);
            menuAlterar(listaPassageiros);
        }
        else {
            cout << "\nPassageiro não localizado.\n";
            systemPauseAndClear();
            alterar(listaPassageiros);
        }
    }
    else
    {
        cout << "\nNão existem dados para serem exibidos.\n";
        systemPauseAndClear();
        menuPassageiros(listaPassageiros);
    }
}

void exibirPassageiroSelecionado(vector<Passageiro> &listaPassageiros, int indice) {
    cout << "\n###### Alterar passageiro ######\n\n";

    cout << "\nDados do passageiro selecionado:\n\n";

    cout << "Nome: " << listaPassageiros[indice].nome << endl;
    cout << "CPF: " << listaPassageiros[indice].cpf << endl;
    cout << "Duração: " << listaPassageiros[indice].dtNascimento << endl;
    cout << "Origem: " << listaPassageiros[indice].numAutorizacao << endl << endl;
}

void selecionarCampo(vector<Passageiro> &listaPassageiros, int indice) {
    vector<string> listaCampos = {"Nome", "CPF", "Data de nascimento", "Número de autorização"};
    int opcao;

    for (string campo : listaCampos)
    {
        systemClear();
        exibirPassageiroSelecionado(listaPassageiros, indice);

        cout << "\nDeseja alterar o campo '" << campo << "'?\n\n";
        
        cout  << "[ 1 ] Sim\t\t[ 2 ] Não";
        cout << "\n\nSelecione uma opção: ";
        cin >> opcao;

        cout << endl << endl;

        switch (opcao)
        {
            case 1:
                if (campo.compare("Nome") == 0)
                {
                    cout << "Nome: ";
                    cin.sync();
                    getline(cin, listaPassageiros[indice].nome);
                    cout << endl;
                }

                if (campo.compare("CPF") == 0)
                {
                    cout << "CPF: ";
                    cin >> listaPassageiros[indice].cpf;
                    cout << endl;
                }

                if (campo.compare("Data de nascimento") == 0)
                {
                    cout << "Data nascimento: ";
                    cin >> listaPassageiros[indice].dtNascimento;
                    cout << endl;
                }

                if (campo.compare("Número de autorização") == 0)
                {
                    cout << "Numero de autorização: ";
                    cin >> listaPassageiros[indice].numAutorizacao;
                    cout << endl;
                }
                
                break;

            case 2:
                continue;
                break;

            default:
                cout << "\n\nOpção inválida!\n";
                systemPauseAndClear();
                break;
        }
    }

}

void menuAlterar(vector<Passageiro> &listaPassageiros) {
    int opcao;

    cout << "\n\nDeseja alterar outro passageiro?\n\n";

    cout << "[ 0 ] Sair\t\t[ 1 ] Alterar passageiro\n";
    cout << "\nSelecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 0:
            systemClear();
            menuPassageiros(listaPassageiros);
            break;

        case 1:
            systemClear();
            alterar(listaPassageiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            alterar(listaPassageiros);
            break;
    }
}

void listar(vector<Passageiro> &listaPassageiros) {
    systemClear();
    cout << "\n###### Listar passageiros ######\n\n";

    if (listaPassageiros.size() > 0)
    {
        exibirListaPassageiros(listaPassageiros);
    }
    else
    {
        cout << "\nNão existem dados para serem exibidos.\n";
    }
    
    systemPauseAndClear();
    menuPassageiros(listaPassageiros);
}

void localizar(vector<Passageiro> &listaPassageiros) {
    Passageiro passageiro;
    string cpf;
    int opcao, indice;

    systemClear();
    cout << "\n###### Loalizar passageiro ######\n\n";

    cout << "Digite o CPF para localizar: ";
    cin >> cpf;

    indice = buscarPassageiro(listaPassageiros, cpf);
    cout << endl;

    if (indice >= 0)
    {
        cout << "CPF: " << listaPassageiros[indice].cpf << endl;
        cout << "Nome: " << listaPassageiros[indice].nome << endl;
        cout << "Data de nascimento: " << listaPassageiros[indice].dtNascimento << endl;
        cout << "Número da autorização: " << listaPassageiros[indice].numAutorizacao << endl;
    }
    else
    {
        cout << "\nPassageiro não localizado.\n\n";
    }

    cout << "\n\n[ 0 ] Sair\t\t[ 1 ] Localizar\n\n";
    cout << "Selecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 0:
            menuPassageiros(listaPassageiros);
            break;
        
        case 1:
            localizar(listaPassageiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            localizar(listaPassageiros);
            break;
    }
}

void exibirListaPassageiros(vector<Passageiro> &listaPassageiros) {
    if (listaPassageiros.size() > 0)
    {
        cout << "Nome\t\tCPF\t\tData nascimento\t\tNúmero de autorização\n\n"; 
        for (Passageiro passageiro : listaPassageiros)
        {
            cout << passageiro.nome << "\t\t";
            cout << passageiro.cpf << "\t\t";
            cout << passageiro.dtNascimento << "\t\t";
            cout << passageiro.numAutorizacao << endl;
        }

        cout << "\n\nPassageiros encontrados: " << listaPassageiros.size() << endl;
    }
}

int buscarPassageiro(vector<Passageiro> &listaPassageiros, string cpf) {
    int tamanho = listaPassageiros.size();

    if (tamanho > 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (listaPassageiros[i].cpf.compare(cpf) == 0)
            {
                return i;
            }
            
        }
    }
    
    return -1;
}

/**Métodos roteiro*/
void menuRoteiros(vector<Roteiro> &listaRoteiros) {
    int opcao;

    systemClear();
    cout << "\n###### Menu roteiros ######\n";

    cout << "\nSelecione uma opção:\n\n";

    cout << "[ 1 ] Incluir" << endl;
    cout << "[ 2 ] Excluir" << endl;
    cout << "[ 3 ] Alterar" << endl;
    cout << "[ 4 ] Listar" << endl;
    cout << "[ 5 ] Localizar" << endl;
    cout << "[ 0 ] Sair" << endl << endl;

    cout << "Selecione uma opção: ";
    cin >> opcao;
    cout << endl;

    switch (opcao)
    {
        case 0:
            menu();
            break;

        case 1:
            incluir(listaRoteiros);
            break;
        
        case 2:
            excluir(listaRoteiros);
            break;

        case 3:
            alterar(listaRoteiros);
            break;

        case 4:
            listar(listaRoteiros);
            break;

        case 5:
            localizar(listaRoteiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            menuRoteiros(listaRoteiros);
            break;
    }
}

void incluir(vector<Roteiro> &listaRoteiros) {
    Roteiro roteiro;

    systemClear();
    cout << "\n###### Incluir roteiros ######\n\n";
    
    cout << "Código: ";
    cin.sync();
    getline(cin, roteiro.codigo);
    cout << endl;

    cout << "Data/hora prevista: ";
    cin.sync();
    getline(cin, roteiro.dataHora);
    cout << endl;

    cout << "Duração prevista: ";
    cin >> roteiro.duracao;
    cout << endl;

    cout << "Origem: ";
    cin.sync();
    getline(cin, roteiro.origem);
    cout << endl;

    cout << "Destino: ";
    cin.sync();
    getline(cin, roteiro.destino);
    cout << endl << endl;

    listaRoteiros.push_back(roteiro);
    menuIncluir(listaRoteiros);
}

void menuIncluir(vector<Roteiro> &listaRoteiros) {
    int opcao;

    cout << "\n\nDeseja incluir outro roteiro?\n\n";

    cout << "[ 0 ] Sair\t\t[ 1 ] Incluir\n";
    cout << "\nSelecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 0:
            systemClear();
            menuRoteiros(listaRoteiros);
            break;

        case 1:
            systemClear();
            incluir(listaRoteiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            incluir(listaRoteiros);
            break;
    }
}

void excluir(vector<Roteiro> &listaRoteiros) {
    int tamanho = listaRoteiros.size();
    int indice;
    string codigo;

    systemClear();
    cout << "\n###### Excluir Roteiros ######\n\n";

    if (tamanho > 0)
    {
        cout << "\n###### Roteiros cadastrados ######\n\n";

        exibirListaRoteiros(listaRoteiros);
        cout << endl << endl;

        cout << "Informe o código do Roteiro que deseja excluir: ";
        cin >> codigo;

        indice = buscarRoteiro(listaRoteiros, codigo);

        if (indice >= 0)
        {
            confirmarExclusao(listaRoteiros, indice);
            menuExcluir(listaRoteiros);
            
        }
        else {
            cout << "\nRoteiro não localizado.\n";
            systemPauseAndClear();
            excluir(listaRoteiros);
        }
    }
    else
    {
        cout << "\nNão existem dados para serem exibidos.\n";
        systemPauseAndClear();
        menuRoteiros(listaRoteiros);
    }
}

void menuExcluir(vector<Roteiro> &listaRoteiros) {
    int opcao;

    cout << "\n\nDeseja excluir outro Roteiro?\n\n";

    cout << "[ 0 ] Sair\t\t[ 1 ] Excluir\n";
    cout << "\nSelecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 0:
            systemClear();
            menuRoteiros(listaRoteiros);
            break;

        case 1:
            systemClear();
            excluir(listaRoteiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            excluir(listaRoteiros);
            break;
    }
}

void confirmarExclusao(vector<Roteiro> &listaRoteiros, int indice) {
    int opcao;

    systemClear();
    cout << "\n\nDeseja realmente excluir o roteiro\n";
    cout << "\t" << listaRoteiros[indice].origem << " X " << listaRoteiros[indice].destino << "?" << endl << endl;

    cout << "[ 1 ] Sim \t\t [ 2 ] Não\n\n";
    cout << "Selecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 1:
            listaRoteiros.erase(listaRoteiros.begin()+indice);
            cout << "\n\nRoteiro excluído com sucesso!\n\n";
            systemPauseAndClear();
            break;

        case 2:
            systemClear();
            excluir(listaRoteiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            confirmarExclusao(listaRoteiros, indice);
            break;
    }
}

void alterar(vector<Roteiro> &listaRoteiros) {
    string codigo;
    int indice;

    systemClear();
    cout << "\n###### Alterar Roteiro ######\n\n";

    if (listaRoteiros.size() > 0)
    {
        cout << "Informe o número de codigo para alterar: ";
        cin >> codigo;

        indice = buscarRoteiro(listaRoteiros, codigo);
        if (indice >= 0)
        {
            selecionarCampo(listaRoteiros, indice);
            menuAlterar(listaRoteiros);
        }
        else {
            cout << "\nRoteiro não localizado.\n";
            systemPauseAndClear();
            alterar(listaRoteiros);
        }
    }
    else
    {
        cout << "\nNão existem dados para serem exibidos.\n";
        systemPauseAndClear();
        menuRoteiros(listaRoteiros);
    }
}

void exibirRoteiroSelecionado(vector<Roteiro> &listaRoteiros, int indice) {
    cout << "\n###### Alterar roteiro ######\n\n";

    cout << "\nDados do roteiro selecionado:\n\n";

    cout << "codigo: " << listaRoteiros[indice].codigo << endl;
    cout << "Data/hora prevista: " << listaRoteiros[indice].dataHora << endl;
    cout << "Duração: " << listaRoteiros[indice].duracao << endl;
    cout << "Origem: " << listaRoteiros[indice].origem << endl;
    cout << "Destino: " << listaRoteiros[indice].destino << endl << endl;
}

void selecionarCampo(vector<Roteiro> &listaRoteiros, int indice) {
    vector<string> listaCampos = {"Código", "Data/Hora prevista", "Duração", "Origem", "Destino"};
    int opcao;

    for (string campo : listaCampos)
    {
        systemClear();
        exibirRoteiroSelecionado(listaRoteiros, indice);

        cout << "\nDeseja alterar o campo '" << campo << "'?\n\n";
        
        cout  << "[ 1 ] Sim\t\t[ 2 ] Não";
        cout << "\n\nSelecione uma opção: ";
        cin >> opcao;

        cout << endl << endl;

        switch (opcao)
        {
            case 1:
                if (campo.compare("Código") == 0)
                {
                    cout << "Código: ";
                    cin >> listaRoteiros[indice].codigo;
                    cout << endl;
                }

                if (campo.compare("Data/Hora prevista") == 0)
                {
                    cout << "Data/Hora prevista: ";
                    cin.sync();
                    getline(cin, listaRoteiros[indice].dataHora);
                    cout << endl;
                }

                if (campo.compare("Duração") == 0)
                {
                    cout << "Duração: ";
                    cin >> listaRoteiros[indice].duracao;
                    cout << endl;
                }

                if (campo.compare("Origem") == 0)
                {
                    cout << "Origem: ";
                    cin.sync();
                    getline(cin, listaRoteiros[indice].origem);
                    cout << endl;
                }

                if (campo.compare("Destino") == 0)
                {
                    cout << "Destino: ";
                    cin.sync();
                    getline(cin, listaRoteiros[indice].destino);
                    cout << endl;
                }
                
                break;

            case 2:
                continue;
                break;

            default:
                cout << "\n\nOpção inválida!\n";
                systemPauseAndClear();
                break;
        }
    }

}

void menuAlterar(vector<Roteiro> &listaRoteiros) {
    int opcao;

    cout << "\n\nDeseja alterar outro Roteiro?\n\n";

    cout << "[ 0 ] Sair\t\t[ 1 ] Alterar Roteiro\n";
    cout << "\nSelecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 0:
            systemClear();
            menuRoteiros(listaRoteiros);
            break;

        case 1:
            systemClear();
            alterar(listaRoteiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            alterar(listaRoteiros);
            break;
    }
}

void listar(vector<Roteiro> &listaRoteiros) {
    systemClear();
    cout << "\n###### Listar roteiros ######\n\n";

    if (listaRoteiros.size() > 0)
    {
        exibirListaRoteiros(listaRoteiros);
    }
    else
    {
        cout << "\nNão existem dados para serem exibidos.\n";
    }
    
    systemPauseAndClear();
    menuRoteiros(listaRoteiros);
}

void localizar(vector<Roteiro> &listaRoteiros) {
    Roteiro roteiro;
    string codigo;
    int opcao, indice;

    systemClear();
    cout << "\n###### Loalizar Roteiro ######\n\n";

    cout << "Digite o codigo para localizar: ";
    cin >> codigo;

    indice = buscarRoteiro(listaRoteiros, codigo);
    cout << endl;

    if (indice >= 0)
    {
        cout << "Codigo: " << listaRoteiros[indice].codigo << endl;
        cout << "Data/Hora prevista: " << listaRoteiros[indice].dataHora << endl;
        cout << "Duração prevista: " << listaRoteiros[indice].duracao << endl;
        cout << "Origem: " << listaRoteiros[indice].origem << endl;
        cout << "Destino: " << listaRoteiros[indice].destino << endl;
    }
    else
    {
        cout << "\nRoteiro não localizado.\n\n";
    }

    cout << "\n\n[ 0 ] Sair\t\t[ 1 ] Localizar\n\n";
    cout << "Selecione uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 0:
            menuRoteiros(listaRoteiros);
            break;
        
        case 1:
            localizar(listaRoteiros);
            break;
        
        default:
            cout << "\n\nOpção inválida!\n";
            systemPauseAndClear();
            localizar(listaRoteiros);
            break;
    }
}

void exibirListaRoteiros(vector<Roteiro> &listaRoteiros) {
    if (listaRoteiros.size() > 0)
    {
        cout << "Código\t\tData/hora prevista\t\tDuração prevista\t\tOrigem\t\t\tDestino\n\n"; 
        for (Roteiro roteiro : listaRoteiros)
        {
            cout << roteiro.codigo << "\t\t";
            cout << roteiro.dataHora << "\t\t\t\t";
            cout << roteiro.duracao << "\t\t\t\t";
            cout << roteiro.origem << "\t\t\t";
            cout << roteiro.destino << endl;
        }

        cout << "\n\nRoteiros encontrados: " << listaRoteiros.size() << endl;
    }
}

int buscarRoteiro(vector<Roteiro> &listaRoteiros, string codigo) {
    int tamanho = listaRoteiros.size();

    if (tamanho > 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (listaRoteiros[i].codigo.compare(codigo) == 0)
            {
                return i;
            }
            
        }
    }
    
    return -1;
}

/**Comum*/
int sair() {
    cout << "\nEncerrando programa...\n";
    systemPause();
    return 0;
}

void systemPause() {
    cout << "\nPressione ENTER para continuar...\n";
    cin.sync();
    cin.get();
}

void systemClear() {
    system("echo ''") != 0 ? system("clear") : system("cls");
}

void systemPauseAndClear() {
    systemPause();
    systemClear();
}
