#include <string>
#include <ctime>

using namespace std;

/* FUNÇÕES */

bool validarCPF(string cpf)
{
    //verificar se todos os caracteres são dígitos
    for (unsigned int i = 0; i < cpf.length(); i++) 
    {
       if (!isdigit(cpf[i])) {
           return false;
       }
    }
    
    //verificar se possui 11 caracteres
    return cpf.length() != 11 ? false : true;
}

bool validarData (int dia, int mes, int ano) {
    if (ano < 1900 || ano > 2100) { return false; }
    if (mes < 1 || mes > 12) { return false; }
    int diasNoMes = 0;
    if (mes == 2) {
        diasNoMes = 
        (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasNoMes = 30;
    }
    else {
        diasNoMes = 31;
    }
    if (dia < 1 || dia > diasNoMes) { return false; }

    return true;
}

bool validarData(Data data) {
    return validarData(data.dia, data.mes, data.ano);
}

string transformarStringZeros(int numero) {
    string numeroString = to_string(numero);

    if (numero < 10){
        numeroString = "0" + numeroString;
    }

    return numeroString;
}

string transformarDataParaString(struct Data data)
{
    string dia = transformarStringZeros(data.dia);
    string mes = transformarStringZeros(data.mes);
    string ano = transformarStringZeros(data.ano);

    return dia+"/"+mes+"/"+ano;
}

bool verificarMaioridade(Data data_nascimento) 
{
    time_t agora = std::time(nullptr);
    tm* data_hora = std::localtime(&agora);

    int dia_atual = data_hora->tm_mday;
    int mes_atual = data_hora->tm_mon + 1;
    int ano_atual = data_hora->tm_year + 1900;

    int idade = ano_atual - data_nascimento.ano;
    int maioridade = false;

    if (idade > 18)
        maioridade = true;
    else if (idade == 18) {
        if ( (data_nascimento.mes + data_nascimento.dia) < (mes_atual + dia_atual) )
            maioridade = true;
    }

    return maioridade;
}