#include <iostream>
#include "login.hpp"

int login(){
    int op;

    while(true){
        std::cout << "\n1- Cliente\n" << "2- Gerente" << std::endl;
        std::cout << "Opção: ";
        std::cin >> op;

        if(op == 1){
            system("clear||cls");
            
            std::cout << "\n---Login efetuado com sucesso!---\n" << std::endl;

            break;
        } else if(op == 2){
            system("clear||cls");

            if(loginGerente()){
                break;
            }
        } else{
            system("clear||cls");

            std::cout << "\n---Opção inválida!---\n" << std::endl;
        }
    }

    return op;
}

bool loginGerente(){
    std::string usuario, senha;
    int op;

    while(true){
        std::cout << "\n---Login Gerente---" << std::endl;
        std::cout << "Usuário: ";
        std::cin >> usuario;
        std::cout << "Senha: ";
        std::cin >> senha;

        if(usuario == "admin" && senha == "admin"){
            system("clear||cls");

            std::cout << "\n---Login efetuado com sucesso!---\n" << std::endl;

            return true;
        } else{
            do{
                system("clear||cls");

                std::cout << "\n---Usuário ou senha incorretos!---\n" << std::endl;
                std::cout << "1- Tentar novamente\n" << "2- Voltar" << std::endl;
                std::cout << "Opção: ";
                std::cin >> op;

                if(op == 2){
                    system("clear||cls");

                    return false;
                }
            } while(op != 1);
        }
    }

    return false;
}