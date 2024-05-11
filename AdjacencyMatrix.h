#pragma once
#include "Graph.h"
#include <vector>
#include <iostream>
class AdjacencyMatrix : public Graph {
private:
    std::vector<std::vector<int>> matrix;

public:
    explicit AdjacencyMatrix(int vertices)
            : matrix(vertices, std::vector<int>(vertices, 0)) {}

    void addEdge(int src, int dest, int weight) override {
        matrix[src][dest] = weight;
    }

    std::vector<std::pair<int, int>> getNeighbors(int v) const override {
        std::vector<std::pair<int, int>> neighbors;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[v][i] != 0) {
                neighbors.emplace_back(i, matrix[v][i]);
            }
        }
        return neighbors;
    }

    void printGraph() const override {
        for (int i = 0; i < matrix.size(); i++) {
            std::cout << i << " -> ";
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] != 0) {
                    std::cout << "(" << j << ", " << matrix[i][j] << ") ";
                }
            }
            std::cout << std::endl;
        }
    }
};
