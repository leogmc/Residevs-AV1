#include <iostream>
#include <vector>
#include <string>

#define LINHA "--------------------------------"

#include "structs.cpp"
#include "validacoes.cpp"
#include "funcoes_auxiliares.cpp"
#include "modulo_passageiros.cpp"
#include "modulo_roteiros.cpp"

using namespace std;

int main (void) 
{
    // inicializando vetores
    vector<Passageiro> passageiros;
    vector<Roteiro> roteiros;

    int opcao_usuario;

    cout << "Escolha um dos módulos - 1 para passageiro e 2 para roteiros: ";
    cin >> opcao_usuario;

    switch (opcao_usuario)
    {
        case 1:
            executarModuloPassageiros();
            break;
        case 2:
            executarModuloRoteiros();
            break;
        default:
        {
            cout << "Insira um número válido.";
            break;
        }
    }

    return 0;
}
