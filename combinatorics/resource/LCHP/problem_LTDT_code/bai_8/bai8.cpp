#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <iomanip>
#include <algorithm>

using namespace std;

class SimpleBFS {
private:
    int numVertices;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> distance;
    vector<int> parent;
    vector<int> bfsOrder;
    
public:
    // Constructor
    SimpleBFS(int n) : numVertices(n) {
        adjList.resize(n);
        resetArrays();
    }
    
    // Reset các mảng trạng thái
    void resetArrays() {
        visited.assign(numVertices, false);
        distance.assign(numVertices, INT_MAX);
        parent.assign(numVertices, -1);
        bfsOrder.clear();
    }
    
    // Thêm cạnh vào đồ thị
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Đồ thị vô hướng
    }
    
    // Thuật toán BFS chính
    void bfs(int start) {
        resetArrays();
        
        queue<int> q;
        visited[start] = true;
        distance[start] = 0;
        q.push(start);
        
        cout << "Bắt đầu BFS từ đỉnh " << start << ":" << endl;
        cout << "Thứ tự duyệt: ";
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            // Xử lý đỉnh u
            bfsOrder.push_back(u);
            cout << u << " ";
            
            // Duyệt tất cả đỉnh kề với u
            for (int v : adjList[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        cout << endl << endl;
    }
    
    // BFS cho toàn bộ đồ thị (xử lý thành phần liên thông)
    void bfsComplete() {
        resetArrays();
        
        cout << "BFS toàn bộ đồ thị:" << endl;
        int componentCount = 0;
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                componentCount++;
                cout << "Thành phần liên thông " << componentCount << ": ";
                bfsComponent(i);
                cout << endl;
            }
        }
        
        cout << "Tổng số thành phần liên thông: " << componentCount << endl << endl;
    }
    
    // BFS cho một thành phần liên thông
    void bfsComponent(int start) {
        queue<int> q;
        visited[start] = true;
        distance[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            
            for (int v : adjList[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
    }
    
    // Tìm đường đi ngắn nhất từ start đến target
    vector<int> getShortestPath(int start, int target) {
        bfs(start);
        
        vector<int> path;
        if (distance[target] == INT_MAX) {
            return path; // Không có đường đi
        }
        
        // Tái tạo đường đi từ mảng parent
        int current = target;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        return path;
    }
    
    // In thông tin khoảng cách
    void printDistances(int start) {
        cout << "Khoảng cách từ đỉnh " << start << ":" << endl;
        cout << setw(6) << "Đỉnh" << setw(12) << "Khoảng cách" << setw(10) << "Cha" << endl;
        cout << string(28, '-') << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << setw(6) << i;
            if (distance[i] == INT_MAX) {
                cout << setw(12) << "INF";
            } else {
                cout << setw(12) << distance[i];
            }
            cout << setw(10) << parent[i] << endl;
        }
        cout << endl;
    }
    
    // In cây BFS
    void printBFSTree(int start) {
        cout << "Cây BFS từ đỉnh " << start << ":" << endl;
        
        for (int i = 0; i < numVertices; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " -> " << i << endl;
            }
        }
        cout << endl;
    }
    
    // Kiểm tra liên thông
    bool isConnected() {
        bfs(0);
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
    
    // Tìm đỉnh xa nhất từ start
    pair<int, int> findFarthestVertex(int start) {
        bfs(start);
        
        int maxDist = -1;
        int farthestVertex = -1;
        
        for (int i = 0; i < numVertices; i++) {
            if (distance[i] != INT_MAX && distance[i] > maxDist) {
                maxDist = distance[i];
                farthestVertex = i;
            }
        }
        
        return {farthestVertex, maxDist};
    }
    
    // In đồ thị
    void printGraph() {
        cout << "Biểu diễn đồ thị (danh sách kề):" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

// Hàm tạo đồ thị mẫu
SimpleBFS createSampleGraph() {
    SimpleBFS graph(6);
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    
    return graph;
}

// Demo BFS cho Simple Graph
void demonstrateSimpleBFS() {
    cout << "=== BÀI 8: BFS CHO SIMPLE GRAPH ===" << endl << endl;
    
    // Tạo đồ thị mẫu
    auto graph = createSampleGraph();
    graph.printGraph();
    
    // BFS từ đỉnh 0
    graph.bfs(0);
    graph.printDistances(0);
    graph.printBFSTree(0);
    
    // Tìm đường đi ngắn nhất
    cout << "Đường đi ngắn nhất từ 0 đến 5:" << endl;
    auto path = graph.getShortestPath(0, 5);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << " (Độ dài: " << path.size() - 1 << ")" << endl << endl;
    
    // Kiểm tra liên thông
    cout << "Đồ thị có liên thông không? " 
         << (graph.isConnected() ? "Có" : "Không") << endl << endl;
    
    // Tìm đỉnh xa nhất
    auto [farthest, maxDist] = graph.findFarthestVertex(0);
    cout << "Đỉnh xa nhất từ 0: " << farthest 
         << " (khoảng cách: " << maxDist << ")" << endl;
}

int main() {
    demonstrateSimpleBFS();
    
    // Demo tương tác
    cout << "\n=== DEMO TƯƠNG TÁC ===" << endl;
    int n, m;
    cout << "Nhập số đỉnh và số cạnh: ";
    cin >> n >> m;
    
    SimpleBFS userGraph(n);
    
    cout << "Nhập " << m << " cạnh (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        userGraph.addEdge(u, v);
    }
    
    int start;
    cout << "Nhập đỉnh bắt đầu BFS: ";
    cin >> start;
    
    userGraph.printGraph();
    userGraph.bfs(start);
    userGraph.printDistances(start);
    userGraph.printBFSTree(start);
    
    return 0;
}