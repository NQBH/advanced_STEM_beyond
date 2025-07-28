#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int to;
    int weight;
    
    Edge(int t, int w) : to(t), weight(w) {}
};

class SimpleGraph {
private:
    int vertices;
    vector<vector<Edge>> adjList;
    
public:
    SimpleGraph(int v) : vertices(v) {
        adjList.resize(v);
    }
    
    // Add edge for simple graph (no parallel edges, no self-loops)
    void addEdge(int from, int to, int weight) {
        if (from == to) {
            cout << "Warning: Self-loops not allowed in simple graph" << endl;
            return;
        }
        
        // Check if edge already exists
        for (const Edge& e : adjList[from]) {
            if (e.to == to) {
                cout << "Warning: Parallel edges not allowed in simple graph" << endl;
                return;
            }
        }
        
        adjList[from].push_back(Edge(to, weight));
        adjList[to].push_back(Edge(from, weight)); // undirected
    }
    
    // Dijkstra's algorithm implementation
    vector<int> dijkstra(int source, vector<int>& parent) {
        vector<int> dist(vertices, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        parent.assign(vertices, -1);
        dist[source] = 0;
        pq.push({0, source});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (const Edge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
    
    // Print shortest path from source to target
    void printPath(int source, int target, const vector<int>& parent) {
        if (parent[target] == -1 && source != target) {
            cout << "No path exists from " << source << " to " << target << endl;
            return;
        }
        
        vector<int> path;
        int current = target;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        
        cout << "Shortest path from " << source << " to " << target << ": ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
    
    void printGraph() {
        cout << "Simple Graph adjacency list:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (const Edge& e : adjList[i]) {
                cout << "(" << e.to << "," << e.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== Dijkstra Algorithm for Simple Graph ===" << endl;
    
    // Create a simple graph with 6 vertices
    SimpleGraph graph(6);
    
    // Add edges (from, to, weight)
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 5, 6);
    
    graph.printGraph();
    cout << endl;
    
    int source = 0;
    vector<int> parent;
    vector<int> distances = graph.dijkstra(source, parent);
    
    cout << "Shortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < distances.size(); i++) {
        cout << "To vertex " << i << ": ";
        if (distances[i] == INT_MAX) {
            cout << "INFINITY" << endl;
        } else {
            cout << distances[i] << endl;
        }
    }
    cout << endl;
    
    // Print shortest paths
    for (int i = 1; i < 6; i++) {
        graph.printPath(source, i, parent);
    }
    
    return 0;
}
