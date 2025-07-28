#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <iomanip>
#include <algorithm>

using namespace std;

class GeneralGraphBFS {
private:
    int numVertices;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> distance;
    vector<int> parent;
    
    map<pair<int,int>, int> edgeCount;
    set<int> selfLoops; // Lưu các đỉnh có khuyên
    
public:
    GeneralGraphBFS(int n) : numVertices(n) {
        adjList.resize(n);
        resetArrays();
    }
    
    void resetArrays() {
        visited.assign(numVertices, false);
        distance.assign(numVertices, INT_MAX);
        parent.assign(numVertices, -1);
    }
    
    // Thêm cạnh vào general graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        
        if (u != v) { // Không phải khuyên
            adjList[v].push_back(u);
        } else { // Là khuyên
            selfLoops.insert(u);
            cout << "Them khuyen tai dinh " << u << endl;
        }
        
        // Đếm số cạnh
        pair<int,int> edge = {min(u,v), max(u,v)};
        edgeCount[edge]++;
        
        if (u != v) {
            cout << "Them canh (" << u << "," << v << ") - So canh: " 
                 << edgeCount[edge] << endl;
        }
    }
    
    // BFS cho general graph
    void bfs(int start) {
        resetArrays();
        
        queue<int> q;
        visited[start] = true;
        distance[start] = 0;
        q.push(start);
        
        cout << "BFS tren General Graph tu dinh " << start << ":" << endl;
        
        // Kiểm tra khuyên tại đỉnh bắt đầu
        if (selfLoops.count(start)) {
            cout << "Dinh bat dau " << start << " co khuyen!" << endl;
        }
        
        cout << "Thu tu duyet: ";
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            
            // Tạo set các đỉnh kề duy nhất (loại bỏ trùng lặp và khuyên)
            set<int> uniqueNeighbors;
            for (int v : adjList[u]) {
                if (v != u) { // Bỏ qua khuyên trong BFS
                    uniqueNeighbors.insert(v);
                }
            }
            
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
    
    // BFS cho toàn bộ đồ thị (xử lý thành phần liên thông)
    void bfsComplete() {
        resetArrays();
        
        cout << "BFS toan bo General Graph:" << endl;
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
            
            set<int> uniqueNeighbors;
            for (int v : adjList[u]) {
                if (v != u) { // Bỏ qua khuyên
                    uniqueNeighbors.insert(v);
                }
            }
            
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
    
    // Tìm đường đi ngắn nhất
    vector<int> getShortestPath(int start, int target) {
        bfs(start);
        
        vector<int> path;
        if (distance[target] == INT_MAX) {
            return path; // Không có đường đi
        }
        
        // Tái tao đường đi từ mảng parent
        int current = target;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        return path;
    }
    
    // In thông tin về đồ thị
    void printGraphInfo() {
        cout << "Thong tin General Graph:" << endl;
        cout << "So dinh: " << numVertices << endl;
        cout << "So dinh co khuyen: " << selfLoops.size() << endl;
        
        if (!selfLoops.empty()) {
            cout << "Cac dinh co khuyen: ";
            for (int v : selfLoops) {
                cout << v << " ";
            }
            cout << endl;
        }
        
        cout << "Cac canh boi:" << endl;
        bool hasMultipleEdges = false;
        for (auto& edge : edgeCount) {
            if (edge.second > 1) {
                cout << "Canh (" << edge.first.first << "," 
                     << edge.first.second << "): " << edge.second << " canh" << endl;
                hasMultipleEdges = true;
            }
        }
        if (!hasMultipleEdges) {
            cout << "Khong co canh boi" << endl;
        }
        cout << endl;
    }
    
    // Kiểm tra tính chất đặc biệt
    void checkSpecialProperties() {
        cout << "Kiem tra tinh chat dac biet:" << endl;
        
        // Kiểm tra có phải simple graph không
        bool isSimple = selfLoops.empty();
        for (auto& edge : edgeCount) {
            if (edge.second > 1) {
                isSimple = false;
                break;
            }
        }
        
        cout << "La simple graph: " << (isSimple ? "Co" : "Khong") << endl;
        cout << "La multigraph: " << (selfLoops.empty() ? "Co" : "Khong") << endl;
        cout << "La general graph: Co" << endl << endl;
    }
    
    // In khoảng cách
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
            cout << "Khong co cay BFS (chi co dinh " << start << ")" << endl;
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
    
    void printGraph() {
        cout << "Bieu dien General Graph (danh sach ke):" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Lấy danh sách đỉnh có khuyên
    set<int> getSelfLoops() {
        return selfLoops;
    }
    
    // Kiểm tra có cạnh bội giữa u và v không
    bool hasMultipleEdges(int u, int v) {
        pair<int,int> edge = {min(u,v), max(u,v)};
        return edgeCount[edge] > 1;
    }
    
    // Lấy số cạnh giữa u và v
    int getEdgeCount(int u, int v) {
        pair<int,int> edge = {min(u,v), max(u,v)};
        return edgeCount[edge];
    }
};

// Demo cho General Graph
void demonstrateGeneralGraph() {
    cout << "=== DEMO GENERAL GRAPH BFS ===" << endl << endl;
    
    // Tạo General Graph mẫu
    GeneralGraphBFS graph(6);
    
    cout << "Tao General Graph mau:" << endl;
    
    // Thêm cạnh bình thường
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    
    // Thêm cạnh bội
    graph.addEdge(0, 1); // Cạnh thứ 2 giữa 0 và 1
    graph.addEdge(1, 2); // Cạnh thứ 2 giữa 1 và 2
    
    // Thêm khuyên
    graph.addEdge(2, 2); // Khuyên tại đỉnh 2
    graph.addEdge(4, 4); // Khuyên tại đỉnh 4
    
    // Thêm thêm cạnh
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    
    cout << endl;
    graph.printGraph();
    graph.printGraphInfo();
    graph.checkSpecialProperties();
    
    // BFS từ đỉnh 0
    graph.bfs(0);
    graph.printDistances(0);
    graph.printBFSTree(0);
    
    // Tìm đường đi ngắn nhất
    cout << "Tim duong di ngan nhat tu 0 den 5:" << endl;
    auto path = graph.getShortestPath(0, 5);
    if (!path.empty()) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << " (Do dai: " << path.size() - 1 << ")" << endl;
    } else {
        cout << "Khong co duong di" << endl;
    }
    cout << endl;
    
    // BFS toàn bộ đồ thị
    graph.bfsComplete();
    
    // Kiểm tra liên thông
    cout << "Do thi co lien thong khong? " 
         << (graph.isConnected() ? "Co" : "Khong") << endl << endl;
}

// Demo General Graph không liên thông
void demonstrateDisconnectedGeneralGraph() {
    cout << "=== DEMO GENERAL GRAPH KHONG LIEN THONG ===" << endl << endl;
    
    GeneralGraphBFS graph(8);
    
    cout << "Tao General Graph khong lien thong:" << endl;
    
    // Thành phần 1: 0-1-2 với khuyên và cạnh bội
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(0, 1); // Cạnh bội
    graph.addEdge(1, 1); // Khuyên tại 1
    
    // Thành phần 2: 3-4 với khuyên
    graph.addEdge(3, 4);
    graph.addEdge(3, 3); // Khuyên tại 3
    
    // Thành phần 3: 5-6-7 với cạnh bội
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);
    graph.addEdge(5, 6); // Cạnh bội
    graph.addEdge(6, 7); // Cạnh bội
    
    cout << endl;
    graph.printGraph();
    graph.printGraphInfo();
    graph.bfsComplete();
}

// Interactive demo
void interactiveDemo() {
    cout << "=== DEMO TUONG TAC GENERAL GRAPH ===" << endl;
    
    int n, m;
    cout << "Nhap so dinh: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "So dinh phai duong!" << endl;
        return;
    }
    
    GeneralGraphBFS userGraph(n);
    
    cout << "Nhap so canh (co the co canh boi va khuyen): ";
    cin >> m;
    
    cout << "Nhap " << m << " canh (u v), co the co khuyen (u u) va canh boi:" << endl;
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
    
    cout << endl;
    userGraph.printGraph();
    userGraph.printGraphInfo();
    userGraph.checkSpecialProperties();
    
    int start;
    cout << "Nhap dinh bat dau BFS: ";
    cin >> start;
    
    if (start >= 0 && start < n) {
        userGraph.bfs(start);
        userGraph.printDistances(start);
        userGraph.printBFSTree(start);
        
        // Tùy chọn bổ sung
        char choice;
        cout << "Ban co muon tim duong di ngan nhat khong? (y/n): ";
        cin >> choice;
        
        if (choice == 'y' || choice == 'Y') {
            int target;
            cout << "Nhap dinh dich: ";
            cin >> target;
            
            if (target >= 0 && target < n) {
                auto path = userGraph.getShortestPath(start, target);
                if (!path.empty()) {
                    cout << "Duong di ngan nhat tu " << start << " den " << target << ": ";
                    for (int i = 0; i < path.size(); i++) {
                        cout << path[i];
                        if (i < path.size() - 1) cout << " -> ";
                    }
                    cout << " (Do dai: " << path.size() - 1 << ")" << endl;
                } else {
                    cout << "Khong co duong di tu " << start << " den " << target << endl;
                }
            }
        }
    } else {
        cout << "Dinh bat dau khong hop le!" << endl;
    }
}

int main() {
    cout << "CHUONG TRINH DEMO BFS TREN GENERAL GRAPH" << endl;
    cout << string(50, '=') << endl << endl;
    
    // Demo cơ bản
    demonstrateGeneralGraph();
    
    cout << string(50, '=') << endl << endl;
    
    // Demo không liên thông
    demonstrateDisconnectedGeneralGraph();
    
    cout << string(50, '=') << endl << endl;
    
    // Demo tương tác
    char choice;
    cout << "Ban co muon chay demo tuong tac khong? (y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        interactiveDemo();
    }
    
    return 0;
}