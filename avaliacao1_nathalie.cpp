#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Passageiro {
    string cpf;
    string nome;
    int dt_nascimento;
    int num_autorizacao;
};

struct Roteiro {
    int codigo;
    int data_prevista;
    int hora_prevista;
    int duracao_prevista;
    string origem;
    string destino;
};

// protótipo de funções

void exibirMenuOpcoes (void);

// funções

int main (void) {
    int opcao_usuario = 0;

    exibirMenuOpcoes();
    cin >> opcao_usuario;


    return 0;
}

void exibirMenuOpcoes (void) {
    cout << "Digite um número conforme a lista de opções abaixo:" << endl
    << "1 para incluir" << endl
    << "2 para excluir" << endl
    << "3 para alterar (apenas por CPF)" << endl
    << "4 para listar" << endl
    << "5 para localizar (por CPF)" << endl
    << "0. Sair" << endl << endl
    << "Número: ";
}

void incluirPassageiro (Passageiro passageiro) {
    
}