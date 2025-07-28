#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

struct MultiEdge {
    int to;
    int weight;
    int id; // ID để phân biệt các cạnh song song
    
    MultiEdge(int t, int w, int i) : to(t), weight(w), id(i) {}
};

class MultiGraphDijkstra {
private:
    int numVertices;
    vector<vector<MultiEdge>> adjList;
    vector<int> dist;
    vector<int> parent;
    vector<int> parentEdgeId;
    vector<bool> visited;
    int edgeIdCounter;
    
public:
    MultiGraphDijkstra(int n) : numVertices(n), edgeIdCounter(0) {
        adjList.resize(n);
        reset();
    }
    
    void reset() {
        dist.assign(numVertices, INT_MAX);
        parent.assign(numVertices, -1);
        parentEdgeId.assign(numVertices, -1);
        visited.assign(numVertices, false);
    }
    
    void addEdge(int u, int v, int weight) {
        // Thêm cạnh từ u đến v
        adjList[u].push_back(MultiEdge(v, weight, edgeIdCounter));
        
        // Nếu không phải vòng lặp, thêm cạnh ngược lại
        if (u != v) {
            adjList[v].push_back(MultiEdge(u, weight, edgeIdCounter));
        }
        
        cout << "Thêm cạnh " << u << " - " << v << " với trọng số " 
             << weight << " (ID: " << edgeIdCounter << ")" << endl;
        
        edgeIdCounter++;
    }
    
    void dijkstraMultiGraph(int source) {
        reset();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                      greater<pair<int, int>>> pq;
        
        dist[source] = 0;
        pq.push({0, source});
        
        cout << "\nDijkstra trên đa đồ thị từ đỉnh " << source << ":" << endl;
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (visited[u]) continue;
            
            visited[u] = true;
            cout << "Xử lý đỉnh " << u << " với khoảng cách " << d << endl;
            
            // Nhóm các cạnh theo đỉnh đích và chọn cạnh nhỏ nhất
            map<int, MultiEdge> bestEdges;
            
            for (const MultiEdge& edge : adjList[u]) {
                int v = edge.to;
                
                if (!visited[v]) {
                    // Chọn cạnh có trọng số nhỏ nhất đến đỉnh v
                    if (bestEdges.find(v) == bestEdges.end() || 
                        edge.weight < bestEdges[v].weight) {
                        bestEdges[v] = edge;
                    }
                }
            }
            
            // Cập nhật khoảng cách với các cạnh tốt nhất
            for (const auto& pair : bestEdges) {
                int v = pair.first;
                const MultiEdge& edge = pair.second;
                
                if (dist[u] + edge.weight < dist[v]) {
                    dist[v] = dist[u] + edge.weight;
                    parent[v] = u;
                    parentEdgeId[v] = edge.id;
                    pq.push({dist[v], v});
                    
                    cout << "  Cập nhật dist[" << v << "] = " << dist[v]
                         << " (qua cạnh ID " << edge.id << ")" << endl;
                }
            }
        }
    }
    
    // Phiên bản xử lý tất cả cạnh song song
    void dijkstraAllEdges(int source) {
        reset();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                      greater<pair<int, int>>> pq;
        
        dist[source] = 0;
        pq.push({0, source});
        
        cout << "\nDijkstra xử lý tất cả cạnh song song từ đỉnh " 
             << source << ":" << endl;
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (visited[u]) continue;
            
            visited[u] = true;
            cout << "Xử lý đỉnh " << u << " với khoảng cách " << d << endl;
            
            // Xử lý tất cả các cạnh (bao gồm cạnh song song)
            for (const MultiEdge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    parentEdgeId[v] = edge.id;
                    pq.push({dist[v], v});
                    
                    cout << "  Cập nhật dist[" << v << "] = " << dist[v]
                         << " (qua cạnh ID " << edge.id 
                         << " với trọng số " << weight << ")" << endl;
                }
            }
        }
    }
    
    void printMultiGraph() {
        cout << "Đa đồ thị có trọng số:" << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << "Đỉnh " << i << ": ";
            
            // Nhóm cạnh theo đỉnh đích
            map<int, vector<MultiEdge>> edgeGroups;
            for (const MultiEdge& edge : adjList[i]) {
                edgeGroups[edge.to].push_back(edge);
            }
            
            for (const auto& group : edgeGroups) {
                int dest = group.first;
                const vector<MultiEdge>& edges = group.second;
                
                cout << dest << "[";
                for (int j = 0; j < edges.size(); j++) {
                    cout << edges[j].weight;
                    if (j < edges.size() - 1) cout << ",";
                }
                cout << "] ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void printResults(int source) {
        cout << "\nKết quả Dijkstra từ đỉnh " << source << ":" << endl;
        cout << setw(6) << "Đỉnh" << setw(12) << "Khoảng cách" 
             << setw(10) << "Cạnh ID" << setw(15) << "Đường đi" << endl;
        cout << string(45, '-') << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << setw(6) << i;
            
            if (dist[i] == INT_MAX) {
                cout << setw(12) << "∞" << setw(10) << "-" 
                     << setw(15) << "Không có" << endl;
            } else {
                cout << setw(12) << dist[i] 
                     << setw(10) << parentEdgeId[i] << setw(15);
                printPath(source, i);
                cout << endl;
            }
        }
        cout << endl;
    }
    
    void printPath(int source, int dest) {
        if (dest == source) {
            cout << dest;
            return;
        }
        
        if (parent[dest] == -1) {
            cout << "Không có đường";
            return;
        }
        
        vector<int> path;
        vector<int> edgeIds;
        int current = dest;
        
        while (current != -1 && current != source) {
            path.push_back(current);
            if (parentEdgeId[current] != -1) {
                edgeIds.push_back(parentEdgeId[current]);
            }
            current = parent[current];
        }
        
        if (current == source) {
            path.push_back(source);
        }
        
        reverse(path.begin(), path.end());
        reverse(edgeIds.begin(), edgeIds.end());
        
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << "→";
            }
        }
    }
    
    // Tìm tất cả các đường đi với chi phí tối ưu (xử lý cạnh song song)
    void findAllOptimalPaths(int source, int dest) {
        dijkstraAllEdges(source);
        
        if (dist[dest] == INT_MAX) {
            cout << "Không có đường đi từ " << source << " đến " << dest << endl;
            return;
        }
        
        cout << "Tất cả đường đi tối ưu từ " << source << " đến " << dest 
             << " (chi phí " << dist[dest] << "):" << endl;
        
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        findAllPathsHelper(source, dest, dist[dest], 0, currentPath, allPaths);
        
        for (int i = 0; i < allPaths.size(); i++) {
            cout << "Đường " << i + 1 << ": ";
            for (int j = 0; j < allPaths[i].size(); j++) {
                cout << allPaths[i][j];
                if (j < allPaths[i].size() - 1) cout << "→";
            }
            cout << endl;
        }
    }
    
private:
    void findAllPathsHelper(int current, int dest, int targetCost, 
                           int currentCost, vector<int>& path, 
                           vector<vector<int>>& allPaths) {
        path.push_back(current);
        
        if (current == dest && currentCost == targetCost) {
            allPaths.push_back(path);
            path.pop_back();
            return;
        }
        
        if (currentCost >= targetCost) {
            path.pop_back();
            return;
        }
        
        for (const MultiEdge& edge : adjList[current]) {
            int next = edge.to;
            int newCost = currentCost + edge.weight;
            
            if (newCost <= targetCost) {
                findAllPathsHelper(next, dest, targetCost, newCost, path, allPaths);
            }
        }
        
        path.pop_back();
    }
};

void demonstrateMultiGraphDijkstra() {
    cout << "=== DEMO DIJKSTRA CHO ĐA ĐỒ THỊ ===" << endl << endl;
    
    MultiGraphDijkstra graph(4);
    
    // Tạo đa đồ thị với cạnh song song
    graph.addEdge(0, 1, 5);  // Cạnh song song 1
    graph.addEdge(0, 1, 3);  // Cạnh song song 2 (tốt hơn)
    graph.addEdge(0, 2, 4);
    graph.addEdge(2, 3, 2);
    graph.addEdge(1, 3, 6);  // Cạnh song song 1
    graph.addEdge(1, 3, 1);  // Cạnh song song 2 (tốt hơn)
    graph.addEdge(2, 2, 2);  // Vòng lặp
    
    cout << endl;
    graph.printMultiGraph();
    
    // So sánh hai phương pháp
    graph.dijkstraMultiGraph(0);
    graph.printResults(0);
    
    graph.dijkstraAllEdges(0);
    graph.printResults(0);
    
    // Tìm tất cả đường đi tối ưu
    graph.findAllOptimalPaths(0, 3);
}

int main() {
    demonstrateMultiGraphDijkstra();
    return 0;
}