#include <string>
#include <vector>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Passageiro {
    string cpf;
    string nome;
    string data_nascimento;
    int num_autorizacao;
};

struct Roteiro {
    int codigo;
    string data_prevista;
    int hora_prevista;
    int duracao_prevista;
    string origem;
    string destino;
};