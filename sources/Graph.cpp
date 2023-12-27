#include "Graph.hpp"
#include <random>
#include <iostream>
namespace amit {
    Graph::Graph(unsigned long rank) : _rank(rank), _matrix(rank, std::vector<int>(rank, 0)) {
        std::random_device rd;
        std::mt19937 mt(rd());
        for (unsigned long i = 0; i < rank; ++i) {
            for (unsigned long j = 0; j < rank && i!=j; ++j){
                std::uniform_int_distribution<int> dist(0, 1);
                double randomNumber = dist(mt);
                if (randomNumber==0) {
                    if (_matrix[i][j] == 1) continue;
                }
                _matrix[i][j] = randomNumber;
                _matrix[j][i] = randomNumber;
            }
        }
    }

    void Graph::printMatrix() {
        std::cout << "Matrix:\n";
        for (const auto &row: _matrix) {
            for (int value: row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

    void Graph::printGraph() {

    }
}
