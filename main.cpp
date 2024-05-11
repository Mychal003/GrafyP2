//#include <iostream>
//#include "AdjacencyList.h"
//#include "Dijkstra.h"
////
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
//#include <iostream>
//#include "AdjacencyList.h"
//#include "Dijkstra.h"
//#include "GraphGenerator.h"
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
//    auto [distances, predecessors] = Dijkstra::computePaths(graph, 0, numVertices);
//
//    for (int i = 0; i < numVertices; ++i) {
//        std::cout << "Distance from 0 to " << i << " is " << distances[i] << std::endl;
//        int step = i;
//        std::cout << "Path: " << i;
//        while (predecessors[step] != -1) {
//            std::cout << " <- " << predecessors[step];
//            step = predecessors[step];
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <chrono>
//#include "AdjacencyList.h"
//#include "Dijkstra.h"
//#include "GraphGenerator.h"
//
//int main() {
//    int numVertices = 100;  // Liczba wierzchołków w grafie
//    double density = 0.25;  // Gęstość grafu
//
//    // Generowanie grafu
//    AdjacencyList graph = GraphGenerator::generate(numVertices, density);
//
//    // Mierzenie czasu wykonania algorytmu Dijkstry
//    auto start = std::chrono::high_resolution_clock::now();
//    auto result = Dijkstra::computePaths(graph, 0, numVertices);
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double, std::milli> elapsed = end - start;
//
//    std::cout << "Czas wykonania Dijkstry: " << elapsed.count() << " ms" << std::endl;
//
//    return 0;
//}











//#include <iostream>
//#include <chrono>
//#include "AdjacencyList.h"
//#include "AdjacencyMatrix.h"
//#include "Dijkstra.h"
//#include "GraphGenerator.h"
//
//int main() {
//    int numVertices = 100;  // Liczba wierzchołków w grafie  (np. 10, 50, 100, 500 i 1000)
//    double density = 1;  // Gęstość grafu 25%, 50%, 75% oraz dla grafu pełnego
//
//    // Generowanie grafu jako lista sąsiedztwa
//    Graph* listGraph = GraphGenerator::generateListGraph(numVertices, density);
//    // Generowanie grafu jako macierz sąsiedztwa
//    Graph* matrixGraph = GraphGenerator::generateMatrixGraph(numVertices, density);
//
//    // Mierzenie czasu wykonania algorytmu Dijkstry dla listy sąsiedztwa
//    auto startList = std::chrono::high_resolution_clock::now();
//    auto resultList = Dijkstra::computePaths(*listGraph, 0, numVertices);  // Użycie dereferencji
//    auto endList = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double, std::milli> elapsedList = endList - startList;
//
//    // Mierzenie czasu wykonania algorytmu Dijkstry dla macierzy sąsiedztwa
//    auto startMatrix = std::chrono::high_resolution_clock::now();
//    auto resultMatrix = Dijkstra::computePaths(*matrixGraph, 0, numVertices);  // Użycie dereferencji
//    auto endMatrix = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double, std::milli> elapsedMatrix = endMatrix - startMatrix;
//
//    std::cout << "Czas wykonania Dijkstry dla listy: " << elapsedList.count() << " ms" << std::endl;
//    std::cout << "Czas wykonania Dijkstry dla macierzy: " << elapsedMatrix.count() << " ms" << std::endl;
//
//    delete listGraph;
//    delete matrixGraph;
//
//    return 0;
//}





//TEST POPRAWNOSCI
#include <iostream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "Dijkstra.h"

int main() {
    int numVertices = 5;

    // Utworzenie i inicjalizacja grafu jako lista sąsiedztwa
    AdjacencyList listGraph(numVertices);
    listGraph.addEdge(0, 1, 10);
    listGraph.addEdge(0, 3, 5);
    listGraph.addEdge(1, 2, 1);
    listGraph.addEdge(1, 3, 2);
    listGraph.addEdge(2, 4, 4);
    listGraph.addEdge(3, 1, 3);
    listGraph.addEdge(3, 2, 9);
    listGraph.addEdge(3, 4, 2);
    listGraph.addEdge(4, 0, 7);
    listGraph.addEdge(4, 2, 6);

    // Utworzenie i inicjalizacja grafu jako macierz sąsiedztwa
    AdjacencyMatrix matrixGraph(numVertices);
    matrixGraph.addEdge(0, 1, 10);
    matrixGraph.addEdge(0, 3, 5);
    matrixGraph.addEdge(1, 2, 1);
    matrixGraph.addEdge(1, 3, 2);
    matrixGraph.addEdge(2, 4, 4);
    matrixGraph.addEdge(3, 1, 3);
    matrixGraph.addEdge(3, 2, 9);
    matrixGraph.addEdge(3, 4, 2);
    matrixGraph.addEdge(4, 0, 7);
    matrixGraph.addEdge(4, 2, 6);

    // Testowanie algorytmu Dijkstry dla listy sąsiedztwa
    auto [distancesList, predecessorsList] = Dijkstra::computePaths(listGraph, 0, numVertices);
    std::cout << "Lista sasiedztwa:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Odleglosc od 0 do " << i << ": " << distancesList[i] << ", Sciezka: ";
        int step = i;
        while (predecessorsList[step] != -1) {
            step = predecessorsList[step];
            std::cout << " <- " << step;
        }
        std::cout << std::endl;
    }

    // Testowanie algorytmu Dijkstry dla macierzy sąsiedztwa
    auto [distancesMatrix, predecessorsMatrix] = Dijkstra::computePaths(matrixGraph, 0, numVertices);
    std::cout << "Macierz sasiedztwa:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Odleglosc od 0 do " << i << ": " << distancesMatrix[i] << ", Sciezka: ";
        int step = i;
        while (predecessorsMatrix[step] != -1) {
            step = predecessorsMatrix[step];
            std::cout << " <- " << step;
        }
        std::cout << std::endl;
    }

    return 0;
}
