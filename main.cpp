#include <iostream>
#include <fstream>
#include <vector>

#include "cliente.hpp"
#include "gerente.hpp"
#include "arquivos.hpp"
#include "login.hpp"

using namespace std;

int main(){

    int opcao;

    lerArquivo("sanduiche");
    lerArquivo("suco");

    opcao = login();

    if(opcao == 1){
        while(true){
            menuCliente();

            cout << "Opção: ";
            cin >> opcao;

            if(opcao == 1){
                listarProdutos("sanduiche");
            } else if(opcao == 2){
                listarProdutos("suco");
            } else if(opcao == 3){
                escolherLanche();
            } else if(opcao == 4){
                //calcularValorTotal();
            } else if(opcao == 5){
                exibirCarrinho();
            } else if(opcao == 6){
                //excluirItem();
            } else if(opcao == 7){
                //finalizarPedido();
                break;
            } else{
                cout << "\n---Opção inválida!---\n" << endl;
            }
        }
    } else if(opcao == 2){
        while(true){
            menuGerente();

            cout << "Opção: ";
            cin >> opcao;

            if(opcao == 1){
                listarProdutos("sanduiche");
            } else if(opcao == 2){
                listarProdutos("suco");
            } else if(opcao == 3){
                adicionarItem("sanduiche");
            } else if(opcao == 4){
                adicionarItem("suco");
            } else if(opcao == 5){
                alterarPrecoItem("sanduiche");
            } else if(opcao == 6){
                alterarPrecoItem("suco");
            } else if(opcao == 7){
                excluirItem("sanduiche");
            } else if(opcao == 8){
                excluirItem("suco");
            } else if(opcao == 9){
                break;
            } else{
                cout << "\n---Opção inválida!---\n" << endl;
            }
        }
    }

    return 0;
}
