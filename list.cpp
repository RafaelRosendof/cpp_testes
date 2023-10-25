#include <iostream>
#include <stdexcept>

template <typename T>
class Fila {
private:
    T* lista;          // Ponteiro para o array que armazena os elementos da fila.
    size_t capacidade; // Capacidade máxima da fila.
    size_t tamanho;    // Número atual de elementos na fila.
    T* inicio;         // Ponteiro para o início da fila.
    T* fim;            // Ponteiro para o final da fila.

public:
    Fila(size_t capacidade = 100) : capacidade(capacidade), tamanho(0) {
        lista = new T[capacidade]; // Aloca espaço para o array.
        inicio = lista;            // Inicializa o ponteiro de início.
        fim = lista;               // Inicializa o ponteiro de fim.
    }

    ~Fila() {
        delete[] lista; // Libera a memória alocada para o array.
    }

    void enqueue(T v) {
        if (tamanho == capacidade) {
            throw std::runtime_error("A fila está cheia.");
        }
        *fim = v;     // Adiciona o elemento no final.
        fim++;        // Atualiza o ponteiro de fim.
        tamanho++;    // Incrementa o tamanho.
        if (fim == lista + capacidade) {
            fim = lista; // Volta ao início do array circular.
        }
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("A fila está vazia.");
        }
        inicio++;     // Remove o elemento do início.
        tamanho--;    // Decrementa o tamanho.
        if (inicio == lista + capacidade) {
            inicio = lista; // Volta ao início do array circular.
        }
    }

    T front() const {
        if (isEmpty()) {
            throw std::runtime_error("A fila está vazia.");
        }
        return *inicio; // Retorna o elemento do início.
    }

    T back() const {
        if (isEmpty()) {
            throw std::runtime_error("A fila está vazia.");
        }
        T* temp = fim - 1;
        if (temp < lista) {
            temp = lista + capacidade - 1; // Volta ao final do array circular.
        }
        return *temp; // Retorna o elemento do final.
    }

    bool isEmpty() const {
        return tamanho == 0; // Verifica se a fila está vazia.
    }

    void clear() {
        tamanho = 0;     // Limpa a fila.
        inicio = lista;  // Reinicializa o ponteiro de início.
        fim = lista;     // Reinicializa o ponteiro de fim.
    }

    size_t size() const {
        return tamanho; // Retorna o tamanho atual da fila.
    }
};

int main() {
    Fila<int> fila;

    fila.enqueue(1);
    fila.enqueue(2);
    fila.enqueue(3);

    std::cout << "Front: " << fila.front() << std::endl;
    std::cout << "Back: " << fila.back() << std::endl;
    std::cout << "Size: " << fila.size() << std::endl;

    fila.dequeue();

    std::cout << "Front after dequeue: " << fila.front() << std::endl;

    fila.clear();

    std::cout << "Is empty? " << (fila.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
