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

    lerArquivoSanduiche();
    lerArquivoSuco();

    opcao = login();

    if(opcao == 1){
        while(true){
            menuCliente();

            cout << "Opção: ";
            cin >> opcao;

            if(opcao == 1){
                //listarSanduiches();
            } else if(opcao == 2){
                //listarSucos();
            } else if(opcao == 3){
                //escolherLanche();
            } else if(opcao == 4){
                //verCarrinho();
            } else if(opcao == 5){
               // excluirItemCarrinho();
            } else if(opcao == 6){
                //finalizarPedido();
                break;
            } else{
                cout << "\n---Opção inválida!---\n" << endl;
            }
        }
    }

    return 0;
}
