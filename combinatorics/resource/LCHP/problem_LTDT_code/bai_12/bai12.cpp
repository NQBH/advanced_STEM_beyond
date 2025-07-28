#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class MultigraphDFS {
private:
    int numVertices;
    // Sử dụng multiset để lưu cạnh bội
    vector<multiset<int>> adjList;
    // Đếm số cạnh giữa mỗi cặp đỉnh
    map<pair<int,int>, int> edgeCount;
    
    vector<bool> visited;
    vector<int> startTime;
    vector<int> finishTime;
    vector<int> parent;
    vector<int> dfsOrder;
    int timeCounter;
    
    // Thông tin về cạnh bội
    vector<tuple<int, int, int, string>> edgeInfo; // (u, v, count, type)
    
public:
    MultigraphDFS(int n) : numVertices(n), timeCounter(0) {
        adjList.resize(n);
        resetArrays();
    }
    
    void resetArrays() {
        visited.assign(numVertices, false);
        startTime.assign(numVertices, 0);
        finishTime.assign(numVertices, 0);
        parent.assign(numVertices, -1);
        dfsOrder.clear();
        edgeInfo.clear();
        timeCounter = 0;
    }
    
    void addEdge(int u, int v) {
        adjList[u].insert(v);
        adjList[v].insert(u); // Đa đồ thị vô hướng
        
        // Cập nhật số lượng cạnh
        pair<int,int> edge = {min(u,v), max(u,v)};
        edgeCount[edge]++;
    }
    
    // DFS cho đa đồ thị
    void dfsRecursive(int u) {
        visited[u] = true;
        startTime[u] = ++timeCounter;
        dfsOrder.push_back(u);
        
        cout << "Thăm đỉnh " << u << " (start: " << startTime[u] << ")" << endl;
        
        // Duyệt các đỉnh kề (chỉ duyệt một lần mỗi đỉnh kề duy nhất)
        set<int> uniqueNeighbors(adjList[u].begin(), adjList[u].end());
        
        for (int v : uniqueNeighbors) {
            // Đếm số cạnh giữa u và v
            pair<int,int> edge = {min(u,v), max(u,v)};
            int count = edgeCount[edge];
            
            if (!visited[v]) {
                parent[v] = u;
                edgeInfo.push_back({u, v, count, "TREE"});
                cout << "  Cạnh cây: " << u << " -> " << v 
                     << " (số cạnh: " << count << ")" << endl;
                dfsRecursive(v);
            } else {
                // Phân loại cạnh bội
                if (startTime[v] < startTime[u] && finishTime[v] == 0) {
                    edgeInfo.push_back({u, v, count, "BACK"});
                    cout << "  Cạnh ngược: " << u << " -> " << v 
                         << " (số cạnh: " << count << ", chu trình!)" << endl;
                } else if (startTime[v] > startTime[u]) {
                    edgeInfo.push_back({u, v, count, "FORWARD"});
                    cout << "  Cạnh xuôi: " << u << " -> " << v 
                         << " (số cạnh: " << count << ")" << endl;
                } else if (v != parent[u]) { // Tránh cạnh cha-con
                    edgeInfo.push_back({u, v, count, "CROSS"});
                    cout << "  Cạnh chéo: " << u << " -> " << v 
                         << " (số cạnh: " << count << ")" << endl;
                }
            }
        }
        
        finishTime[u] = ++timeCounter;
        cout << "Kết thúc đỉnh " << u << " (finish: " << finishTime[u] << ")" << endl;
    }
    
    void dfsComplete() {
        resetArrays();
        
        cout << "DFS toàn bộ đa đồ thị:" << endl;
        int componentCount = 0;
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                componentCount++;
                cout << "\nThành phần liên thông " << componentCount << ":" << endl;
                dfsRecursive(i);
            }
        }
        
        cout << "\nTổng số thành phần liên thông: " << componentCount << endl;
        analyzeMultipleEdges();
    }
    
    void analyzeMultipleEdges() {
        cout << "\nPhân tích cạnh bội:" << endl;
        
        bool hasCycle = false;
        int totalEdges = 0;
        int multipleEdges = 0;
        
        for (auto& info : edgeInfo) {
            int u = get<0>(info);
            int v = get<1>(info);
            int count = get<2>(info);
            string type = get<3>(info);
            
            cout << "Cạnh (" << u << "," << v << "): " 
                 << type << ", Số lượng: " << count << endl;
            
            totalEdges += count;
            if (count > 1) {
                multipleEdges++;
            }
            
            if (type == "BACK") {
                hasCycle = true;
            }
        }
        
        cout << "\nThống kê:" << endl;
        cout << "Tổng số cạnh: " << totalEdges/2 << endl; // Chia 2 vì đồ thị vô hướng
        cout << "Số cặp đỉnh có cạnh bội: " << multipleEdges << endl;
        cout << "Đồ thị có chu trình: " << (hasCycle ? "Có" : "Không") << endl;
    }
    
    void printMultigraph() {
        cout << "Biểu diễn đa đồ thị:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        
        cout << "\nSố lượng cạnh giữa các cặp đỉnh:" << endl;
        for (auto& edge : edgeCount) {
            cout << "(" << edge.first.first << "," << edge.first.second 
                 << "): " << edge.second << " cạnh" << endl;
        }
        cout << endl;
    }
    
    // Tìm đường đi với ít cạnh bội nhất
    void findPathWithMinMultipleEdges(int start, int end) {
        vector<int> dist(numVertices, INT_MAX);
        vector<int> parent(numVertices, -1);
        vector<bool> visited(numVertices, false);
        
        dist[start] = 0;
        
        for (int count = 0; count < numVertices - 1; count++) {
            int u = -1;
            for (int v = 0; v < numVertices; v++) {
                if (!visited[v] && (u == -1 || dist[v] < dist[u])) {
                    u = v;
                }
            }
            
            if (dist[u] == INT_MAX) break;
            visited[u] = true;
            
            set<int> uniqueNeighbors(adjList[u].begin(), adjList[u].end());
            for (int v : uniqueNeighbors) {
                pair<int,int> edge = {min(u,v), max(u,v)};
                int edgeWeight = edgeCount[edge]; // Trọng số = số cạnh bội
                
                if (dist[u] + edgeWeight < dist[v]) {
                    dist[v] = dist[u] + edgeWeight;
                    parent[v] = u;
                }
            }
        }
        
        if (dist[end] == INT_MAX) {
            cout << "Không có đường đi từ " << start << " đến " << end << endl;
        } else {
            cout << "Đường đi với ít cạnh bội nhất từ " << start << " đến " << end << ":" << endl;
            vector<int> path;
            int current = end;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            
            reverse(path.begin(), path.end());
            
            cout << "Đường đi: ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) {
                    cout << " -> ";
                }
            }
            cout << "\nTổng trọng số cạnh bội: " << dist[end] << endl;
        }
    }
    
    void printTimes() {
        cout << "\nThông tin thời gian DFS:" << endl;
        cout << "Đỉnh\tStart\t\tFinish\t\tCha" << endl;
        cout << "----\t-----\t\t------\t\t---" << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << i << "\t" << startTime[i] << "\t\t" 
                 << finishTime[i] << "\t\t" << parent[i] << endl;
        }
        cout << endl;
    }
};

// Demo cho đa đồ thị
void demonstrateMultigraphDFS() {
    cout << "=== DEMO DFS CHO ĐA ĐỒ THỊ ===" << endl << endl;
    
    MultigraphDFS graph(5);
    
    // Tạo đa đồ thị với cạnh bội
    cout << "Tạo đa đồ thị với cạnh bội:" << endl;
    graph.addEdge(0, 1);
    graph.addEdge(0, 1); // Cạnh bội
    graph.addEdge(0, 1); // Cạnh bội thứ 3
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 3); // Cạnh bội
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 4); // Cạnh bội
    graph.addEdge(1, 2); // Tạo chu trình
    cout << endl;
    
    graph.printMultigraph();
    
    // DFS trên đa đồ thị
    graph.dfsComplete();
    graph.printTimes();
    
    // Tìm đường đi với ít cạnh bội nhất
    cout << "\n" << endl;
    graph.findPathWithMinMultipleEdges(0, 4);
}

int main() {
    demonstrateMultigraphDFS();
    return 0;
}