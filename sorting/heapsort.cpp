#include <cstddef>
#include <cstdint>
#include <iostream>
#include <array>
#include <iomanip>
#include <iterator>
#include <utility>


inline size_t leftC(size_t i){
    return 2 * i +1;
}

template < typename T, std::size_t size>
void baixo(std::array<T,size>& figas, size_t i, size_t n){

    size_t filho;
    T temp;

    for(temp = std::move( figas[i] ); leftC(i) < n; i = filho){
        filho = leftC(i);
        if(filho != n-1 && figas[filho] < figas[filho + 1])
            ++filho;

        if(temp < figas[filho])
            figas[i] = std::move(figas[filho]);
        else
            break;
    }
    figas[i] = std::move(temp);
}


template<typename T, std::size_t size>
void heap(std::array<T,size>& figas){
    for(size_t i{figas.size() / 2 - 1};i != SIZE_MAX; --i)
        baixo(figas,i,figas.size());


    for(size_t j{figas.size() - 1}; j > 0; --j){

        std::swap(figas[0], figas[j]);
        baixo(figas,0,j);
    }
    
}



int main(){

    std::cout<<"Mostrando o heapsort"<<std::endl;

  const size_t Arrays{75};
  std::array<int,Arrays> figass{-45,47,-89,65,32,14,15,25,37,85,40,26,
75,47,89,65,32,-14,75,64,-58,47,69,85,32,14,78,74,15,45,58,1,
-75,45,12,32,14,75,85,95,76,-13,47,85,102,301,407,84,569,12,451,
235,-36,247,356,124,356,287,236,214,365,754,214,32,65,98,78,12,
45,23,14,7,23,54,873};
    std::cout<<"Array nativo "<<std::endl;;
 for(int i{0};i<figass.size();i++){
        std::cout<<std::setw(4)<<figass[i];

        if((i+1) % 10 == 0){
            std::cout<<std::endl;
        }
    }


  std::cout << std::endl;

  heap(figass);
  std::cout << "Array ordenado: "<<std::endl;

    for(int i{0};i<figass.size();i++){
        std::cout<<std::setw(4)<<figass[i];
        if((i+1) % 10 == 0)
            std::cout<<std::endl;
    }
    std::cout<<std::endl;

  return 0;
}