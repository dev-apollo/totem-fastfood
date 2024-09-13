#ifndef FASTFOOD_HPP
#define FASTFOOD_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct item{
    string nome;
    double preco;
    string descricao;
};

struct pedido{
    item hamburguer;
    vector<item> adicionais;
    item bebida;
    item sobremesa;
};

int admOuCliente();
int escolherTipoDeItem();
item solicitarInfos();
item cadastrarItem(string nome, double preco, string descricao);
pedido fazerPedido(vector<item> hamburgueres, vector<item> bebidas, vector<item> sobremesas, vector<item> adicionais);
item selecionarItem(vector<item> itens, string opcao);
void revisarPedido(pedido pedidoEspecifico);
double calcularPedido(pedido pedidoEspecifico);
void alterarPedido(pedido &pedidoEspecifico, vector<item> hamburgueres, vector<item> bebidas, vector<item> sobremesas, vector<item> adicionais);
#endif