#include <iostream>
#include <map>

#include "cliente.hpp"
#include "arquivos.hpp"

using namespace std;

//Função para exibir o menu do cliente
void menuCliente(){
    cout << "---Menu do cliente---" << endl;
    cout << "1 - Listar Sanduíches" << endl;
    cout << "2 - Listar Sucos" << endl;
    cout << "3 - Escolher Lanche" << endl;
    cout << "4 - Calcular Valor Total" << endl;
    cout << "5 - Ver Carrinho" << endl;
    cout << "6 - Excluir Item" << endl;
    cout << "7 - Finalizar Pedido" << endl;
}

//Função para o úsuario escolher seu lanche
void escolherLanche(){
    string nomeProduto, nomeItem;
    int op;

    cout << "\n---Escolher Lanche---" << endl;

    //Laço para o úsuario escolher o lanche
    while(true){
        cout << "1 - Sanduíche\n" << "2 - Suco" << "\n3 - Sair"<< endl;
        cout << "Opção: ";
        cin >> op;

        //Verifica se a opção está entre 1 e 2
        if(op == 1 || op == 2){
            //Atribui o nome do produto de acordo com a opção
            switch (op){
                case 1:
                    nomeProduto = "sanduiche";
                    break;
                case 2:
                    nomeProduto = "suco";
                    break;
            }

            //Lẽ o nome do item que o úsuario deseja
            cout << "\nNome do " << nomeProduto << ": ";
            cin.ignore();
            getline(cin, nomeItem);

            addItemCarrinho(nomeProduto, nomeItem); //Faz a chamada da função para adicionar o item no carrinho
        } else if(op == 3){
            cout << endl; //Caso o úsuario deseje sair, pula uma linha e encerra o laço
            break;
        } else{
            cout << "\n---Opção inválida!---\n" << endl; //Caso o úsuario digite uma opção fora do intervalo de 1 a 3, mostra uma mensagem de erro
        }
    }
}

void excluirItem(){
    string nomeItem;

    cout << "\n---Excluir Item---" << endl;

    cout << "Nome do item: ";
    cin.ignore();
    getline(cin, nomeItem);

    removerItemCarrinho(nomeItem); //Faz a chamada da função para remover o item do carrinho
}