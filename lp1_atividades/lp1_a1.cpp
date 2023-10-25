#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<random>
#include<ctime>
#include<cstdlib>

class atividade {
public:
    int tamanho_1() {
        int size;
        std::cout << "Digite a quantidade de elementos para ser alocado: ";
        std::cin >> size;
        return size;
    }

    template <typename T, size_t size>
    void aloca_1() {
        int tamanho = tamanho_1();
        T* vetor_1 = new T[size];
        int count = 0;

        std::cout << "Caso queira alocar algum número, tecle o número, se quiser parar a operação digite 'q'\n";

        while (count < tamanho) {
            T elementos;
            std::cout << "Digite o número para ser alocado: ";
            std::cin >> elementos;

            if (elementos == "q") {
                break;
            }

            vetor_1[count] = elementos;
            count++;

            if (count == tamanho) {
                std::cout << "Vetor está cheio!!!!!!\n";
                break;
            }
        }

        delete[] vetor_1;
    }

    int** criarMatriz(int n) {
        int** matriz = new int*[n];
        for (int i = 0; i < n; i++) {
            matriz[i] = new int[n];
            for (int j = 0; j < n; j++) {
                matriz[i][j] = rand() % 2; // Preenche com números aleatórios 0 ou 1
            }
        }
        return matriz;
    }

    bool verificarEIdentidade(int** matriz, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j && matriz[i][j] != 1) {
                    return false; // A diagonal principal não contém apenas 1s
                } else if (i != j && matriz[i][j] != 0) {
                    return false; // Fora da diagonal principal, não contém apenas 0s
                }
            }
        }
        return true; // A matriz é uma matriz identidade
    }

    void realizarAtividade() {
        int n;
        std::cout << "Informe o tamanho da matriz quadrada: ";
        std::cin >> n;

        std::srand(static_cast<unsigned>(std::time(nullptr)));

        int** matriz = criarMatriz(n);

        std::cout << "Matriz gerada:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << matriz[i][j] << " ";
            }
            std::cout << "\n";
        }

        bool isIdentidade = verificarEIdentidade(matriz, n);
        if (isIdentidade) {
            std::cout << "A matriz é uma matriz identidade.\n";
        } else {
            std::cout << "A matriz não é uma matriz identidade.\n";
        }

        for (int i = 0; i < n; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }


    //questão 3

        void preencherVetor() {
         int tamanhoInicial = 10;
        int* vetor = new int[tamanhoInicial];
        int count = 0;

        while (count < tamanhoInicial) {
            int elemento;
            std::cout << "Digite o número para ser alocado (ou 'q' para parar): ";
            std::string entrada;
            std::cin >> entrada;

            if (entrada == "q") {
                break;
            }

            elemento = std::stoi(entrada);
            vetor[count] = elemento;
            count++;

            if (count == tamanhoInicial) {
                std::cout << "Vetor está cheio!!!!!!\n";
                int opcao;
                std::cout << "Deseja aumentar a capacidade do vetor? (0 para não, 1 para sim): ";
                std::cin >> opcao;
                if (opcao == 1) {
                    int novoTamanho = tamanhoInicial * 2;
                    int* novoVetor = new int[novoTamanho];
                    for (int i = 0; i < tamanhoInicial; i++) {
                        novoVetor[i] = vetor[i];
                    }
                    delete[] vetor;
                    vetor = novoVetor;
                    tamanhoInicial = novoTamanho;
                } else {
                    break;
                }
            }
        }

        std::cout << "Vetor preenchido:\n";
        for (int i = 0; i < count; i++) {
            std::cout << vetor[i] << " ";
        }
        std::cout << "\n";

        delete[] vetor;
    }


};

int main() {
    atividade ativ;

    // Questão 1
    std::cout << "Questão 1:\n";
    ativ.aloca_1<int, 10>(); // Exemplo com alocação de vetor

    // Questão 2
    std::cout << "\nQuestão 2:\n";
    ativ.realizarAtividade(); // Exemplo com matriz e verificação de identidade

    // Questão 3
    std::cout << "\nQuestão 3:\n";
    ativ.preencherVetor(); // Exemplo de preenchimento de vetor

    return 0;
}



/*

4. Continuar preenchendo até o tamanho ser atingido novamente.
Quando isso acontecer, volte para o ponto 2 e siga o processo até o usuário informar que não deseja mais
aumentar o tamanho do vetor.
4 - Crie um programa em C++ com uma estrutura chamada Aluno contendo
1. Nome;
2. Um vetor com 3 posições para as notas
após isso
1. Aloque memória dinamicamente tanto para a estrutura quanto para o vetor de notas;
2. Preencha a estrutura Aluno ( nome e notas do aluno);
3. Percorra o vetor e faça a média das notas;
4. Classifique o aluno como aprovado, em reposição ou reprovado considerando os valores adotados
pelo IMD.
5. Em caso de reposição, leia a nota de reposição, crie um novo vetor dinamicamente com 4 posições,
passe as três notas do aluno para o novo vetor, insira a nota de reposição e refaça os pontos 3 e 4.

*/

