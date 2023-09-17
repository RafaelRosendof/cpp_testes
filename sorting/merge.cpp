#include <algorithm>
#include <cstddef>
#include <iostream>
#include <array>
#include <ctime>
#include <random>

//code for explaing the merge sort algorithm 
//free to use and copy
//that way can have a good view of how it works
//have fun and go check my other algorithm
//Rafael Rosendo Faustino

template<typename T, std::size_t size>
void display(const std::array<T,size>& figas,size_t low, size_t high){
    for(size_t i{0}; i < figas.size() && i < low ; ++i){
        std::cout<<"    ";
    }
    for(size_t i{low};i<figas.size() && i<= high; ++i){
        std::cout<<figas[i]<<"  ";
    }
    std::cout<<std::endl;
}



template<typename T, std::size_t size>
void mergee(std::array<T, size>& figas,size_t left, size_t mid1, size_t mid2 , size_t rigth){
    size_t LeftIn{left};
    size_t combinado{left};
    size_t rigthIn{mid2};
    std::array<T, size>combinadoo;

    std::cout<<"merge:    ";
    display(figas, left, mid1);
    std::cout<<"        ";
    display(figas, mid2, rigth);
    std::cout<<std::endl;

    while(LeftIn <= mid1 && rigthIn <= rigth){
        if(figas[LeftIn] <= figas[rigthIn]){
            combinadoo[combinado++] = figas[LeftIn++];
        }
        else{
            combinadoo[combinado++] = figas[rigthIn++];
        }
    }
    if(LeftIn == mid2){
        while(rigthIn <= rigth){
            combinadoo[combinado++] = figas[rigthIn++];
        }
    }
    else{
        while(LeftIn <= mid1){
            combinadoo[combinado++] = figas[LeftIn++];
        }
    }
    for(size_t i{left};i <= rigth; i++){
        figas[i] = combinadoo[i];   //colocando os valores dentro do array
    }

    std::cout<<"        ";
    display(figas, left, rigth);
    std::cout<<std::endl;
}

template<typename T, std::size_t size>
void Sorte(std::array<T,size>& figas, size_t low, size_t high){
//função para organizar 
    if((high - low) >= 1){
        size_t mid1{(low + high) / 2};
        size_t mid2{mid1+1};

        std::cout<<" split:   ";
        display(figas,  low, high);
        std::cout<<"       ";
        display(figas, low, mid1);
        std::cout<<"        ";
        display(figas, mid2, high);
        std::cout<<std::endl;

        //divide o array dnv no meio e ordenando cada metade
        Sorte(figas,  low, mid1);
        Sorte(figas, mid2, high);
        mergee(figas, low, mid1,  mid2, high);
        
    }
}

int main(){

    std::default_random_engine engine{
        static_cast<unsigned int>(std::time(nullptr))};
     std::uniform_int_distribution<unsigned int> randomInt{10,99};


        const size_t arrayS{8};

        std::array<int, arrayS> dataset;
        for(int &figas : dataset){
            figas = randomInt(engine);
        }

        std::cout<<"Array normal: ";
        display(dataset, 0, dataset.size() - 1);
        std::cout<<std::endl;
    //array ordenado

    Sorte(dataset, 0, dataset.size() - 1);
    std::cout<<"Array ordenado: "<<std::endl;
    display(dataset, 0, dataset.size() - 1);
    
}