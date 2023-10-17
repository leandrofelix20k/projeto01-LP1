#include <iostream>
#include "login.hpp"

using namespace std;

int login(){
    int op;

    //O laço é executado até que o úsuario digite uma opção válida
    while(true){
        cout << "\n1- Cliente\n" << "2- Gerente" << endl;
        cout << "Opção: ";
        cin >> op;

        //Verifica se a opção está entre 1 e 2. Caso o login seja feito como gerente, é necessário ter o úsuario e senha para acessar o menu
        if(op == 1){
            cout << "\n---Login efetuado com sucesso!---\n" << endl;

            break;
        } else if(op == 2){
            if(loginGerente()){
                break;
            }
        } else{
            cout << "\n---Opção inválida!---\n" << endl;
        }
    }

    return op;
}

//Função para o úsuario fazer o login como gerente.
bool loginGerente(){
    string usuario, senha;
    int op;

    while(true){
        cout << "\n---Login Gerente---" << endl;
        cout << "Usuário: ";
        cin.ignore();
        getline(cin, usuario);

        cout << "Senha: ";
        cin.ignore();
        getline(cin, senha);

        if(usuario == "admin" && senha == "admin"){
            cout << "\n---Login efetuado com sucesso!---\n" << endl; //Retorna true caso o úsuario digite o úsuario e senha corretos

            return true;
        } else{
            do{
                cout << "\n---Usuário ou senha incorretos!---\n" << endl;
                cout << "1- Tentar novamente\n" << "2- Voltar" << endl;
                cout << "Opção: ";
                cin >> op;

                if(op == 2){
                    return false; //E false caso o úsuario deseje voltar para a tela inicial de login
                }
            } while(op != 1);
        }
    }
}