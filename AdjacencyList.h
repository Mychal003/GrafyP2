#pragma once
#include "Graph.h"
#include <list>
#include <vector>
#include <iostream>

class AdjacencyList : public Graph {
private:
    std::vector<std::list<std::pair<int, int>>> adjList;

public:
    explicit AdjacencyList(int vertices) : adjList(vertices) {}

    void addEdge(int src, int dest, int weight) override {
        adjList[src].push_back({dest, weight});
    }

    std::vector<std::pair<int, int>> getNeighbors(int v) const override {
        std::vector<std::pair<int, int>> neighbors;
        for (const auto& pair : adjList[v]) {
            neighbors.push_back(pair);
        }
        return neighbors;
    }

    void printGraph() const override {
        for (int i = 0; i < adjList.size(); i++) {
            std::cout << i << " -> ";
            for (const auto& edge : adjList[i]) {
                std::cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};
