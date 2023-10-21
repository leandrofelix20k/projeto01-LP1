#include <iostream>
#include <fstream>
#include <vector>

#include "cliente.hpp"
#include "gerente.hpp"
#include "arquivos.hpp"

using namespace std;

int main(){

    int opcao;

    lerArquivo("sanduiche");
    lerArquivo("suco");

    cout << "-----------------------------" << endl;
    cout << "---Lanchonete do Francisco---" << endl;
    cout << "-----------------------------" << endl;

    while(true){
        cout << "\n1- Cliente\n" << "2- Gerente\n" << "3- Sair" << endl;
        cout << "Opção: ";
        cin >> opcao; //Recebe a opção escolhida pelo úsuario

        system("clear||cls"); //Limpa o terminal
        if(opcao == 1){ //O login é feito automaticamente caso o úsuario escolha a opção 1
            cout << "\n---Login efetuado com sucesso!---\n" << endl;

            break;
        } else if(opcao == 2){ //Caso o úsuario escolha a opção 2, é chamada a função de login do gerente
            if(loginGerente()){
                cout << "\n---Login efetuado com sucesso!---\n" << endl;

                break;
            }
        } else if(opcao == 3){
            cout << "\n---Saindo do sistema---\n" << endl;
            break;
        } else{
            cout << "\n---Opção inválida!---" << endl;
        }
    }

    if(opcao == 1){
        while(true){
            menuCliente(); //Chama a função para exibir o menu do cliente

            cout << "Opção: ";
            cin >> opcao;

            //Executa uma operação de acordo com a opção escolhida pelo úsuario
            if(opcao == 1){
                listarProdutos("sanduiche");
            } else if(opcao == 2){
                listarProdutos("suco");
            } else if(opcao == 3){
                escolherLanche();
            } else if(opcao == 4){
                system("clear||cls");
                valorTotalCarrinho();
            } else if(opcao == 5){
                system("clear||cls");
                exibirCarrinho();
            } else if(opcao == 6){
                excluirItem();
            } else if(opcao == 7){ //O loop é encerrado quando o úsuario digita 7
                //Ao encerrar o pedido, o mapa do carrinho e o valor total são exibidos
                system("clear||cls");
                exibirCarrinho();
                valorTotalCarrinho();
                cout << "---Pedido finalizado!---\n" << endl;
                break;
            } else{
                cout << "\n---Opção inválida!---\n" << endl;
            }
        }
    } else if(opcao == 2){
        while(true){
            menuGerente(); //Chama a função para exibir o menu do gerente

            cout << "Opção: ";
            cin >> opcao;

            //Executa uma operação de acordo com a opção escolhida pelo úsuario
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
            } else if(opcao == 9){ //O loop é encerrado quando o úsuario digita 9
                system("clear||cls");
                cout << "\n---Saindo do sistema---\n" << endl;
                break;
            } else{
                cout << "\n---Opção inválida!---\n" << endl;
            }
        }
    }

    return 0;
}
