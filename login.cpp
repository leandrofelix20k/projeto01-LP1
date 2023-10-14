#include <iostream>
#include "login.hpp"

using namespace std;

int login(){
    int op;

    while(true){
        cout << "\n1- Cliente\n" << "2- Gerente" << endl;
        cout << "Opção: ";
        cin >> op;

        if(op == 1){
            system("clear||cls");

            cout << "\n---Login efetuado com sucesso!---\n" << endl;

            break;
        } else if(op == 2){
            system("clear||cls");

            if(loginGerente()){
                break;
            }
        } else{
            system("clear||cls");

            cout << "\n---Opção inválida!---\n" << endl;
        }
    }

    return op;
}

bool loginGerente(){
    string usuario, senha;
    int op;

    while(true){
        cout << "\n---Login Gerente---" << endl;
        cout << "Usuário: ";
        cin >> usuario;
        cout << "Senha: ";
        cin >> senha;

        if(usuario == "admin" && senha == "admin"){
            system("clear||cls");

            cout << "\n---Login efetuado com sucesso!---\n" << endl;

            return true;
        } else{
            do{
                cout << "\n---Usuário ou senha incorretos!---\n" << endl;
                cout << "1- Tentar novamente\n" << "2- Voltar" << endl;
                cout << "Opção: ";
                cin >> op;

                if(op == 2){
                    system("clear||cls");

                    return false;
                }
            } while(op != 1);
        }
    }

    return false;
}