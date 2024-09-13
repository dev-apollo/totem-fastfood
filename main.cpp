#include "fastfood.hpp"

int main()
{
    vector<item> hamburgueres;
    vector<item> adicionais;
    vector<item> bebidas;
    vector<item> sobremesas;
    
    hamburgueres.push_back(cadastrarItem("X-Tudo", 23.99, "Tem de tudo mesmo!"));
    hamburgueres.push_back(cadastrarItem("X-Bacon", 22.99, "A Peppa Pig nao gosta desse."));
    hamburgueres.push_back(cadastrarItem("X-Egg", 20.99, "Cocorico!"));
    bebidas.push_back(cadastrarItem("Fonta Uva", 9.99, "O melhor sabor."));
    bebidas.push_back(cadastrarItem("Caco-cola", 4.99, "Bem baratinha."));
    bebidas.push_back(cadastrarItem("Sprrrrite", 9.99, "Atchim!"));
    adicionais.push_back(cadastrarItem("Cheddar", 1.99, "Nhame nhame."));
    adicionais.push_back(cadastrarItem("Cebola Caramelizada", 3.99, "Tem quem nao goste, fazer o que?"));
    sobremesas.push_back(cadastrarItem("Musse de Maracuja", 12.99, "Amarelado como eu gosto."));
    sobremesas.push_back(cadastrarItem("Sagu", 10.99, "Tem um gosto meio roxo."));

    
    bool run = true;
    do{
        int opcao = admOuCliente();
        if(opcao == 1){
            int escolha = escolherTipoDeItem();
            switch(escolha){
                case 1: {
                    hamburgueres.push_back(solicitarInfos());
                    break;
                }
                case 2: {
                    adicionais.push_back(solicitarInfos());
                    break;
                }
                case 3: {
                    bebidas.push_back(solicitarInfos());
                    break;
                }
                case 4: {
                    sobremesas.push_back(solicitarInfos());
                    break;
                }
            }
        }else if(opcao == 2){
            int opcao;
            pedido novoPedido = fazerPedido(hamburgueres, bebidas, sobremesas, adicionais);
            revisarPedido(novoPedido);
            alterarPedido(novoPedido, hamburgueres, bebidas, sobremesas, adicionais);
            cout<<"Deseja cancelar o pedido?"<<endl<<"[1] - Cancelar"<<endl<<"[2] - Continuar para o pagamento"<<endl;
            do{
                cin>>opcao;
                if(opcao > 2 || opcao < 1){
                    cout<<"Opcao invalida, selecione uma opcao valida."<<endl;
                }
            }while(opcao > 2 || opcao < 1);
            if(opcao == 1){
                cout<<"Pedido cancelado."<<endl;
            }else{
                cout<<"Pedido pago com sucesso!"<<endl;
            }
        }else{
            cout<<"Saindo..."<<endl;
            run = false;
        }
    }while(run);
}