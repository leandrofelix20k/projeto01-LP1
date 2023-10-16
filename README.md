# Projeto 01 de Linguagem de Programação I 2023.2

## Sobre o Projeto:
O projeto consiste na criação de um sistema para o gerenciamento de pedidos de uma
lanchonete. A lanchonete vende sandúiches e sucos. Nesse sistema, o úsuario pode ter
acesso a dois perfis, um para o cliente e o outro para o gerente. Para o cliente, o login é feito sem que haja a necessidade do usuário digitar uma senha. Já para o gerente, o login é feito com uma senha.

---

## Funcionalidades do Sistema:
O sistema conta com as seguintes funcionalidades:

### **Funcionalidades do Cliente:**
O programa conta com a seguintes funcionalidades para o cliente:
1. Listar os sanduíches disponíveis.
2. Listar os sucos disponíveis.
3. Escolher o lanche desejado.
4. Calcular o valor total do pedido.
5. Ver elementos do carrinho.
6. Remover elementos do carrinho.

### **Funcionalidades do Gerente:**
Para o gerente, o login é feito com o nome do usuário e uma senha. ambos são
definidos como `"admin"`.

O programa conta com a seguintes funcionalidades para o gerente:
1. Listar os sanduíches disponíveis.
2. Listar os sucos disponíveis.
3. Adicionar um novo sanduíche.
4. Adicionar um novo suco.
5. Modificar o preço de um sanduíche.
6. Modificar o preço de um suco.
7. Remover um sanduíche.
8. Remover um suco.

---

## Organização do Projeto:
* main.cpp - Arquivo principal do projeto.
* login.cpp - Funções para o login do cliente e do gerente.
* arquivos.cpp - Funções para a manipulação dos arquivos, onde também é manipulado as
estruturas STL map.
* cliente.cpp - Funções para o perfil do cliente.
* gerente.cpp - Funções para o perfil do gerente.

---

## Como executar o projeto:
### **Compilar:**
    make compilar
### **Rodar**
    make run