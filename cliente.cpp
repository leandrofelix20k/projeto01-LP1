#include <iostream>
#include <map>

#include "cliente.hpp"
#include "arquivos.hpp"

using namespace std;

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

void escolherLanche(){
    string nomeProduto, nomeItem;
    int op;

    cout << "\n---Escolher Lanche---" << endl;

    while(true){
        cout << "1 - Sanduíche\n" << "2 - Suco" << "3 - Sair"<< endl;
        cout << "Opção: ";
        cin >> op;

        if(op == 1 || op == 2){
            switch (op){
                case 1:
                    nomeProduto = "sanduiche";
                    break;
                case 2:
                    nomeProduto = "suco";
                    break;
            }

            cout << "\nNome do " << nomeProduto << ": ";
            cin >> nomeItem;

            addItemCarrinho(nomeProduto, nomeItem);

        } else if(op == 3){
            break;
        } else{
            cout << "\n---Opção inválida!---\n" << endl;
        }
    }
}

