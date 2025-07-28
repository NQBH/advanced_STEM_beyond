#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Lớp biểu diễn đồ thị
class Graph {
public:
    int V; // Số đỉnh
    vector<vector<int>> adj; // Danh sách kề

    Graph(int vertices) : V(vertices), adj(vertices) {}

    // Thêm cạnh (cho đồ thị vô hướng)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Chuyển đổi sang Ma trận kề
    vector<vector<int>> toAdjacencyMatrix() {
        vector<vector<int>> matrix(V, vector<int>(V, 0));
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                matrix[u][v]++;
            }
        }
        return matrix;
    }

    // Chuyển đổi sang Ánh xạ kề
    map<int, vector<int>> toAdjacencyMap() {
        map<int, vector<int>> adjMap;
        for (int i = 0; i < V; ++i) {
            if (!adj[i].empty()) {
                adjMap[i] = adj[i];
            }
        }
        return adjMap;
    }

    void printAdjList() {
        cout << "Danh sach ke:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << i << ": ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

// Lớp biểu diễn cây (kế thừa từ Graph)
class Tree : public Graph {
public:
    Tree(int vertices) : Graph(vertices) {}

    // Chuyển đổi sang Mảng Cha
    vector<int> toParentArray(int root) {
        vector<int> parent(V, -1); // -1 cho gốc và các đỉnh không kết nối
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(root);
        visited[root] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        return parent;
    }
};

int main() {
    cout << "--- Bieu dien Do thi ---" << endl;
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2); // Thêm cạnh song song

    g.printAdjList();

    vector<vector<int>> matrix = g.toAdjacencyMatrix();
    cout << "\nMa tran ke:" << endl;
    for (int i = 0; i < g.V; ++i) {
        for (int j = 0; j < g.V; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\n--- Bieu dien Cay ---" << endl;
    Tree t(5);
    t.addEdge(0, 1);
    t.addEdge(0, 2);
    t.addEdge(1, 3);
    t.addEdge(1, 4);

    t.printAdjList();
    
    vector<int> parent_array = t.toParentArray(0);
    cout << "\nMang Cha (goc la 0):" << endl;
    for (int i = 0; i < t.V; ++i) {
        cout << "parent[" << i << "] = " << parent_array[i] << endl;
    }

    return 0;
}