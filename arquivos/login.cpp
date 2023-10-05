#include <iostream>
#include "login.hpp"

int login(){
    int op;

    while(true){
        std::cout << "\n1- Cliente\n" << "2- Gerente" << std::endl;
        std::cout << "Opção: ";
        std::cin >> op;

        if(op == 1){
            std::cout << "\n---Login efetuado com sucesso!---\n" << std::endl;

            break;
        } else if(op == 2){
            if(loginGerente()){
                break;
            }
        } else{
            std::cout << "\n---Opção inválida!---\n" << std::endl;
        }
    }

    return op;
}

bool loginGerente(){
    std::string usuario, senha;
    int op;

    while(true){
        std::cout << "\nUsuário: ";
        std::cin >> usuario;
        std::cout << "Senha: ";
        std::cin >> senha;

        if(usuario == "admin" && senha == "admin"){
            std::cout << "\n---Login efetuado com sucesso!---\n" << std::endl;

            return true;
        } else{
            do{
                std::cout << "\n---Usuário ou senha incorretos!---\n" << std::endl;
                std::cout << "1- Tentar novamente\n" << "2- Voltar" << std::endl;
                std::cout << "Opção: ";
                std::cin >> op;

                if(op == 2){
                    return false;
                }
            } while(op != 1);
        }
    }

    return false;
}