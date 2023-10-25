#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

template <typename T>
class MyVector {
private:
    T* arr;            // Um ponteiro para o vetor dinâmico
    T* originalArr;    // Um ponteiro para o vetor original para liberação posterior
    size_t capacity;    // A capacidade atual do vetor
    T* first;          // Um ponteiro para o primeiro elemento no vetor
    T* last;           // Um ponteiro para o próximo elemento após o último no vetor

public:
    MyVector() {
        capacity = 1;
        arr = new T[capacity];   // Inicializa o vetor com capacidade 1
        originalArr = arr;      // Mantém um ponteiro para o vetor original
        first = arr;            // Inicializa o ponteiro first
        last = arr;             // Inicializa o ponteiro last
    }

    ~MyVector() {
        delete[] originalArr;   // Libera a memória alocada para o vetor original
    }

    size_t size() {
        return std::distance(first, last);  // Retorna o tamanho do vetor
    }

    void reserve(size_t new_capacity) {
        T* newData = new T[new_capacity];  // Aloca um novo vetor com a nova capacidade
        std::copy(first, first + size(), newData);  // Copia os elementos do vetor original para o novo vetor
        delete[] originalArr;  // Libera a memória do vetor original
        arr = newData;         // Atualiza o ponteiro para o novo vetor
        capacity = new_capacity;  // Atualiza a capacidade
        first = arr;           // Atualiza o ponteiro first
        last = arr + size();   // Atualiza o ponteiro last
    }

    bool isfull() const {
        return std::distance(first, last) == capacity;  // Verifica se o vetor está cheio
    }

    void push_back(T data) {
        if (isfull()) {
            reserve(2 * capacity);  // Dobra a capacidade se o vetor estiver cheio
        }
        *last = data;  // Adiciona um novo elemento no final do vetor
        ++last;
    }

    void pop_back();

    T front() {
        if (first < last) {
            return *first;  // Retorna o primeiro elemento do vetor
        } else {
            throw std::out_of_range("Vector is empty.");
        }
    }

    T back() {
        if (first < last) {
            return *(last - 1);  // Retorna o último elemento do vetor
        } else {
            throw std::out_of_range("Vector is empty.");
        }
    }

    bool empty() {
        return first == last;  // Verifica se o vetor está vazio
    }

    size_t get_capacity() {
        return capacity;  // Retorna a capacidade atual do vetor
    }

    T& operator[](size_t index) {
        if (index >= size()) {
            throw std::out_of_range("Index out of range.");
        }
        return arr[index];  // Retorna o elemento no índice especificado
    }
};

template <typename T>
void MyVector<T>::pop_back() {
    if (last > first) {
        --last;  // Remove o último elemento do vetor
    }
}

int main() {
    MyVector<size_t> myVector;

    // Push some elements into the vector
    for (int i = 1; i <= 10; ++i) {
        myVector.push_back(i * 10);  // Adiciona elementos ao vetor
    }

    std::cout << "Vector size: " << myVector.size() << std::endl;
    std::cout << "Vector capacity: " << myVector.get_capacity() << std::endl;

    // Access and print elements
    for (size_t i = 0; i < myVector.size(); ++i) {
        std::cout << "Element at index " << i << ": " << myVector[i] << std::endl;  // Acessa e imprime os elementos
    }

    // Access front and back
    std::cout << "Front element: " << myVector.front() << std::endl;  // Acessa e imprime o primeiro elemento
    std::cout << "Back element: " << myVector.back() << std::endl;    // Acessa e imprime o último elemento

    // Pop elements
    myVector.pop_back();  // Remove o último elemento
    myVector.pop_back();  // Remove o último elemento

    std::cout << "Vector size after popping: " << myVector.size() << std::endl;

    return 0;
}
