#include <cstddef>
#include <iostream>
#include <array>
#include <iomanip>
#include <iterator>


template<typename T,std::size_t size>
void shellsort(std::array<T, size>& figas){
    for(int i= figas.size() /2 ; i > 0 ; i/=2){
	for(int j = i ; j< figas.size() ; ++j){
		T tmp = std::move(figas [j]);
	 	int x = j;

		for(; x>= i && tmp < figas[x-i]; x -= i)
			figas[x] = std::move(figas[x-i]);
	figas[x] = std::move(tmp);	
	}
    }
}

int main(){

    std::cout<<"Mostrando o shellsort"<<std::endl;

  const size_t Arrays{12};
  std::array<int,Arrays> figass{45,47,89,65,32,14,15,25,37,85,40,26,};
    std::cout<<"Array nativo: ";
 for(int i{0};i<figass.size();i++){
        std::cout<<std::setw(4)<<figass[i];
    }


  std::cout << std::endl;

  shellsort(figass);
  std::cout << "Array ordenado: ";

    for(int i{0};i<figass.size();i++){
        std::cout<<std::setw(4)<<figass[i];
    }
    std::cout<<std::endl;

  return 0;
}
