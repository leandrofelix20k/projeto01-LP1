#include <iostream>
#include <fstream>

#include "gerente.hpp"
#include "arquivos.hpp"

using namespace std;

//Função para exibir o menu do gerente
void menuGerente(){
    cout << "---Menu do gerente---" << endl;
    cout << "1 - Listar Sanduíches" << endl;
    cout << "2 - Listar Sucos" << endl;
    cout << "3 - Adicionar Novo Sanduíche" << endl;
    cout << "4 - Adicionar Novo Suco" << endl;
    cout << "5 - Alterar Preço do Sanduíche" << endl;
    cout << "6 - Alterar Preço do Suco" << endl;
    cout << "7 - Excluir Sanduíche" << endl;
    cout << "8 - Excluir Suco" << endl;
    cout << "9 - Sair" << endl;
}

//Função para adicionar um novo item no mapa de sanduiches ou sucos. Recebe como parâmetro o nome do produto.
void adicionarItem(string nomeProduto){
    string nome;
    float preco;

    cout << "\n---Adicionar novo " << nomeProduto << endl;

    cout << "Nome: ";
    cin >> nome;

    cout << "Preço: ";
    cin >> preco;

    addItem(nomeProduto, nome, preco); //Faz a chamada da função para adicionar o item e o preço no mapa

}

//Função para alterar o preço de um item no mapa de sanduiches ou sucos. Recebe como parâmetro o nome do produto.
void alterarPrecoItem(string nomeProduto){
    string nome;
    float novoPreco;

    cout << "\n---Alterar preço do " << nomeProduto << endl;

    cout << "Nome: ";
    cin >> nome;

    cout << "Novo preço: ";
    cin >> novoPreco;

    modificarPreco(nomeProduto, nome, novoPreco); //Faz a chamada da função para alterar o preço do item
}

//Função para excluir um item do mapa de sanduiches ou sucos. Recebe como parâmetro o nome do produto.
void excluirItem(string nomeProduto){
    string nome;

    cout << "\n---Excluir " << nomeProduto << endl;

    cout << "Nome: ";
    cin >> nome;

    removerItem(nomeProduto, nome); //Faz a chamada da função para remover o item do mapa
}
