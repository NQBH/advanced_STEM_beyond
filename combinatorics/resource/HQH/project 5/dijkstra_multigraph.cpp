#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct MultiEdge {
    int to;
    int weight;
    int edgeId; // To distinguish parallel edges
    
    MultiEdge(int t, int w, int id) : to(t), weight(w), edgeId(id) {}
};

class Multigraph {
private:
    int vertices;
    vector<vector<MultiEdge>> adjList;
    int nextEdgeId;
    
public:
    Multigraph(int v) : vertices(v), nextEdgeId(0) {
        adjList.resize(v);
    }
    
    // Add edge for multigraph (allows parallel edges, no self-loops for simplicity)
    void addEdge(int from, int to, int weight) {
        if (from == to) {
            cout << "Note: Self-loops allowed but skipped in this implementation" << endl;
            return;
        }
        
        adjList[from].push_back(MultiEdge(to, weight, nextEdgeId));
        adjList[to].push_back(MultiEdge(from, weight, nextEdgeId));
        nextEdgeId++;
        
        cout << "Added edge " << from << "-" << to << " with weight " << weight 
             << " (Edge ID: " << nextEdgeId-1 << ")" << endl;
    }
    
    // Dijkstra's algorithm for multigraph
    vector<int> dijkstra(int source, vector<int>& parent, vector<int>& usedEdge) {
        vector<int> dist(vertices, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        parent.assign(vertices, -1);
        usedEdge.assign(vertices, -1);
        dist[source] = 0;
        pq.push({0, source});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (const MultiEdge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    usedEdge[v] = edge.edgeId;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
    
    void printPath(int source, int target, const vector<int>& parent, const vector<int>& usedEdge) {
        if (parent[target] == -1 && source != target) {
            cout << "No path exists from " << source << " to " << target << endl;
            return;
        }
        
        vector<int> path;
        vector<int> edges;
        int current = target;
        
        while (current != source && current != -1) {
            path.push_back(current);
            edges.push_back(usedEdge[current]);
            current = parent[target];
        }
        
        if (current == source) {
            path.push_back(source);
            reverse(path.begin(), path.end());
            reverse(edges.begin(), edges.end());
            
            cout << "Shortest path from " << source << " to " << target << ": ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) {
                    cout << " --(edge " << edges[i] << ")--> ";
                }
            }
            cout << endl;
        }
    }
    
    void printGraph() {
        cout << "Multigraph adjacency list:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (const MultiEdge& e : adjList[i]) {
                cout << "(" << e.to << "," << e.weight << ",E" << e.edgeId << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== Dijkstra Algorithm for Multigraph ===" << endl;
    
    // Create a multigraph with 5 vertices
    Multigraph graph(5);
    
    // Add edges including parallel edges
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 1, 5);  // Parallel edge with different weight
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 3, 4);  // Another parallel edge
    graph.addEdge(3, 4, 2);
    
    cout << endl;
    graph.printGraph();
    cout << endl;
    
    int source = 0;
    vector<int> parent, usedEdge;
    vector<int> distances = graph.dijkstra(source, parent, usedEdge);
    
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
    
    // Print shortest paths with edge information
    for (int i = 1; i < 5; i++) {
        graph.printPath(source, i, parent, usedEdge);
    }
    
    return 0;
}
