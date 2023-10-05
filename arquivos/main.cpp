#include <iostream>
#include "cliente.hpp"
#include "gerente.hpp"
#include "login.hpp"

int main(){

    int op;

    do{
        op = login();

        if(op == 1){
            // Cliente
        } else if(op == 2){
            // Gerente
        }

        op = 2;
    } while(op != 2);


    return 0;
}
