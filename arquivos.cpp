#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

#include "arquivos.hpp"

using namespace std;

//Cria os mapas que armazenarão os sanduiches, sucos e o carrinho
map<string, float> sanduiches;
map<string, float> sucos;
map<string, float> carrinho;

//Lê os arquivos de sanduiches e sucos. Recebe como parâmetro o nome do arquivo (suco ou sanduiche)
void lerArquivo(string nomeArquivo){
    vector<string> linhas;
    fstream arquivo;

    //Abre ou cria o arquivo de acordo com o nome passado como parâmetro
    arquivo.open(nomeArquivo + ".txt", ios::in);

    //Lê o arquivo e armazena as linhas em um vetor
    string temp;
    while(getline(arquivo, temp)){
        linhas.push_back(temp);
    }
    arquivo.close();

    //Imprime uma mensagem caso o arquivo esteja vazio
    if(linhas.empty()){
        cout << "\n---Nenhum " << nomeArquivo << " cadastrado!---" << endl;
    }

    //Armazena os dados do arquivo no mapa correspondente
    if(nomeArquivo == "sanduiche"){
        for(int i = 0; i < linhas.size(); i += 2){
            sanduiches[linhas[i]] = stof(linhas[i + 1]); //No mapa é guardado o nome e o preço do lanche. O preço é convertido para float
        }
    } else if(nomeArquivo == "suco"){
        for(int i = 0; i < linhas.size(); i += 2){
            sucos[linhas[i]] = stof(linhas[i + 1]);
        }
    }
}

//Atualiza o arquivo de acordo com o mapa do sanduiche ou suco. Recebe como parâmetro o nome do arquivo.
void atualizarArquivo(string nomeArquivo){
    fstream arquivo;
    map<string, float>::iterator it; //Iterador para percorrer o mapa

    arquivo.open(nomeArquivo + ".txt", ios::out); //Abre ou cria o arquivo de acordo com o nome passado como parâmetro

    if(nomeArquivo == "sanduiche"){
        //Laço para percorrer o mapa e escrever os dados no arquivo. É escrito duas linhas, uma para o nome e outra para o preço
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

//Lista os produtos de acordo com o nome do produto passado como parâmetro
void listarProdutos(string nomeProduto){
    map<string, float>::iterator it; //Iterador para percorrer o mapa

    cout << fixed << setprecision(2); //Define a precisão de duas casas decimais para os valores float para a impressão

    if(nomeProduto == "sanduiche"){
        //Imprime uma mensagem caso o mapa esteja vazio
        if(sanduiches.empty()){
            cout << "\n---Nenhum sanduíche cadastrado!---" << endl;
        } else{
            cout << "\n---Sanduíches---" << endl;
            for(it = sanduiches.begin(); it != sanduiches.end(); it++){
                cout << it->first << " - R$" << it->second << endl; //Lista o nome do lanche e o preço
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

//Verifica se o item passado como parâmetro está no mapa de sanduiches ou sucos. Retorna true se estiver e false caso contrário
bool verificarItem(string nomeProduto, string nomeItem){
    //Verifica se o item está no mapa do produto correspondente
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

//Adiciona um item e o seu preço ao mapa de sanduiches ou sucos.
void addItem(string nomeProduto, string nomeItem, float precoItem){
    if(verificarItem(nomeProduto, nomeItem)){
        cout << "\n---Este produto já foi cadastrado!---\n" << endl; //Imprime uma mensagem caso o item já esteja cadastrado
    } else{
        //Caso contrário, adiciona o item e o preço ao mapa correspondente
        if(nomeProduto == "sanduiche"){
            sanduiches[nomeItem] = precoItem; //A chave do mapa é o nome do item e o valor é o preço
        } else if(nomeProduto == "suco"){
            sucos[nomeItem] = precoItem;
        }
        atualizarArquivo(nomeProduto); //Por fim, atualiza o arquivo correspondente

        cout << "\n---" << nomeProduto << " adicionado!---\n" << endl;
    }
}

//Remove um item do mapa de sanduiches ou sucos
void removerItem(string nomeProduto, string nomeItem){
    if(verificarItem(nomeProduto, nomeItem) == false){
        cout << "\n---Este " << nomeProduto << " não foi cadastrado!---\n" << endl; //Imprime uma mensagem caso o item não esteja cadastrado no mapa
    } else{
        //Caso contrário, remove o item do mapa correspondente
        if(nomeProduto == "sanduiche"){
            sanduiches.erase(nomeItem); //O erase recebe como parâmetro o nome do item e o remove do mapa
        } else if(nomeProduto == "suco"){
            sucos.erase(nomeItem);
        }
        atualizarArquivo(nomeProduto); //Por fim, atualiza o arquivo correspondente

        cout << "\n---" << nomeProduto << " removido com sucesso!---\n" << endl;
    }
}

//Modifica o preço de um item do mapa. Recebe como parâmetro o nome do produto, o nome do item e o novo preço
void modificarPreco(string nomeProduto, string nomeItem, float novoPreco){
    if(verificarItem(nomeProduto, nomeItem) == false){
        cout << "\n---Este " << nomeProduto << " não foi cadastrado!---\n" << endl; //Faz a verificação se o item está cadastrado no mapa
    } else{
        //Caso esteja, altera o preço do item
        if(nomeProduto == "sanduiche"){
            sanduiches[nomeItem] = novoPreco;
        } else if(nomeProduto == "suco"){
            sucos[nomeItem] = novoPreco;
        }
        atualizarArquivo(nomeProduto);

        cout << "\n---Preço do " << nomeProduto << " alterado!---\n" << endl;
    }
}

void exibirCarrinho(){
    map<string, float>::iterator it; //Iterador para percorrer o mapa do carrinho

    cout << fixed << setprecision(2); //Define a precisão de duas casas decimais para os valores float para a impressão

    if(carrinho.empty()){
        cout << "\n---Carrinho vazio!---" << endl; //Imprime uma mensagem caso o carrinho esteja vazio
    } else{
        cout << "\n---Carrinho---" << endl;
        //Laço para percorrer o mapa e imprimir os itens e seus preços
        for(it = carrinho.begin(); it != carrinho.end(); it++){
            //imprime o nome do item e o preço de acordo com o iterador, sendo o it-first o nome e o it->second o preço
            cout << "\n   "<<it->first << " - R$" << it->second << endl;
        }
        cout << endl;
    }
}

void valorTotalCarrinho(){
    map<string, float>::iterator it; //Iterador para percorrer o mapa do carrinho
    float valorTotal = 0; //Variável para armazenar o valor total do carrinho

    cout << fixed << setprecision(2); //Define a precisão de duas casas decimais para os valores float para a impressão

    //Se o mapa do carrinho não estiver vazio, percorre o mapa e soma os preços dos itens
    if(!carrinho.empty()){
        for(it = carrinho.begin(); it != carrinho.end(); it++){
            valorTotal += it->second;
        }
    }
    cout << "\n---Valor total: R$" << valorTotal << "---\n" << endl; //Por fim, imprime o valor total
}

//Adiciona um item ao carrinho. Recebe como parâmetro o nome do produto e o nome do item a ser adicionado
void addItemCarrinho(string nomeProduto, string nomeItem){
    //Verifica se o item está cadastrado no mapa correspondente
    if(verificarItem(nomeProduto, nomeItem) == false){
        cout << "\n---Este " << nomeProduto << " não consta no cardápio!---" << endl; //Imprime uma mensagem caso o item não esteja cadastrado
        cout << "       ---Escolha outro " << nomeProduto << "!---\n" << endl;
    } else{
        //Caso esteja, adiciona o item ao carrinho
        if(nomeProduto == "sanduiche"){
            carrinho[nomeItem] = sanduiches[nomeItem];
            cout << "\n---" << nomeItem << " foi adicionado ao carrinho!---\n" << endl;
        } else if(nomeProduto == "suco"){
            carrinho[nomeItem] = sucos[nomeItem];
            cout << "\n---Suco de " << nomeItem << " foi adicionado ao carrinho!---\n" << endl;
        }
    }
}

//Remove um item do carrinho. Recebe como parâmetro o nome do item a ser removido
void removerItemCarrinho(string nomeItem){
    //Verifica se o item está no carrinho
    if(carrinho.find(nomeItem) == carrinho.end()){
        cout << "\n---Este item não consta no carrinho!---\n" << endl; //Imprime uma mensagem caso o item não esteja no carrinho
    } else{
        carrinho.erase(nomeItem); //Caso esteja, remove o item do carrinho
        cout << "\n---Item removido do carrinho!---\n" << endl;
    }
}