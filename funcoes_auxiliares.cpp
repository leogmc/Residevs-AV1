#include <iostream>
#include <vector>
#include <string>

using namespace std;

string pedirCPF(string acao)
{
    string cpf;

    cout << "Informe o CPF do passageiro a ser " << acao << ": ";
    cin >> cpf;

    return cpf;
}

int pedirCodigo(string acao)
{
    int codigo;

    cout << "Informe o código do roteiro a ser " << acao << ": ";
    cin >> codigo;

    return codigo;
}

// encontrar o passageiro pelo CPF
int pegarIndicePorCPF(vector<Passageiro> &passageiros, string cpf)
{
    int indice_passageiro = -1; 
    int i = 0;

    for (Passageiro passageiro: passageiros)
    {
        if (passageiro.cpf == cpf) 
        {
            indice_passageiro = i;
        }

        i++;
    }

    return indice_passageiro;
}

// encontrar o roteiro pelo índice
int pegarIndicePorCodigo(vector<Roteiro> &roteiros, int codigo)
{
    int indice_roteiro = -1; 
    int i = 0;

    for (Roteiro roteiro: roteiros)
    {
        if (roteiro.codigo == codigo) 
        {
            indice_roteiro = i;
        }

        i++;
    }

    return indice_roteiro;
}
