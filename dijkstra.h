//#pragma once
//#include "Graph.h"
//#include <vector>
//#include <queue>
//#include <climits>
//
//class Dijkstra {
//public:
//    static std::vector<int> computePaths(const Graph& graph, int source, int numVertices) {
//        std::vector<int> dist(numVertices, INT_MAX);
//        dist[source] = 0;
//
//        auto comp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
//            return a.second > b.second;
//        };
//        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq(comp);
//        pq.emplace(source, 0);
//
//        while (!pq.empty()) {
//            int u = pq.top().first;
//            pq.pop();
//
//            for (const auto& neighbor : graph.getNeighbors(u)) {
//                int v = neighbor.first;
//                int weight = neighbor.second;
//                if (dist[u] + weight < dist[v]) {
//                    dist[v] = dist[u] + weight;
//                    pq.emplace(v, dist[v]);
//                }
//            }
//        }
//
//        return dist;
//    }
//};
#pragma once
#include "Graph.h"
#include <vector>
#include <queue>
#include <climits>
#include <tuple>

class Dijkstra {
public:
    static std::tuple<std::vector<int>, std::vector<int>> computePaths(const Graph& graph, int source, int numVertices) {
        std::vector<int> dist(numVertices, INT_MAX);
        std::vector<int> predecessor(numVertices, -1);
        dist[source] = 0;

        auto comp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq(comp);
        pq.emplace(source, 0);

        while (!pq.empty()) {
            int u = pq.top().first;
            pq.pop();

            for (const auto& neighbor : graph.getNeighbors(u)) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    predecessor[v] = u;
                    pq.emplace(v, dist[v]);
                }
            }
        }

        return std::make_tuple(dist, predecessor);
    }
};
