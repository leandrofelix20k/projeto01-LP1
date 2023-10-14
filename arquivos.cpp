#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

#include "arquivos.hpp"

using namespace std;

map<string, float> sanduiches;
map<string, float> sucos;
map<string, float> carrinho;

void lerArquivo(string nomeArquivo){
    vector<string> linhas;
    fstream arquivo;

    arquivo.open(nomeArquivo + ".txt", ios::in);

    string temp;
    while(getline(arquivo, temp)){
        linhas.push_back(temp);
    }
    arquivo.close();

    if(linhas.empty()){
        cout << "\n---Nenhum " << nomeArquivo << " cadastrado!---" << endl;
    }

    if(nomeArquivo == "sanduiche"){
        for(int i = 0; i < linhas.size(); i += 2){
            sanduiches[linhas[i]] = stof(linhas[i + 1]);
        }
    } else if(nomeArquivo == "suco"){
        for(int i = 0; i < linhas.size(); i += 2){
            sucos[linhas[i]] = stof(linhas[i + 1]);
        }
    }
}

void atualizarArquivo(string nomeArquivo){
    fstream arquivo;
    map<string, float>::iterator it;

    arquivo.open(nomeArquivo + ".txt", ios::out);

    if(nomeArquivo == "sanduiche"){
        for(it = sanduiches.begin(); it != sanduiches.end(); it++){
            arquivo << it->first << endl;
            arquivo << it->second << endl;
        }
    } else if(nomeArquivo == "suco"){
        for(it = sucos.begin(); it != sucos.end(); it++){
            arquivo << it->first << endl;
            arquivo << it->second << endl;
        }
    }

    arquivo.close();
}

void listarProdutos(string nomeProduto){
    map<string, float>::iterator it;

    cout << fixed << setprecision(2);

    if(nomeProduto == "sanduiche"){
        if(sanduiches.empty()){
            cout << "\n---Nenhum sanduíche cadastrado!---" << endl;
        } else{
            cout << "\n---Sanduíches---" << endl;
            for(it = sanduiches.begin(); it != sanduiches.end(); it++){
                cout << it->first << " - R$" << it->second << endl;
            }
        }
    } else if(nomeProduto == "suco"){
        if(sucos.empty()){
            cout << "\n---Nenhum suco cadastrado!---" << endl;
        } else{
            cout << "\n---Sucos---" << endl;
            for(it = sucos.begin(); it != sucos.end(); it++){
                cout << it->first << " - R$" << it->second << endl;
            }
        }
    }
    cout << endl;
}

bool verificarItem(string nomeProduto, string nomeItem){
    if(nomeProduto == "sanduiche"){
        if(sanduiches.find(nomeItem) != sanduiches.end()){

            return true;
        }
    } else if(nomeProduto == "suco"){
        if(sucos.find(nomeItem) != sucos.end()){

            return true;
        }
    }

    return false;
}

void addItem(string nomeProduto, string nomeItem, float precoItem){
    if(verificarItem(nomeProduto, nomeItem)){
        cout << "\n---Este produto já foi cadastrado!---\n" << endl;
    } else{
        if(nomeProduto == "sanduiche"){
            sanduiches[nomeItem] = precoItem;
        } else if(nomeProduto == "suco"){
            sucos[nomeItem] = precoItem;
        }
        atualizarArquivo(nomeProduto);

        cout << "\n---" << nomeProduto << " adicionado!---\n" << endl;
    }
}

void addItemCarrinho(string nomeProduto, string nomeItem){
    if(verificarItem(nomeProduto, nomeItem) == false){
        cout << "\n---Este " << nomeProduto << " não consta no cardápio!---\n" << endl;
        cout << "\n---Escolha outro " << nomeProduto << "!---\n" << endl;
    } else{
        if(nomeProduto == "sanduiche"){
            carrinho[nomeItem] = sanduiches[nomeItem];
        } else if(nomeProduto == "suco"){
            carrinho[nomeItem] = sucos[nomeItem];
        }
    }
}

void modificarPreco(string nomeProduto, string nomeItem, float novoPreco){
    if(verificarItem(nomeProduto, nomeItem) == false){
        cout << "\n---Este " << nomeProduto << " não foi cadastrado!---\n" << endl;
    } else{
        if(nomeProduto == "sanduiche"){
            sanduiches[nomeItem] = novoPreco;
        } else if(nomeProduto == "suco"){
            sucos[nomeItem] = novoPreco;
        }
        atualizarArquivo(nomeProduto);

        cout << "\n---Preço do " << nomeProduto << " alterado!---\n" << endl;
    }
}

void removerItem(string nomeProduto, string nomeItem){
    if(verificarItem(nomeProduto, nomeItem) == false){
        cout << "\n---Este " << nomeProduto << " não foi cadastrado!---\n" << endl;
    } else{
        if(nomeProduto == "sanduiche"){
            sanduiches.erase(nomeItem);
        } else if(nomeProduto == "suco"){
            sucos.erase(nomeItem);
        }
        atualizarArquivo(nomeProduto);

        cout << "\n---" << nomeProduto << " removido com sucesso!---\n" << endl;
    }
}

void exibirCarrinho(){
    map<string, float>::iterator it;
    float valorTotal = 0;

    cout << fixed << setprecision(2);

    if(carrinho.empty()){
        cout << "\n---Carrinho vazio!---\n" << endl;
    } else{
        cout << "\n---Carrinho---" << endl;
        for(it = carrinho.begin(); it != carrinho.end(); it++){
            cout << it->first << " - R$" << it->second << endl;
            valorTotal += it->second;
        }
        cout << "Valor total: R$" << valorTotal << endl;
    }
    cout << endl;
}