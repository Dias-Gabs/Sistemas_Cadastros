#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//- Função responsavel por capturar e armazenar os dados 
void cadastrarCliente(ofstream& file) {                //- Função como 'void' por não retornar valores. Também recebe parametros dentro de ()
 //                                                    ------ 'ofstream&' indica um tipo de fluxo de saida de dados do codigo e entrada de dados no arquvo
 //                                                        ----- O '&' ao final de 'ofstream' apenas indica a referencia ao arquivo, nesse caso 'file'.
    string nome, idade, genero, cpf, rg, dataNascimento, observacoes;

    cout << "Nome: ";
    cin.ignore();                                        //- 'cin.ignore()' limpa o buffer, evita aquele erro do codigo passar direto
    getline(cin, nome);                                  //- 'getLine(); é usado para capturar todos os caracteres de uma linha, e recebe como parametros
 //                                                      ----- 'getline() recebe como parametros dentro dos '( )' o metodo de entrada de informações 'cin', e onde armazenar 'nome'
    cout << "Idade: ";
    getline(cin, idade);

    cout << "Genero: ";
    getline(cin, genero);                                //- Mesma coisa

    cout << "CPF: ";
    getline(cin, cpf);

    cout << "RG: ";
    getline(cin, rg);

    cout << "Data de Nascimento: ";
    getline(cin, dataNascimento);

    cout << "Observacoes (opcional): ";
    getline(cin, observacoes);

    //- Aqui é organizado os dados dentro do arquivo, ele vai imprimir no arquivo a variavel e separar com '|', e obviamente salvar, nada demais.
    file << nome << "|" << idade << "|" << genero << "|" << cpf << "|" << rg << "|" << dataNascimento << "|" << observacoes << endl;
    cout << "Cliente cadastrado com sucesso!" << endl;          //- Printa a linha mostrando que foi cadastrado;
}

//- Função responsavel por consultar os dados dentro do arquivo.
void consultarCliente(ifstream& file) {                         //- Quase a mesma coisa da função 'cadastrarClientes()', mas dessa vez usamos 'ifstream', que indica ENTRADA de valores no codigo e SAIDA do arquivo
    string line;                                                //- Cria a variavel 'line' que irá receber os dados da linha completa contida no arquivo
    cout << "\n\nLista de Clientes:\n" << endl;
    while (getline(file, line)) {                               //- Mantem o loop enquanto existir dados na linha para serem exibidos, enquando a var 'line' recebe esses valores o loop se mantem.
        cout << "" << endl;
        cout << "- " << line << endl;                           //- Printa a linha completa com os dados consultados
    }
}

//- Apenas exibe os integrantes do grupo, e encerra caso o usuario digitar 0
void creditos() {             
    
    cout << "\n\n======================" << endl;
    cout << "\nIntegrantes:\n" << endl;
    cout << "" << endl;

    cout << "- Gabriel Dias \n RA: 52318979 \n" << endl;
    cout << "- Nathalia Franco Cherelo  \n RA: 52318803 \n" << endl;
    cout << "- Eduardo Henrique gonçalves da Silva \n RA: 52319004 \n" << endl;
    cout << "- Giovanna Luiza Andreoli de Souza \n RA: 52015281 \n" << endl;
    cout << "- Gabriel Pereira Kawakami  \n RA: 52318982 \n" << endl;
    //cout << "" << endl;
    cout << "======================\n" << endl;
    cout << "0- Encerrar programa" << endl;
    cout << "" << endl;
    cout << "\nEscolha uma opção: ";

}

int main() {
    int opcao;

        //- Declara que a var 'arquivo_escrita' e "arquivo_consulta", um para escrever no arquivo, o outro para leitura.
    ofstream arquivo_escrita("clientes.txt", ios::out | ios::app);      //- var 'arquivo_escrita' recebe o arquivo .txt. 'ios::out' indica que esse arquivo deve ser aberto como saida do codigo e entrada de valores no arquivo
    ifstream arquivo_entrada("clientes.txt");                           //- Mesma coisa, mas nesse caso o arquivo é apenas para leitura.

    if (!arquivo_escrita.is_open() || !arquivo_entrada.is_open()) {     //- Verifica usando o operador logico '!', caso NENHUMA dessas var tenham puxado o arquivo
        cout << "\nErro ao abrir o arquivo." << endl;
        return 1;
    }

    do {
        cout << "\nMenu:" << endl;
        cout << "1- Cadastrar Cliente" << endl;
        cout << "2- Consultar Cliente" << endl;
        cout << "3- Creditos" << endl;
        cout << "0- Sair" << endl;
        cout << "\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao) {                                               //- Switch para verificar a função escolhida pelo usuario
            case 1:                                                    //- Se a opção for == 1, inicia a função para cadastrar
              cadastrarCliente(arquivo_escrita);
              break;
            case 2:                                                   //- Se a opção for == 2, inicia a função para consultar.
                consultarCliente(arquivo_entrada);
                break;
            case 3:                                                   //- Se a opção 3 for selecionada pelo usiaro, incia um switch
                do {
                    creditos();                                       //- Incia a função 'creditos()'
                    cin >> opcao;                                     //- Continua capturando o que o usuario digitar
                } while (opcao != 0);                                 //- Enquanto 'opcao' for DIFERENTE de 0, nada será realizado, utilizando o break para finalizar o loop;
                break;
            case 0:                                                   //- Caso for igual a zero, encerra o programa;
                cout << "\n\nSaindo do programa.\n\n" << endl;
            default:
                cout << "\nOpção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);                                             //- Enquanto a variavel 'opcao' for igual a zero, fecha o arquivo e seus modos de comunicação

    arquivo_escrita.close();
    arquivo_entrada.close();

    return 0;
}