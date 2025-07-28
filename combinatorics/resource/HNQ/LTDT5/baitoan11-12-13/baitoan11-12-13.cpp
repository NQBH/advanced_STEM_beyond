#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

// Lớp cơ sở cho đồ thị
class Graph {
protected:
    int vertices;  // Số đỉnh
    
public:
    Graph(int v) : vertices(v) {}
    virtual ~Graph() {}
    
    virtual void addEdge(int u, int v) = 0;
    virtual void dfsRecursive(int start) = 0;
    virtual void dfsIterative(int start) = 0;
    virtual void displayGraph() = 0;
    virtual string getType() = 0;
    
    int getVertices() { return vertices; }
};

// Bài toán 11: Simple Graph - Đồ thị đơn giản
class SimpleGraph : public Graph {
private:
    vector<vector<int>> adjList;  // Danh sách kề
    vector<bool> visited;         // Mảng đánh dấu đã thăm
    
    void dfsRecursiveHelper(int vertex, vector<bool>& vis) {
        vis[vertex] = true;
        cout << vertex << " ";
        
        // Duyệt tất cả đỉnh kề
        for (int neighbor : adjList[vertex]) {
            if (!vis[neighbor]) {
                dfsRecursiveHelper(neighbor, vis);
            }
        }
    }
    
public:
    SimpleGraph(int v) : Graph(v) {
        adjList.resize(v);
        visited.resize(v);
    }
    
    // Thêm cạnh (không trùng lặp, không tự khuyên)
    void addEdge(int u, int v) override {
        if (u != v) {  // Không cho phép tự khuyên
            // Kiểm tra cạnh đã tồn tại chưa
            if (find(adjList[u].begin(), adjList[u].end(), v) == adjList[u].end()) {
                adjList[u].push_back(v);
                adjList[v].push_back(u);  // Đồ thị vô hướng
            }
        }
    }
    
    void dfsRecursive(int start) override {
        fill(visited.begin(), visited.end(), false);
        cout << "DFS Recursive (Simple Graph): ";
        dfsRecursiveHelper(start, visited);
        cout << endl;
    }
    
    void dfsIterative(int start) override {
        fill(visited.begin(), visited.end(), false);
        stack<int> st;
        
        cout << "DFS Iterative (Simple Graph): ";
        st.push(start);
        
        while (!st.empty()) {
            int vertex = st.top();
            st.pop();
            
            if (!visited[vertex]) {
                visited[vertex] = true;
                cout << vertex << " ";
                
                // Thêm các đỉnh kề vào stack (theo thứ tự ngược)
                for (auto it = adjList[vertex].rbegin(); it != adjList[vertex].rend(); ++it) {
                    if (!visited[*it]) {
                        st.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }
    
    void displayGraph() override {
        cout << "\n=== SIMPLE GRAPH ===\n";
        for (int i = 0; i < vertices; i++) {
            cout << "Đỉnh " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    
    string getType() override { return "Simple Graph"; }
};

// Bài toán 12: Multigraph - Đa đồ thị
class Multigraph : public Graph {
private:
    vector<map<int, int>> adjList;  // map<đỉnh_kề, số_cạnh>
    vector<bool> visited;
    
    void dfsRecursiveHelper(int vertex, vector<bool>& vis) {
        vis[vertex] = true;
        cout << vertex << " ";
        
        // Duyệt tất cả đỉnh kề (bỏ qua số lượng cạnh)
        for (auto& edge : adjList[vertex]) {
            int neighbor = edge.first;
            if (!vis[neighbor]) {
                dfsRecursiveHelper(neighbor, vis);
            }
        }
    }
    
public:
    Multigraph(int v) : Graph(v) {
        adjList.resize(v);
        visited.resize(v);
    }
    
    // Thêm cạnh (cho phép đa cạnh)
    void addEdge(int u, int v) override {
        if (u != v) {  // Không cho phép tự khuyên
            adjList[u][v]++;
            adjList[v][u]++;  // Đồ thị vô hướng
        }
    }
    
    void dfsRecursive(int start) override {
        fill(visited.begin(), visited.end(), false);
        cout << "DFS Recursive (Multigraph): ";
        dfsRecursiveHelper(start, visited);
        cout << endl;
    }
    
    void dfsIterative(int start) override {
        fill(visited.begin(), visited.end(), false);
        stack<int> st;
        
        cout << "DFS Iterative (Multigraph): ";
        st.push(start);
        
        while (!st.empty()) {
            int vertex = st.top();
            st.pop();
            
            if (!visited[vertex]) {
                visited[vertex] = true;
                cout << vertex << " ";
                
                // Thêm các đỉnh kề vào stack
                vector<int> neighbors;
                for (auto& edge : adjList[vertex]) {
                    neighbors.push_back(edge.first);
                }
                
                // Sắp xếp ngược để đảm bảo thứ tự đúng trong stack
                sort(neighbors.rbegin(), neighbors.rend());
                for (int neighbor : neighbors) {
                    if (!visited[neighbor]) {
                        st.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }
    
    void displayGraph() override {
        cout << "\n=== MULTIGRAPH ===\n";
        for (int i = 0; i < vertices; i++) {
            cout << "Đỉnh " << i << ": ";
            for (auto& edge : adjList[i]) {
                cout << edge.first << "(" << edge.second << ") ";
            }
            cout << endl;
        }
    }
    
    string getType() override { return "Multigraph"; }
};

// Bài toán 13: General Graph - Đồ thị tổng quát
class GeneralGraph : public Graph {
private:
    vector<map<int, int>> adjList;  // map<đỉnh_kề, số_cạnh> (bao gồm cả tự khuyên)
    vector<bool> visited;
    
    void dfsRecursiveHelper(int vertex, vector<bool>& vis) {
        vis[vertex] = true;
        cout << vertex << " ";
        
        // Duyệt tất cả đỉnh kề (bao gồm cả tự khuyên)
        for (auto& edge : adjList[vertex]) {
            int neighbor = edge.first;
            if (!vis[neighbor]) {
                dfsRecursiveHelper(neighbor, vis);
            }
        }
    }
    
public:
    GeneralGraph(int v) : Graph(v) {
        adjList.resize(v);
        visited.resize(v);
    }
    
    // Thêm cạnh (cho phép đa cạnh và tự khuyên)
    void addEdge(int u, int v) override {
        adjList[u][v]++;
        if (u != v) {  // Nếu không phải tự khuyên thì thêm cạnh ngược
            adjList[v][u]++;
        }
    }
    
    void dfsRecursive(int start) override {
        fill(visited.begin(), visited.end(), false);
        cout << "DFS Recursive (General Graph): ";
        dfsRecursiveHelper(start, visited);
        cout << endl;
    }
    
    void dfsIterative(int start) override {
        fill(visited.begin(), visited.end(), false);
        stack<int> st;
        
        cout << "DFS Iterative (General Graph): ";
        st.push(start);
        
        while (!st.empty()) {
            int vertex = st.top();
            st.pop();
            
            if (!visited[vertex]) {
                visited[vertex] = true;
                cout << vertex << " ";
                
                // Thêm các đỉnh kề vào stack
                vector<int> neighbors;
                for (auto& edge : adjList[vertex]) {
                    neighbors.push_back(edge.first);
                }
                
                // Sắp xếp ngược để đảm bảo thứ tự đúng trong stack
                sort(neighbors.rbegin(), neighbors.rend());
                for (int neighbor : neighbors) {
                    if (!visited[neighbor]) {
                        st.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }
    
    void displayGraph() override {
        cout << "\n=== GENERAL GRAPH ===\n";
        for (int i = 0; i < vertices; i++) {
            cout << "Đỉnh " << i << ": ";
            for (auto& edge : adjList[i]) {
                if (edge.first == i) {
                    cout << "loop(" << edge.second << ") ";
                } else {
                    cout << edge.first << "(" << edge.second << ") ";
                }
            }
            cout << endl;
        }
    }
    
    string getType() override { return "General Graph"; }
};

// Hàm kiểm tra và so sánh các thuật toán
void demonstrateGraphTypes() {
    cout << "========================================\n";
    cout << "DEMONSTRATION OF DFS ON DIFFERENT GRAPH TYPES\n";
    cout << "========================================\n\n";
    
    // Tạo đồ thị mẫu với 6 đỉnh
    int vertices = 6;
    
    // 1. Simple Graph
    SimpleGraph sg(vertices);
    sg.addEdge(0, 1);
    sg.addEdge(0, 2);
    sg.addEdge(1, 3);
    sg.addEdge(2, 4);
    sg.addEdge(3, 5);
    sg.addEdge(4, 5);
    // Thử thêm cạnh trùng lặp (sẽ bị bỏ qua)
    sg.addEdge(0, 1);
    
    sg.displayGraph();
    sg.dfsRecursive(0);
    sg.dfsIterative(0);
    
    cout << "\n" << string(50, '-') << "\n";
    
    // 2. Multigraph
    Multigraph mg(vertices);
    mg.addEdge(0, 1);
    mg.addEdge(0, 1);  // Đa cạnh
    mg.addEdge(0, 2);
    mg.addEdge(1, 3);
    mg.addEdge(1, 3);  // Đa cạnh
    mg.addEdge(2, 4);
    mg.addEdge(3, 5);
    mg.addEdge(4, 5);
    mg.addEdge(4, 5);  // Đa cạnh
    
    mg.displayGraph();
    mg.dfsRecursive(0);
    mg.dfsIterative(0);
    
    cout << "\n" << string(50, '-') << "\n";
    
    // 3. General Graph
    GeneralGraph gg(vertices);
    gg.addEdge(0, 1);
    gg.addEdge(0, 1);  // Đa cạnh
    gg.addEdge(0, 2);
    gg.addEdge(1, 1);  // Tự khuyên
    gg.addEdge(1, 3);
    gg.addEdge(2, 2);  // Tự khuyên
    gg.addEdge(2, 4);
    gg.addEdge(3, 5);
    gg.addEdge(4, 5);
    gg.addEdge(5, 5);  // Tự khuyên
    
    gg.displayGraph();
    gg.dfsRecursive(0);
    gg.dfsIterative(0);
}

// Phân tích độ phức tạp
void complexityAnalysis() {
    cout << "\n\n========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n";
    
    cout << "Độ phức tạp thời gian DFS:\n";
    cout << "- Simple Graph: O(V + E)\n";
    cout << "- Multigraph: O(V + E') (E' = tổng số cạnh thực tế)\n";
    cout << "- General Graph: O(V + E') (E' = tổng số cạnh + tự khuyên)\n\n";
    
    cout << "Độ phức tạp không gian:\n";
    cout << "- Recursive: O(V) (call stack)\n";
    cout << "- Iterative: O(V) (explicit stack)\n";
    cout << "- Adjacency List: O(V + E)\n\n";
    
    cout << "Đặc điểm của từng loại đồ thị:\n";
    cout << "1. Simple Graph: Không đa cạnh, không tự khuyên\n";
    cout << "2. Multigraph: Cho phép đa cạnh, không tự khuyên\n";
    cout << "3. General Graph: Cho phép đa cạnh và tự khuyên\n";
}

int main() {
    demonstrateGraphTypes();
    complexityAnalysis();
    
    cout << "\n========================================\n";
    cout << "Chương trình hoàn thành!\n";
    cout << "========================================\n";
    
    return 0;
}