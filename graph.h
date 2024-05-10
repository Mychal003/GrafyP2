#pragma once
#include <vector>
#include <utility>

class Graph {
public:
    virtual ~Graph() {}
    virtual void addEdge(int src, int dest, int weight) = 0;
    virtual std::vector<std::pair<int, int>> getNeighbors(int v) const = 0;
    virtual void printGraph() const = 0;
};
