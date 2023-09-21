# Residevs-AV1
Este repositório é referente a Avaliação I do programa.

E contem a implementação no arquivo **mainIndividual.cpp** da gestão de Passageiros, gestão de Roteiros e Menu Principal.

Em gestão de Passageiros foi implementada as opções:

    1. Incluir um Novo Passageiro
    
    2. Excluir (por CPF)
    
    3. Alterar (por CPF)
    
    4. Listar todos 
    
    5. Localizar Passageiro (por CPF)
    
    Funcões:
    
        *int gestaoPassageiro(vector<Passageiro> &passageiros);*
        *void incluirPassageiro(vector<Passageiro> &passageiros);*
        *void alterarPassageiro(vector<Passageiro> &passageiros);*
        *void excluirPassageiro(vector<Passageiro> &passageiros);*
        *void listarPassageiros(vector<Passageiro> passageiros);*
        *void localizarPassageiroCPF(vector<Passageiro> passageiros);*
        *bool verificaPassageiroExiste(vector<Passageiro> passageiros, string cpf);*
        *int retornaIdade(Data dtNascimento);*

Em gestão de Roteiros foi implementada as opções:

    1. Incluir
    
    2. Excluir (por codigo)
    
    3. Alterar (por codigo)
    
    4. Listar todos
    
    5. Localizar (por codigo)

    Funções:
    
        *int gestaoRoteiro(vector<Roteiro> &roteiros);*
        *void incluirRoteiro(vector<Roteiro> &roteiros);*
        *void alterarRoteiro(vector<Roteiro> &roteiros);*
        *void excluirRoteiro(vector<Roteiro> &roteiros);*
        *void listarRoteiros(vector<Roteiro> roteiros);*
        *void localizarRoteiro(vector<Roteiro> roteiros);*
        *bool verificaRoteiroExiste(vector<Roteiro> roteiros, int codigo);*
    

Em Menu Principal tem as opcoes para chamar ou a gestão de Passageiros, ou a gestão de Roteiros ou sair do programa

No arquivo data.h e dataUtils.cpp contem a biblioteca e a implementação da struct Data

Para executar o programa basta colocar no terminal ./meu_programa
