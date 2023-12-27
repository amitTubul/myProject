#pragma once
#include <vector>
namespace amit{
    class Graph{
    private:
        unsigned long _rank;
        std::vector<std::vector<int>> _matrix;

    public:
        Graph(unsigned long _rank);// constructor for random symmetric matrix o(_rank^2)
        void printMatrix();// print the matrix
        void printGraph();
    };
}


