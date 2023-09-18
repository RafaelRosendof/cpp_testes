#include <cstddef>
#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>

//A exemple of a simple algorithm but very eficient 
//it's the quick_sort, have a chance and try 
//please change the numbers and increment tests
//author: Rafael Rosendo Faustino

template<typename T>
void quick(std::vector<T>& figas) {
    if (figas.size() > 1) {
        std::vector<T> menor;
        std::vector<T> meesmo;
        std::vector<T> maior;

        auto escolhe = figas[figas.size() / 2];

        for (auto& i : figas) {
            if (i < escolhe)
                menor.push_back(std::move(i));
            else if (i > escolhe)
                maior.push_back(std::move(i));
            else
                meesmo.push_back(std::move(i));
        }
        quick(menor);
        quick(maior);

        std::move(std::begin(menor), std::end(menor), std::begin(figas));
        std::move(std::begin(meesmo), std::end(meesmo), std::begin(figas) + menor.size());
        std::move(std::begin(maior), std::end(maior), std::begin(figas) + menor.size() + meesmo.size());
    }
}

int main() {
    std::cout << "Mostrando o quick_sort" << std::endl;

    const size_t Arrays = 75;
    std::vector<int> figass{-45, 47, -89, 65, 32, 14, 15, 25, 37, 85, 40, 26,
        75, 47, 89, 65, 32, -14, 75, 64, -58, 47, 69, 85, 32, 14, 78, 74, 15, 45, 58, 1,
        -75, 45, 12, 32, 14, 75, 85, 95, 76, -13, 47, 85, 102, 301, 407, 84, 569, 12, 451,
        235, -36, 247, 356, 124, 356, 287, 236, 214, 365, 754, 214, 32, 65, 98, 78, 12,
        45, 23, 14, 7, 23, 54, 873};
    
    std::cout << "Array nativo " << std::endl;
    for (int i = 0; i < figass.size(); i++) {
        std::cout << std::setw(4) << figass[i];

        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;

    quick(figass);
    std::cout << "Array ordenado: " << std::endl;

    for (int i = 0; i < figass.size(); i++) {
        std::cout << std::setw(4) << figass[i];
        if ((i + 1) % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
