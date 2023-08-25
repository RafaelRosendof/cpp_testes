#include <iostream>
#include<array>
#include<ctime>
#include<random>
#include<algorithm>

//fazendo uma mostra mais formal do algoritmo de busca binária

template<typename T,size_t tamanho>
void mostraNum(const std::array<T, tamanho>& itens,size_t low, size_t high){
    for(size_t i{0};i<itens.size() && i<low;i++){
        std::cout<<" ";
    }
    for(size_t i{low};i<itens.size() && i<=high;i++){
        std::cout<<itens[i]<<" ";
    }
    std::cout<<std::endl;
}

template <typename T, size_t tamanho>
int binario(const std::array<T,tamanho>& itens,const T& chave){
    int low{0}; //item mais baixo 
    int high{static_cast<int>(itens.size())-1};
    int meio{(low+high+1)/2};
    int localizacao{-1};

    do{
        mostraNum(itens, low, high);

        for(int i{0};i<meio;i++){
            std::cout<<" ";
        }
        std::cout<<" * "<<std::endl;
    if(chave == itens[meio]){
        localizacao = meio;
    }
    else if(chave<itens[meio]){
        high = meio-1;
    }
    else{
        low = meio+1;
    }

    meio = (low + high +1)/2;
    
    }while ((low<=high) && (localizacao == -1));

    return localizacao;
}

int main(){
   std::default_random_engine engine{
        static_cast<unsigned int>(time(nullptr))};
        std::uniform_int_distribution<unsigned int> randomInt{10,99};

        const size_t tamanho{15};
        std::array<int,tamanho> array_de_busca;

        for(int &itens:array_de_busca){
            itens = randomInt(engine);
        }
        std::sort(array_de_busca.begin(),array_de_busca.end());
        
        mostraNum(array_de_busca,0,array_de_busca.size()-1);

        std::cout<<"Coloque o valor de busca do array: ";
        int chave;
        std::cin>>chave;
        std::cout<<std::endl;

        while(chave != -1){
            int position{binario(array_de_busca,chave)};

            if(position == -1){
                std::cout<<"não achado "<<chave<< std::endl;
            }
            else{
                std::cout<<"achado "<< position<< std::endl;
            }

            std::cout<<"\n\n pf entre com um inteiro válido ou -1 para sair: ";
            std::cin>>chave;
            std::cout<<std::endl;
        }
}


