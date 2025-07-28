#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int to;
    int weight;
    int id;  // For multigraph identification

    Edge(int t, int w, int i = 0) : to(t), weight(w), id(i) {}
};

// Comparison for priority queue (min-heap)
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;  // Min-heap based on distance
    }
};

class Graph {
protected:
    int vertices;
    vector<vector<Edge>> adj;
    string graphType;

public:
    Graph(int v, string type) : vertices(v), graphType(type) {
        adj.resize(v);
    }

    virtual void addEdge(int from, int to, int weight) = 0;
    virtual void printGraph() = 0;

    // Dijkstra's algorithm implementation
    pair<vector<int>, vector<int>> dijkstra(int source) {
        vector<int> dist(vertices, INT_MAX);
        vector<int> parent(vertices, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        dist[source] = 0;
        pq.push({ source, 0 });

        cout << "\n=== Dijkstra's Algorithm Execution for " << graphType << " ===" << endl;
        cout << "Source vertex: " << source << endl;

        while (!pq.empty()) {
            int u = pq.top().first;
            int currentDist = pq.top().second;
            pq.pop();

            // Skip if we've already found a better path
            if (currentDist > dist[u]) continue;

            cout << "\nProcessing vertex " << u << " (distance: " << dist[u] << ")" << endl;

            // Relax all adjacent vertices
            for (const Edge& edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    cout << "  Relaxing edge " << u << " -> " << v
                        << " (weight: " << weight << ", new distance: "
                        << dist[u] + weight << ")" << endl;

                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({ v, dist[v] });
                }
            }
        }

        return { dist, parent };
    }

    // Print shortest paths
    void printShortestPaths(int source, const vector<int>& dist, const vector<int>& parent) {
        cout << "\n=== Shortest Paths from vertex " << source << " ===" << endl;
        cout << "Vertex\tDistance\tPath" << endl;
        cout << "------\t--------\t----" << endl;

        for (int i = 0; i < vertices; i++) {
            cout << i << "\t";
            if (dist[i] == INT_MAX) {
                cout << "INF\t\tNo path" << endl;
            }
            else {
                cout << dist[i] << "\t\t";
                printPath(parent, i);
                cout << endl;
            }
        }
    }

private:
    void printPath(const vector<int>& parent, int vertex) {
        if (parent[vertex] == -1) {
            cout << vertex;
            return;
        }
        printPath(parent, parent[vertex]);
        cout << " -> " << vertex;
    }
};

// Simple Graph: No loops, no multiple edges
class SimpleGraph : public Graph {
private:
    set<pair<int, int>> edgeSet;  // To prevent multiple edges

public:
    SimpleGraph(int v) : Graph(v, "Simple Graph") {}

    void addEdge(int from, int to, int weight) override {
        // Check for self-loops
        if (from == to) {
            cout << "Error: Cannot add self-loop (" << from << "," << to
                << ") in simple graph!" << endl;
            return;
        }

        // Check for multiple edges
        if (edgeSet.count({ from, to }) || edgeSet.count({ to, from })) {
            cout << "Error: Edge (" << from << "," << to
                << ") already exists in simple graph!" << endl;
            return;
        }

        adj[from].push_back(Edge(to, weight));
        adj[to].push_back(Edge(from, weight));  // Undirected graph
        edgeSet.insert({ from, to });
    }

    void printGraph() override {
        cout << "\n=== Simple Graph Structure ===" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (const Edge& edge : adj[i]) {
                cout << "(" << edge.to << "," << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

// Multigraph: No loops, but multiple edges allowed
class Multigraph : public Graph {
private:
    int edgeCounter;

public:
    Multigraph(int v) : Graph(v, "Multigraph"), edgeCounter(0) {}

    void addEdge(int from, int to, int weight) override {
        // Check for self-loops
        if (from == to) {
            cout << "Error: Cannot add self-loop (" << from << "," << to
                << ") in multigraph!" << endl;
            return;
        }

        // Multiple edges are allowed, so we assign unique IDs
        adj[from].push_back(Edge(to, weight, edgeCounter));
        adj[to].push_back(Edge(from, weight, edgeCounter));  // Undirected graph
        edgeCounter++;

        cout << "Added edge " << from << " <-> " << to
            << " with weight " << weight << " (ID: " << edgeCounter - 1 << ")" << endl;
    }

    void printGraph() override {
        cout << "\n=== Multigraph Structure ===" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (const Edge& edge : adj[i]) {
                cout << "(" << edge.to << "," << edge.weight << ",ID:" << edge.id << ") ";
            }
            cout << endl;
        }
    }
};

// General Graph: Both loops and multiple edges allowed
class GeneralGraph : public Graph {
private:
    int edgeCounter;

public:
    GeneralGraph(int v) : Graph(v, "General Graph"), edgeCounter(0) {}

    void addEdge(int from, int to, int weight) override {
        // Everything is allowed in general graph
        adj[from].push_back(Edge(to, weight, edgeCounter));

        // For loops, don't add the reverse edge
        if (from != to) {
            adj[to].push_back(Edge(from, weight, edgeCounter));
        }

        edgeCounter++;

        if (from == to) {
            cout << "Added self-loop at vertex " << from
                << " with weight " << weight << " (ID: " << edgeCounter - 1 << ")" << endl;
        }
        else {
            cout << "Added edge " << from << " <-> " << to
                << " with weight " << weight << " (ID: " << edgeCounter - 1 << ")" << endl;
        }
    }

    void printGraph() override {
        cout << "\n=== General Graph Structure ===" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (const Edge& edge : adj[i]) {
                cout << "(" << edge.to << "," << edge.weight << ",ID:" << edge.id << ") ";
            }
            cout << endl;
        }
    }
};

// Demonstration function
void demonstrateGraph(Graph* graph, const string& title) {
    cout << "\n" << string(60, '=') << endl;
    cout << title << endl;
    cout << string(60, '=') << endl;

    graph->printGraph();

    // Run Dijkstra from vertex 0
    auto result = graph->dijkstra(0);
    graph->printShortestPaths(0, result.first, result.second);
}

int main() {
    cout << "DIJKSTRA'S ALGORITHM IMPLEMENTATION" << endl;
    cout << "Problems 14, 15, 16: Simple Graph, Multigraph, General Graph" << endl;
    cout << string(70, '=') << endl;

    // Problem 14: Simple Graph
    cout << "\n>>> PROBLEM 14: SIMPLE GRAPH <<<" << endl;
    SimpleGraph simpleGraph(5);

    // Add edges to simple graph
    simpleGraph.addEdge(0, 1, 10);
    simpleGraph.addEdge(0, 4, 5);
    simpleGraph.addEdge(1, 2, 1);
    simpleGraph.addEdge(1, 4, 2);
    simpleGraph.addEdge(2, 3, 4);
    simpleGraph.addEdge(3, 2, 6);  // This will be rejected (duplicate)
    simpleGraph.addEdge(3, 4, 2);
    simpleGraph.addEdge(4, 1, 3);  // This will be rejected (duplicate)
    simpleGraph.addEdge(4, 2, 9);
    simpleGraph.addEdge(4, 3, 2);  // This will be rejected (duplicate)

    demonstrateGraph(&simpleGraph, "SIMPLE GRAPH ANALYSIS");

    // Problem 15: Multigraph
    cout << "\n\n>>> PROBLEM 15: MULTIGRAPH <<<" << endl;
    Multigraph multigraph(4);

    // Add edges including multiple edges between same vertices
    multigraph.addEdge(0, 1, 5);
    multigraph.addEdge(0, 1, 3);   // Multiple edge - allowed
    multigraph.addEdge(0, 2, 4);
    multigraph.addEdge(1, 2, 2);
    multigraph.addEdge(1, 2, 6);   // Multiple edge - allowed
    multigraph.addEdge(1, 3, 1);
    multigraph.addEdge(2, 3, 3);
    multigraph.addEdge(2, 3, 7);   // Multiple edge - allowed
    multigraph.addEdge(1, 1, 2);   // Self-loop - not allowed in multigraph

    demonstrateGraph(&multigraph, "MULTIGRAPH ANALYSIS");

    // Problem 16: General Graph
    cout << "\n\n>>> PROBLEM 16: GENERAL GRAPH <<<" << endl;
    GeneralGraph generalGraph(4);

    // Add edges including self-loops and multiple edges
    generalGraph.addEdge(0, 1, 7);
    generalGraph.addEdge(0, 1, 4);   // Multiple edge - allowed
    generalGraph.addEdge(0, 2, 3);
    generalGraph.addEdge(0, 0, 2);   // Self-loop - allowed
    generalGraph.addEdge(1, 2, 5);
    generalGraph.addEdge(1, 2, 8);   // Multiple edge - allowed
    generalGraph.addEdge(1, 3, 6);
    generalGraph.addEdge(2, 2, 1);   // Self-loop - allowed
    generalGraph.addEdge(2, 3, 2);
    generalGraph.addEdge(3, 3, 4);   // Self-loop - allowed

    demonstrateGraph(&generalGraph, "GENERAL GRAPH ANALYSIS");

    // Summary
    cout << "\n" << string(70, '=') << endl;
    cout << "SUMMARY OF DIJKSTRA'S ALGORITHM ON DIFFERENT GRAPH TYPES" << endl;
    cout << string(70, '=') << endl;
    cout << "1. SIMPLE GRAPH: No loops, no multiple edges" << endl;
    cout << "   - Dijkstra works optimally with clean edge relationships" << endl;
    cout << "   - Each pair of vertices has at most one edge" << endl;

    cout << "\n2. MULTIGRAPH: No loops, but multiple edges allowed" << endl;
    cout << "   - Dijkstra considers all parallel edges" << endl;
    cout << "   - Chooses the minimum weight edge automatically" << endl;

    cout << "\n3. GENERAL GRAPH: Both loops and multiple edges allowed" << endl;
    cout << "   - Dijkstra handles self-loops by processing them normally" << endl;
    cout << "   - Multiple edges are evaluated, minimum weight is chosen" << endl;
    cout << "   - Most flexible but requires careful implementation" << endl;

    cout << "\nKey Insight: Dijkstra's algorithm adapts naturally to all graph types" << endl;
    cout << "by using a priority queue and relaxation technique!" << endl;

    return 0;
}