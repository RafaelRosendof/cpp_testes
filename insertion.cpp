//programa de um insertion sort
//author: Rafael Rosendo

#include<iostream>
#include<iomanip>
#include<array>

//função template
template<typename T,size_t tam>
void insertion(std::array<T,tam>& itens){
    for(size_t i{1};i<itens.size();i++){
        T insert{itens[i]};//salvando o valor do proximo elemento para inserir
        size_t move{i};  //iniciando a localização para por o elemento

        while((move > 0) && (itens[move-1] > insert)){ //fazendo a busca de qual elemento colocar no lugar
            //colocando elementos a direita
            itens[move] = itens[move -1];
            --move;
        }
        itens[move] = insert; //colocando de volta no array 
    }
}

int main(){
    const size_t array{10};
    std::array<int, array> data{2,-1,4,69,-9,10,54,32,70,31};

    std::cout<<"Array original: ";
    for(size_t i{0};i<data.size();i++){
        std::cout<<std::setw(4)<<data[i];
    }
    std::cout<<"\n\n";
    insertion(data);
    std::cout<<"Array organizado: ";
    for(size_t i{0};i<data.size();i++){
        std::cout<<std::setw(4)<<data[i];
    }
    std::cout<<std::endl;
}

/*
A ideia central do Insertion Sort é construir uma lista ordenada no início da lista de entrada. Ele faz isso inserindo elementos na posição correta, movendo os elementos maiores para a direita.

O loop externo percorre a lista a partir do segundo elemento (índice 1). Ele assume que o primeiro elemento (índice 0) já está "ordenado".

Dentro do loop externo, você armazena o valor do elemento atual em insert.

O loop interno começa na posição move (a posição atual) e continua até que a posição seja maior que 0 e o elemento na posição anterior (itens[move-1]) seja maior do que o valor de insert.

Dentro do loop interno, você move os elementos maiores para a direita, abrindo espaço para inserir o valor insert.

Uma vez que o loop interno termine, você insere o valor de insert na posição correta (move) na lista.

Isso se repete para todos os elementos da lista, garantindo que a lista à esquerda do índice atual esteja sempre ordenada.*/