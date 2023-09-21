#include <iostream>
#include <string>
#include <vector>
#include "validar.cpp"
#include "passageiro.cpp" //arquivo que gerencia os passageiros;
#include "roteiro.cpp"//arquivo que gerencia os roteiros

using namespace std;
int menuPrincipal();
bool gerenciarAcessos(int op, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros);

int main (){
    vector<Passageiros> passageiros;
    vector<Roteiros> roteiros;
   
    bool continuar = true;

    do{
        //1ºparamentro uma opcao escolhida, 2º e 3º os vectores;
        continuar = gerenciarAcessos(menuPrincipal(), passageiros, roteiros);
        //o retono é true ou false para encerrar o acesso ou sair o while. na variavel continuar   
    } while (continuar);//continuar a execução do  gerenciarAcessos sai do programa;
    
    return 0;
} 

bool gerenciarAcessos(int op, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros){
     switch (op){
        case 1:
            gestaoDePassageiros(passageiros);// vai para o arquivo passageiro.cpp
            break;
        case 2:
            gestaoDeRoteiros(roteiros);// vai para o arquivo roteiro.cpp
            break;
        case 0:
           return false;
        default:
                return true;////continuar o gerenciarAcesso o usuario digitou uma opçao invalida
        }
        return true;//continuar o gerenciarAcesso;
}

int menuPrincipal(){
    int op = 0;
    cout <<"----------------------------" <<endl;
    cout << "1-Gestao de Passageiro" <<endl;
    cout << "2-Gerenciar Roteiro" <<endl;
    cout << "0-Sair" <<endl;
    cout << "Digite uma opcao:";
    cin >>op;
    cout<<endl; 
    return op;
}