//#include <iostream>
//#include "AdjacencyList.h"
//#include "Dijkstra.h"
//
//int main() {
//    int numVertices = 5;
//    AdjacencyList graph(numVertices);
//    graph.addEdge(0, 1, 10);
//    graph.addEdge(0, 3, 5);
//    graph.addEdge(1, 2, 1);
//    graph.addEdge(1, 3, 2);
//    graph.addEdge(2, 4, 4);
//    graph.addEdge(3, 1, 3);
//    graph.addEdge(3, 2, 9);
//    graph.addEdge(3, 4, 2);
//    graph.addEdge(4, 0, 7);
//    graph.addEdge(4, 2, 6);
//
//    std::vector<int> distances = Dijkstra::computePaths(graph, 0, numVertices);
//
//    for (int i = 0; i < numVertices; ++i) {
//        std::cout << "Distance from 0 to " << i << " is " << distances[i] << std::endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include "AdjacencyList.h"
#include "Dijkstra.h"

int main() {
    int numVertices = 5;
    AdjacencyList graph(numVertices);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 4, 4);
    graph.addEdge(3, 1, 3);
    graph.addEdge(3, 2, 9);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 0, 7);
    graph.addEdge(4, 2, 6);

    auto [distances, predecessors] = Dijkstra::computePaths(graph, 0, numVertices);

    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Distance from 0 to " << i << " is " << distances[i] << std::endl;
        int step = i;
        std::cout << "Path: " << i;
        while (predecessors[step] != -1) {
            std::cout << " <- " << predecessors[step];
            step = predecessors[step];
        }
        std::cout << std::endl;
    }

    return 0;
}
