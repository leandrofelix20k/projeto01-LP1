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
    cout << "4 - Ver Carrinho" << endl;
    cout << "5 - Excluir Item do Carrinho" << endl;
    cout << "6 - Finalizar Pedido" << endl;
}

void listarSanduiches(){
    map<string, float>::iterator it;

    cout << "---Sanduíches---" << endl;

    
}