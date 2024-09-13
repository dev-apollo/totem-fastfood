#include "fastfood.hpp"

int admOuCliente(){
    int opcao;
    cout<<"Administrador ou cliente?"<<endl<<"[1] - Administrador"<<endl<<"[2] - Cliente"<<endl<<"[0] - Sair"<<endl;
    do{
        cin>>opcao;
        if(opcao > 2 || opcao < 0){
            cout<<"Opcao invalida, insira [1], [2] ou [0]."<<endl;
        }
    }while(opcao > 2 || opcao < 0);
    return opcao;
}

int escolherTipoDeItem(){
    int escolha;
    cout<<"Ola Administrador, deseja cadastrar qual tipo de produto?"<<endl<<"[1] - Hamburguer"<<endl<<"[2] - Adicional"<<endl<<"[3] - Bebida"<<endl<<"[4] - Sobremesa"<<endl<<"[0] - Cancelar"<<endl;
    do{
        cin>>escolha;
        if(escolha > 4 || escolha < 0){
            cout<<"Opcao invalida, insira [1], [2], [3], [4] ou [0]."<<endl;
        }
    }while(escolha > 4 || escolha < 0);
    return escolha;
}

item solicitarInfos(){
    string nome, descricao;
    double preco;
    cout<<"Insira o nome do produto: ";
    cin.ignore();
    getline(cin, nome);
    do{
        cout<<"Insira o preco do produto: ";
        cin>>preco;
        if(preco < 0.01){
            cout<<"O preco inserido eh invalido."<<endl;
        }
    }while(preco < 0.01);
    cout<<"Insira a descricao do produto: ";
    cin.ignore();
    getline(cin, descricao);
    item novoItem = cadastrarItem(nome, preco, descricao);
    cout<<novoItem.nome<<" foi cadastrado com sucesso!"<<endl<<endl;
    return novoItem;
}

item cadastrarItem(string nome, double preco, string descricao){
    item novoItem;
    novoItem.nome = nome;
    novoItem.preco = preco;
    novoItem.descricao = descricao;
    return novoItem;
}

pedido fazerPedido(vector<item> hamburgueres, vector<item> bebidas, vector<item> sobremesas, vector<item> adicionais){
    int adicional;
    pedido novoPedido;
    novoPedido.hamburguer = selecionarItem(hamburgueres, "hamburguer");
    cout<<"Desejas adicionais?"<<endl<<"[1] - Sim"<<endl<<"[2] - Nao"<<endl;
    do{
        cin>>adicional;
        if(adicional > 2 || adicional < 1){
            cout<<"Opcao invalida, selecione uma opcao valida."<<endl;
        }
    }while(adicional > 2 || adicional < 1);
    if(adicional == 1){
        do{
            novoPedido.adicionais.push_back(selecionarItem(adicionais, "adicional"));
            cout<<"Desejas outro?"<<endl<<"[1] - Sim"<<endl<<"[2] - Nao"<<endl;
            do{
                cin>>adicional;
                if(adicional > 2 || adicional < 1){
                    cout<<"Opcao invalida, selecione uma opcao valida."<<endl;
                }
            }while(adicional > 2 || adicional < 1);
        }while(adicional == 1);
    }
    novoPedido.bebida = selecionarItem(bebidas, "bebida");
    novoPedido.sobremesa = selecionarItem(sobremesas, "sobremesa");
    return novoPedido;
}

item selecionarItem(vector<item> item, string opcao){
    int i, escolha;
    cout<<"Escolha um(a)"<<opcao<<"."<<endl;
    for(i = 0; i < item.size(); i++){
        cout<<"["<<i+1<<"] - "<<item[i].nome<<" | "<<item[i].preco<<" | "<<item[i].descricao<<endl;
    }
    do {
        cin>>escolha;
        if(escolha > i || escolha < 1){
            cout<<"Opcao invalida, selecione uma opcao valida."<<endl;
        }
    }while(escolha > i || escolha < 1);
    if(opcao == "bebida"){
        cout<<"[1] - Com refil"<<endl<<"[2] - Sem refil"<<endl<<"O valor aumentara 5 reais!"<<endl;
        do{
            cin>>escolha;
            if(escolha > 2 || escolha < 1){
                cout<<"Opcao invalida, selecione uma opcao valida."<<endl;
            }
            if(escolha == 1){
                item[escolha-1].preco+5;
            }
        }while(escolha > 2 || escolha < 1);
    }
    return item[escolha-1];
}

void revisarPedido(pedido pedidoEspecifico){
    cout<<"O seu pedido foi:"<<endl;
    cout<<pedidoEspecifico.hamburguer.nome<<endl;
    for(int i = 0; i < pedidoEspecifico.adicionais.size(); i++){
        cout<<"+ "<<pedidoEspecifico.adicionais[i].nome<<endl;
    }
    cout<<pedidoEspecifico.bebida.nome<<endl;
    cout<<pedidoEspecifico.sobremesa.nome<<endl;
    cout<<"O preco final eh: "<<calcularPedido(pedidoEspecifico)<<endl;
}

double calcularPedido(pedido pedidoEspecifico){
    double valorFinal = pedidoEspecifico.hamburguer.preco + pedidoEspecifico.bebida.preco + pedidoEspecifico.sobremesa.preco;
    for(int i = 0; i < pedidoEspecifico.adicionais.size(); i++){
        valorFinal += pedidoEspecifico.adicionais[i].preco;
    }
    return valorFinal;
}

void alterarPedido(pedido &pedidoEspecifico, vector<item> hamburgueres, vector<item> bebidas, vector<item> sobremesas, vector<item> adicionais){
    int opcao, escolha;
    do{
        cout<<"Deseja alterar algo do seu pedido?"<<endl<<"[1] - Sim"<<endl<<"[2] - Nao"<<endl;
        do{
            cin>>opcao;
            if(opcao > 2 || opcao < 1){
                cout<<"Opcao invalida, selecione uma opcao valida."<<endl;
            }
        }while(opcao > 2 || opcao < 1);
            if(opcao == 1){
            cout<<"O que deseja alterar?"<<endl<<"[1] - Hamburguer"<<endl<<"[2] - Bebida"<<endl<<"[3] - Sobremesa"<<endl;
            do{
                cin>>escolha;
                if(escolha > 3 || escolha < 1){
                    cout<<"Opcao invalida, selecione uma opcao valida."<<endl;
                }
            }while(escolha > 3 || escolha < 1);
            switch(escolha){
                case 1: {
                    pedidoEspecifico.hamburguer = selecionarItem(hamburgueres, "hamburguer");
                    break;
                }
                case 2: {
                    pedidoEspecifico.bebida = selecionarItem(bebidas, "bebida");
                    break;
                }
                case 3: {
                    pedidoEspecifico.bebida = selecionarItem(sobremesas, "sobremesa");
                    break;
                }
            }
            revisarPedido(pedidoEspecifico);
        }
    }while(opcao == 1);
}