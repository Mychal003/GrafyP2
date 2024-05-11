//
// Created by pawli on 11.05.2024.
//

#ifndef PAA_GRAPH1_GRAPHGENERATOR_H
#define PAA_GRAPH1_GRAPHGENERATOR_H

#endif //PAA_GRAPH1_GRAPHGENERATOR_H
#pragma once
#include "AdjacencyList.h"  // Załóżmy, że używamy listy sąsiedztwa
#include <cstdlib>
#include <ctime>
#include <iostream>
//class GraphGenerator {
//public:
//    static AdjacencyList generate(int numVertices, double density) {
//        srand(time(NULL));  // Inicjalizacja generatora liczb losowych
//        AdjacencyList graph(numVertices);
//
//        for (int i = 0; i < numVertices; i++) {
//            for (int j = i + 1; j < numVertices; j++) {
//                double prob = (double)rand() / RAND_MAX;
//                if (prob < density) {
//                    int weight = rand() % 10 + 1;  // Losowa waga od 1 do 10
//                    graph.addEdge(i, j, weight);
//                    graph.addEdge(j, i, weight);  // Dla grafu nieskierowanego
//                }
//            }
//        }
//        return graph;
//    }
//};
//#pragma once
#include "Graph.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class GraphGenerator {
public:
    static Graph* generateListGraph(int numVertices, double density) {
        srand(time(NULL));  // Inicjalizacja generatora liczb losowych
        AdjacencyList* graph = new AdjacencyList(numVertices);

        for (int i = 0; i < numVertices; i++) {
            for (int j = i + 1; j < numVertices; j++) {
                double prob = (double)rand() / RAND_MAX;
                if (prob < density) {
                    int weight = rand() % 10 + 1;  // Losowa waga od 1 do 10
                    graph->addEdge(i, j, weight);
                    graph->addEdge(j, i, weight);  // Dla grafu nieskierowanego
                }
            }
        }
        return graph;
    }

    static Graph* generateMatrixGraph(int numVertices, double density) {
        srand(time(NULL));
        AdjacencyMatrix* graph = new AdjacencyMatrix(numVertices);

        for (int i = 0; i < numVertices; i++) {
            for (int j = i + 1; j < numVertices; j++) {
                double prob = (double)rand() / RAND_MAX;
                if (prob < density) {
                    int weight = rand() % 10 + 1;
                    graph->addEdge(i, j, weight);
                    graph->addEdge(j, i, weight);  // Dla grafu nieskierowanego
                }
            }
        }
        return graph;
    }
};
