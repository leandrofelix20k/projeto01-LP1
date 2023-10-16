#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

using namespace std;

void lerArquivo(string nomeArquivo);
void atualizarArquivo(string nomeArquivo);
void listarProdutos(string nomeProduto);
bool verificarItem(string nomeProduto, string nomeItem);
void addItem(string nomeProduto, string nomeItem, float precoItem);
void removerItem(string nomeProduto, string nomeItem);
void modificarPreco(string nomeProduto, string nomeItem, float novoPreco);
void exibirCarrinho();
void valorTotalCarrinho();
void addItemCarrinho(string nomeProduto, string nomeItem);
void removerItemCarrinho(string nomeItem);

#endif