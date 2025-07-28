#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;

struct GeneralEdge {
    int to;
    int weight;
    int edgeId;
    bool isSelfLoop;
    
    GeneralEdge(int t, int w, int id, bool selfLoop = false) 
        : to(t), weight(w), edgeId(id), isSelfLoop(selfLoop) {}
};

class GeneralGraph {
private:
    int vertices;
    vector<vector<GeneralEdge>> adjList;
    int nextEdgeId;
    set<pair<int, int>> edgeSet; // To track parallel edges
    
public:
    GeneralGraph(int v) : vertices(v), nextEdgeId(0) {
        adjList.resize(v);
    }
    
    // Add edge for general graph (allows parallel edges and self-loops)
    void addEdge(int from, int to, int weight) {
        bool isSelfLoop = (from == to);
        
        if (isSelfLoop) {
            adjList[from].push_back(GeneralEdge(to, weight, nextEdgeId, true));
            cout << "Added self-loop at vertex " << from << " with weight " << weight 
                 << " (Edge ID: " << nextEdgeId << ")" << endl;
        } else {
            adjList[from].push_back(GeneralEdge(to, weight, nextEdgeId));
            adjList[to].push_back(GeneralEdge(from, weight, nextEdgeId));
            
            // Check if this creates a parallel edge
            pair<int, int> edge = {min(from, to), max(from, to)};
            if (edgeSet.count(edge)) {
                cout << "Added parallel edge " << from << "-" << to << " with weight " << weight 
                     << " (Edge ID: " << nextEdgeId << ")" << endl;
            } else {
                cout << "Added edge " << from << "-" << to << " with weight " << weight 
                     << " (Edge ID: " << nextEdgeId << ")" << endl;
                edgeSet.insert(edge);
            }
        }
        nextEdgeId++;
    }
    
    // Enhanced Dijkstra's algorithm for general graph
    vector<int> dijkstra(int source, vector<int>& parent, vector<int>& usedEdge) {
        vector<int> dist(vertices, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(vertices, false);
        
        parent.assign(vertices, -1);
        usedEdge.assign(vertices, -1);
        dist[source] = 0;
        pq.push({0, source});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (visited[u]) continue;
            visited[u] = true;
            
            for (const GeneralEdge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                
                // Handle self-loops specially
                if (edge.isSelfLoop) {
                    cout << "Processing self-loop at vertex " << u << " (weight: " << weight << ")" << endl;
                    continue; // Self-loops don't contribute to shortest paths to other vertices
                }
                
                if (!visited[v] && dist[u] + weight < dist[v]) {
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
        
        if (source == target) {
            cout << "Path from " << source << " to " << target << ": " << source << " (same vertex)" << endl;
            return;
        }
        
        vector<int> path;
        vector<int> edges;
        int current = target;
        
        while (current != source && current != -1) {
            path.push_back(current);
            edges.push_back(usedEdge[current]);
            current = parent[current];
        }
        
        if (current == source) {
            path.push_back(source);
            reverse(path.begin(), path.end());
            reverse(edges.begin(), edges.end());
            
            cout << "Shortest path from " << source << " to " << target << ": ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) {
                    cout << " --(E" << edges[i] << ")--> ";
                }
            }
            cout << endl;
        }
    }
    
    void printGraph() {
        cout << "General Graph adjacency list:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (const GeneralEdge& e : adjList[i]) {
                cout << "(" << e.to << "," << e.weight << ",E" << e.edgeId;
                if (e.isSelfLoop) cout << ",SELF";
                cout << ") ";
            }
            cout << endl;
        }
    }
    
    void printGraphStatistics() {
        int totalEdges = nextEdgeId;
        int selfLoops = 0;
        int parallelEdges = 0;
        
        set<pair<int, int>> uniqueEdges;
        for (int i = 0; i < vertices; i++) {
            for (const GeneralEdge& e : adjList[i]) {
                if (e.isSelfLoop) {
                    selfLoops++;
                } else if (i <= e.to) { // Count each undirected edge once
                    pair<int, int> edge = {i, e.to};
                    if (uniqueEdges.count(edge)) {
                        parallelEdges++;
                    } else {
                        uniqueEdges.insert(edge);
                    }
                }
            }
        }
        
        cout << "Graph Statistics:" << endl;
        cout << "Total vertices: " << vertices << endl;
        cout << "Total edges: " << totalEdges << endl;
        cout << "Self-loops: " << selfLoops << endl;
        cout << "Parallel edges: " << parallelEdges << endl;
        cout << "Unique edges: " << uniqueEdges.size() << endl;
    }
};

int main() {
    cout << "=== Dijkstra Algorithm for General Graph ===" << endl;
    
    // Create a general graph with 6 vertices
    GeneralGraph graph(6);
    
    // Add various types of edges
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 1, 2);    // Self-loop
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 2, 5);    // Parallel edge with different weight
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 3, 1);    // Another self-loop
    graph.addEdge(3, 4, 3);
    graph.addEdge(2, 4, 8);
    graph.addEdge(2, 4, 6);    // Another parallel edge
    graph.addEdge(4, 5, 2);
    graph.addEdge(0, 5, 10);
    
    cout << endl;
    graph.printGraphStatistics();
    cout << endl;
    graph.printGraph();
    cout << endl;
    
    int source = 0;
    vector<int> parent, usedEdge;
    vector<int> distances = graph.dijkstra(source, parent, usedEdge);
    
    cout << endl << "Shortest distances from vertex " << source << ":" << endl;
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
    for (int i = 0; i < 6; i++) {
        graph.printPath(source, i, parent, usedEdge);
    }
    
    return 0;
}
