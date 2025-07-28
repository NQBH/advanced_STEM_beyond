#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <iomanip>
#include <algorithm>

using namespace std;

class MultigraphBFS {
private:
    int numVertices;
    // Sử dụng multiset để lưu nhiều cạnh giữa hai đỉnh
    vector<multiset<int>> adjList;
    vector<bool> visited;
    vector<int> distance;
    vector<int> parent;
    vector<int> bfsOrder;
    
    // Đếm số cạnh giữa hai đỉnh
    map<pair<int,int>, int> edgeCount;
    
public:
    MultigraphBFS(int n) : numVertices(n) {
        adjList.resize(n);
        resetArrays();
    }
    
    void resetArrays() {
        visited.assign(numVertices, false);
        distance.assign(numVertices, INT_MAX);
        parent.assign(numVertices, -1);
        bfsOrder.clear();
    }
    
    // Thêm cạnh vào multigraph
    void addEdge(int u, int v) {
        adjList[u].insert(v);
        adjList[v].insert(u);
        
        // Đếm số cạnh
        pair<int,int> edge = {min(u,v), max(u,v)};
        edgeCount[edge]++;
        
        cout << "Them canh (" << u << "," << v << ") - So canh giua " 
             << u << " va " << v << ": " << edgeCount[edge] << endl;
    }
    
    // BFS cho multigraph
    void bfs(int start) {
        resetArrays();
        
        queue<int> q;
        visited[start] = true;
        distance[start] = 0;
        q.push(start);
        
        cout << "BFS tren Multigraph tu dinh " << start << ":" << endl;
        cout << "Thu tu duyet: ";
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            bfsOrder.push_back(u);
            cout << u << " ";
            
            // Sử dụng set để tránh duyệt trùng đỉnh kề
            set<int> uniqueNeighbors(adjList[u].begin(), adjList[u].end());
            
            for (int v : uniqueNeighbors) {
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
    
    // BFS cho toàn bộ multigraph (xử lý thành phần liên thông)
    void bfsComplete() {
        resetArrays();
        
        cout << "BFS toan bo multigraph:" << endl;
        int componentCount = 0;
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                componentCount++;
                cout << "Thanh phan lien thong " << componentCount << ": ";
                bfsComponent(i);
                cout << endl;
            }
        }
        
        cout << "Tong so thanh phan lien thong: " << componentCount << endl << endl;
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
            
            set<int> uniqueNeighbors(adjList[u].begin(), adjList[u].end());
            for (int v : uniqueNeighbors) {
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
    
    // In thông tin về các cạnh bội
    void printMultipleEdges() {
        cout << "Cac canh boi trong multigraph:" << endl;
        bool hasMultiple = false;
        
        for (auto& edge : edgeCount) {
            if (edge.second > 1) {
                cout << "Canh (" << edge.first.first << "," 
                     << edge.first.second << "): " << edge.second << " canh" << endl;
                hasMultiple = true;
            }
        }
        
        if (!hasMultiple) {
            cout << "Khong co canh boi nao." << endl;
        }
        cout << endl;
    }
    
    // In thông tin khoảng cách
    void printDistances(int start) {
        cout << "Khoang cach tu dinh " << start << ":" << endl;
        cout << setw(6) << "Dinh" << setw(12) << "Khoang cach" << setw(10) << "Cha" << endl;
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
        cout << "Cay BFS tu dinh " << start << ":" << endl;
        
        bool hasTree = false;
        for (int i = 0; i < numVertices; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " -> " << i << endl;
                hasTree = true;
            }
        }
        
        if (!hasTree) {
            cout << "Khong co cay BFS (chi co dinh goc)." << endl;
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
    
    // Lấy số lượng cạnh giữa hai đỉnh
    int getEdgeMultiplicity(int u, int v) {
        pair<int,int> edge = {min(u,v), max(u,v)};
        return edgeCount.count(edge) ? edgeCount[edge] : 0;
    }
    
    // In đồ thị
    void printGraph() {
        cout << "Bieu dien Multigraph (danh sach ke):" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Thống kê đồ thị
    void printGraphStats() {
        cout << "Thong ke Multigraph:" << endl;
        cout << "So dinh: " << numVertices << endl;
        
        int totalEdges = 0;
        int uniqueEdges = edgeCount.size();
        
        for (auto& edge : edgeCount) {
            totalEdges += edge.second;
        }
        
        cout << "Tong so canh (ke ca canh boi): " << totalEdges << endl;
        cout << "So cap dinh co canh: " << uniqueEdges << endl;
        cout << "So canh boi: " << (totalEdges - uniqueEdges) << endl;
        cout << endl;
    }
};

// Các hàm tiện ích cho Multigraph
class MultigraphUtils {
public:
    // Tạo multigraph mẫu 1
    static MultigraphBFS createSampleMultigraph1() {
        MultigraphBFS graph(5);
        
        // Thêm cạnh bình thường
        graph.addEdge(0, 1);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        
        // Thêm cạnh bội
        graph.addEdge(0, 1); // Cạnh thứ 2 giữa 0 và 1
        graph.addEdge(1, 2); // Cạnh thứ 2 giữa 1 và 2
        graph.addEdge(3, 4);
        
        return graph;
    }
    
    // Tạo multigraph mẫu 2 - không liên thông
    static MultigraphBFS createSampleMultigraph2() {
        MultigraphBFS graph(6);
        
        // Thành phần 1
        graph.addEdge(0, 1);
        graph.addEdge(0, 1); // Cạnh bội
        graph.addEdge(1, 2);
        
        // Thành phần 2
        graph.addEdge(3, 4);
        graph.addEdge(3, 4); // Cạnh bội
        graph.addEdge(3, 4); // Cạnh bội thứ 2
        
        // Đỉnh cô lập
        // Đỉnh 5 không có cạnh nào
        
        return graph;
    }
};

// Hàm demo đầy đủ cho Multigraph
void demonstrateMultigraphBFS() {
    cout << "=== DEMO THUAT TOAN BFS TREN MULTIGRAPH ===" << endl << endl;
    
    // Demo 1: Multigraph liên thông với cạnh bội
    cout << "1. MULTIGRAPH LIEN THONG VOI CANH BOI:" << endl;
    auto graph1 = MultigraphUtils::createSampleMultigraph1();
    
    graph1.printGraph();
    graph1.printGraphStats();
    graph1.printMultipleEdges();
    
    // BFS từ đỉnh 0
    graph1.bfs(0);
    graph1.printDistances(0);
    graph1.printBFSTree(0);
    
    // Tìm đường đi ngắn nhất
    cout << "Duong di ngan nhat tu 0 den 4:" << endl;
    auto path = graph1.getShortestPath(0, 4);
    if (!path.empty()) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << " (Do dai: " << path.size() - 1 << ")" << endl;
    } else {
        cout << "Khong co duong di!" << endl;
    }
    cout << endl;
    
    // Kiểm tra liên thông
    cout << "Do thi co lien thong khong? " 
         << (graph1.isConnected() ? "Co" : "Khong") << endl << endl;
    
    // Demo 2: Multigraph không liên thông
    cout << "2. MULTIGRAPH KHONG LIEN THONG:" << endl;
    auto graph2 = MultigraphUtils::createSampleMultigraph2();
    
    graph2.printGraph();
    graph2.printGraphStats();
    graph2.printMultipleEdges();
    graph2.bfsComplete();
    
    cout << "Do thi co lien thong khong? " 
         << (graph2.isConnected() ? "Co" : "Khong") << endl << endl;
    
    // Demo 3: Kiểm tra tính chất đặc biệt
    cout << "3. KIEM TRA TINH CHAT DAC BIET:" << endl;
    cout << "So luong canh giua dinh 0 va 1 trong graph1: " 
         << graph1.getEdgeMultiplicity(0, 1) << endl;
    cout << "So luong canh giua dinh 3 va 4 trong graph2: " 
         << graph2.getEdgeMultiplicity(3, 4) << endl;
}

int main() {
    demonstrateMultigraphBFS();
    
    // Demo tương tác
    cout << "=== DEMO TUONG TAC - MULTIGRAPH ===" << endl;
    int n, m;
    cout << "Nhap so dinh va so cap canh: ";
    cin >> n >> m;
    
    if (n <= 0 || m < 0) {
        cout << "So dinh va canh phai la so duong!" << endl;
        return 1;
    }
    
    MultigraphBFS userGraph(n);
    
    cout << "Nhap " << m << " cap canh (u v) - co the nhap trung de tao canh boi:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Canh " << i + 1 << ": ";
        cin >> u >> v;
        
        if (u >= 0 && u < n && v >= 0 && v < n) {
            userGraph.addEdge(u, v);
        } else {
            cout << "Canh khong hop le! Dinh phai tu 0 den " << n-1 << endl;
            i--; // Nhập lại
        }
    }
    
    int start;
    cout << "Nhap dinh bat dau BFS: ";
    cin >> start;
    
    if (start < 0 || start >= n) {
        cout << "Dinh bat dau khong hop le!" << endl;
        return 1;
    }
    
    cout << "\n=== KET QUA ===" << endl;
    userGraph.printGraph();
    userGraph.printGraphStats();
    userGraph.printMultipleEdges();
    userGraph.bfs(start);
    userGraph.printDistances(start);
    userGraph.printBFSTree(start);
    
    return 0;
}