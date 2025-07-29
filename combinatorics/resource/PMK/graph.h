#ifndef GRAPH_H
#define GRAPH_H

#include "utils.h"

const int INF = std::numeric_limits<int>::max();

// Dinh nghia mot canh de de dang phan tich
struct Edge {
    int u, v, w;
};

class Graph {
private:
    int V;
    std::vector<std::list<std::pair<int, int>>> adj;
    std::vector<Edge> edge_list; // Luu tat ca cac canh de phan tich
    bool is_directed;

    // Ham phu tro
    void DFS_util(int u, std::vector<bool>& visited, std::vector<int>& prev, int& step, int s);
    void isConnected_util(int u, std::vector<bool>& visited);
    std::string getPath(int src, int dest, const std::vector<int>& prev);

public:
    Graph(int vertices, bool directed = false);
    int getV() const;
    void addEdge(int u, int v, int w = 1);
    const std::list<std::pair<int, int>>& getAdj(int u) const;
    void print() const;
    
    // Cac ham duyet co ban
    void BFS(int s);
    void DFS(int s);

    // Cac ham phan tich do thi
    bool isConnected();
    void analyzeGraph();

    // Thuat toan Dijkstra chi tiet
    void dijkstra(int src);
};

#endif