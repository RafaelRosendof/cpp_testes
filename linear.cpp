#include<iostream>
#include<vector>
#include <array>

template<typename T, size_t tam>
int buscaLinear(const std::array<T,tam>& itens, const T& key){
    for(size_t i{0};i<itens.size();i++){
        if(key == itens[i])
            return i;//retornando o indice
    }

    return -1; //não foi encontrado o item
}

int main(){
    const size_t aray_princi{100000}; //tamanho do array

    std::array<long long, aray_princi> array_busca;//criando o array
    


    for(size_t i{0};i<array_busca.size();i++){
        array_busca[i] = 2 * i; //criando data 
    }

    std::cout<<"entre com o inteiro que vc quer pesquisar: ";
    long long chave;
    std::cin>> chave;
    std::cout<<std::endl;
    int elemento{buscaLinear(array_busca,chave)};

    if(elemento != -1){
        std::cout<<elemento<<std::endl;
    }
    
}
