#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "arquivo.hpp"

using namespace std;

map<string, float> sanduiches;
map<string, float> sucos;

void lerArquivoSanduiche(){
    vector<string> linhas;
    fstream arquivoSanduiches;
    arquivoSanduiches.open("sanduiches.txt", ios::in);

    string temp;
    while(getline(arquivoSanduiches, temp)){
        linhas.push_back(temp);
    }
    arquivoSanduiches.close();

    if(linhas.empty()){
        cout << "Nenhum sanduíche cadastrado!" << endl;
    } else{
        for(int i = 0; i < linhas.size(); i+=2){
            sanduiches[linhas[i]] = stof(linhas[i + 1]);
        }
    }
}

void lerArquivoSuco(){
    vector<string> linhas;
    fstream arquivoSucos;
    arquivoSucos.open("sucos.txt", ios::in);

    string temp;
    while(getline(arquivoSucos, temp)){
        linhas.push_back(temp);
    }
    arquivoSucos.close();

    if(linhas.empty()){
        cout << "Nenhum suco cadastrado!" << endl;
    } else{
        for(int i = 0; i < linhas.size(); i+=2){
            sucos[linhas[i]] = stof(linhas[i + 1]);
        }
    }
}