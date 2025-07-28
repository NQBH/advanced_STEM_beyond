#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Edge {
    int to;
    int weight;
    
    Edge(int t, int w) : to(t), weight(w) {}
};

class SimpleDijkstra {
private:
    int numVertices;
    vector<vector<Edge>> adjList;
    vector<int> dist;
    vector<int> parent;
    vector<bool> visited;
    
public:
    SimpleDijkstra(int n) : numVertices(n) {
        adjList.resize(n);
        reset();
    }
    
    void reset() {
        dist.assign(numVertices, INT_MAX);
        parent.assign(numVertices, -1);
        visited.assign(numVertices, false);
    }
    
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(Edge(v, weight));
        adjList[v].push_back(Edge(u, weight)); // Đồ thị vô hướng
        cout << "Thêm cạnh " << u << " - " << v << " với trọng số " << weight << endl;
    }
    
    // Dijkstra sử dụng priority queue
    void dijkstraWithPQ(int source) {
        reset();
        
        // Priority queue (min-heap): pair<distance, vertex>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[source] = 0;
        pq.push({0, source});
        
        cout << "\nDijkstra với Priority Queue từ đỉnh " << source << ":" << endl;
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (visited[u]) continue;
            
            visited[u] = true;
            cout << "Xử lý đỉnh " << u << " với khoảng cách " << d << endl;
            
            // Duyệt các đỉnh kề
            for (const Edge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                    
                    cout << "  Cập nhật dist[" << v << "] = " << dist[v] 
                         << " (qua đỉnh " << u << ")" << endl;
                }
            }
        }
    }
    
    // Dijkstra cơ bản với mảng
    void dijkstraBasic(int source) {
        reset();
        
        dist[source] = 0;
        
        cout << "\nDijkstra cơ bản từ đỉnh " << source << ":" << endl;
        
        for (int count = 0; count < numVertices - 1; count++) {
            // Tìm đỉnh chưa xử lý có khoảng cách nhỏ nhất
            int u = findMinDistance();
            if (u == -1) break;
            
            visited[u] = true;
            cout << "Bước " << count + 1 << ": Chọn đỉnh " << u 
                 << " với khoảng cách " << dist[u] << endl;
            
            // Cập nhật khoảng cách đến các đỉnh kề
            for (const Edge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                
                if (!visited[v] && dist[u] != INT_MAX && 
                    dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    
                    cout << "  Cập nhật dist[" << v << "] = " << dist[v] << endl;
                }
            }
        }
    }
    
private:
    int findMinDistance() {
        int minDist = INT_MAX;
        int minVertex = -1;
        
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minVertex = v;
            }
        }
        
        return minVertex;
    }
    
public:
    void printResults(int source) {
        cout << "\nKết quả Dijkstra từ đỉnh " << source << ":" << endl;
        cout << setw(6) << "Đỉnh" << setw(12) << "Khoảng cách" 
             << setw(15) << "Đường đi" << endl;
        cout << string(35, '-') << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << setw(6) << i;
            
            if (dist[i] == INT_MAX) {
                cout << setw(12) << "∞" << setw(15) << "Không có" << endl;
            } else {
                cout << setw(12) << dist[i] << setw(15);
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
        int current = dest;
        
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << "→";
        }
    }
    
    void printGraph() {
        cout << "Đồ thị đơn có trọng số:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Đỉnh " << i << ": ";
            for (const Edge& edge : adjList[i]) {
                cout << "(" << edge.to << "," << edge.weight << ") ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Tìm đường đi ngắn nhất giữa hai đỉnh cụ thể
    pair<int, vector<int>> shortestPath(int source, int dest) {
        dijkstraWithPQ(source);
        
        if (dist[dest] == INT_MAX) {
            return {-1, {}};
        }
        
        vector<int> path;
        int current = dest;
        
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        return {dist[dest], path};
    }
    
    // Kiểm tra tính chất của đồ thị
    void analyzeGraph() {
        cout << "Phân tích đồ thị:" << endl;
        
        // Kiểm tra tính liên thông
        bool isConnected = true;
        dijkstraWithPQ(0);
        
        for (int i = 0; i < numVertices; i++) {
            if (dist[i] == INT_MAX) {
                isConnected = false;
                break;
            }
        }
        
        cout << "Đồ thị liên thông: " << (isConnected ? "Có" : "Không") << endl;
        
        // Tìm cặp đỉnh có khoảng cách lớn nhất
        int maxDist = 0;
        pair<int, int> farthestPair = {-1, -1};
        
        for (int i = 0; i < numVertices; i++) {
            dijkstraWithPQ(i);
            for (int j = 0; j < numVertices; j++) {
                if (dist[j] != INT_MAX && dist[j] > maxDist) {
                    maxDist = dist[j];
                    farthestPair = {i, j};
                }
            }
        }
        
        if (farthestPair.first != -1) {
            cout << "Cặp đỉnh xa nhất: " << farthestPair.first 
                 << " và " << farthestPair.second 
                 << " (khoảng cách: " << maxDist << ")" << endl;
        }
        
        cout << endl;
    }
};

// Demo cho đồ thị đơn
int main() {
    cout << "=== DIJKSTRA CHO ĐỒ THỊ ĐƠN ===" << endl << endl;
    
    SimpleDijkstra graph(5);
    
    // Tạo đồ thị mẫu
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 4, 2);
    
    cout << endl;
    graph.printGraph();
    
    // Dijkstra với priority queue
    graph.dijkstraWithPQ(0);
    graph.printResults(0);
    
    // Dijkstra cơ bản
    graph.dijkstraBasic(0);
    graph.printResults(0);
    
    // Tìm đường đi cụ thể
    auto path = graph.shortestPath(0, 4);
    cout << "Đường đi ngắn nhất từ 0 đến 4:" << endl;
    cout << "Độ dài: " << path.first << endl;
    cout << "Đường đi: ";
    for (int i = 0; i < path.second.size(); i++) {
        cout << path.second[i];
        if (i < path.second.size() - 1) cout << "→";
    }
    cout << endl << endl;
    
    // Phân tích đồ thị
    graph.analyzeGraph();
    
    return 0;
}