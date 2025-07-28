#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;

class SimpleDFS {
private:
    int numVertices;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> startTime;
    vector<int> finishTime;
    vector<int> parent;
    vector<int> dfsOrder;
    int timeCounter;
    
    // Phan loai canh
    enum EdgeType { TREE, BACK, FORWARD, CROSS };
    vector<tuple<int, int, EdgeType>> edges;
    
public:
    SimpleDFS(int n) : numVertices(n), timeCounter(0) {
        adjList.resize(n);
        resetArrays();
    }
    
    void resetArrays() {
        visited.assign(numVertices, false);
        startTime.assign(numVertices, 0);
        finishTime.assign(numVertices, 0);
        parent.assign(numVertices, -1);
        dfsOrder.clear();
        edges.clear();
        timeCounter = 0;
    }
    
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Do thi vo huong
    }
    
    // DFS de quy
    void dfsRecursive(int u) {
        visited[u] = true;
        startTime[u] = ++timeCounter;
        dfsOrder.push_back(u);
        
        cout << "Tham dinh " << u << " (start: " << startTime[u] << ")" << endl;
        
        // Duyet cac dinh ke
        for (int v : adjList[u]) {
            if (!visited[v]) {
                parent[v] = u;
                edges.push_back({u, v, TREE});
                cout << "  Canh cay: " << u << " -> " << v << endl;
                dfsRecursive(v);
            } else {
                // Phan loai canh
                if (startTime[v] < startTime[u] && finishTime[v] == 0) {
                    edges.push_back({u, v, BACK});
                    cout << "  Canh nguoc: " << u << " -> " << v << " (chu trinh!)" << endl;
                } else if (startTime[v] > startTime[u]) {
                    edges.push_back({u, v, FORWARD});
                    cout << "  Canh xuoi: " << u << " -> " << v << endl;
                } else {
                    edges.push_back({u, v, CROSS});
                    cout << "  Canh cheo: " << u << " -> " << v << endl;
                }
            }
        }
        
        finishTime[u] = ++timeCounter;
        cout << "Ket thuc dinh " << u << " (finish: " << finishTime[u] << ")" << endl;
    }
    
    // DFS khong de quy
    void dfsIterative(int start) {
        resetArrays();
        
        stack<int> stk;
        stack<int> path; // De theo doi duong di
        
        cout << "DFS khong de quy tu dinh " << start << ":" << endl;
        
        stk.push(start);
        
        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();
            
            if (!visited[u]) {
                visited[u] = true;
                startTime[u] = ++timeCounter;
                dfsOrder.push_back(u);
                
                cout << "Tham dinh " << u << " (start: " << startTime[u] << ")" << endl;
                
                // Them cac dinh ke vao stack (thu tu nguoc lai)
                vector<int> neighbors = adjList[u];
                sort(neighbors.rbegin(), neighbors.rend());
                
                for (int v : neighbors) {
                    if (!visited[v]) {
                        stk.push(v);
                        if (parent[v] == -1) {
                            parent[v] = u;
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    
    // DFS toan bo do thi
    void dfsComplete() {
        resetArrays();
        
        cout << "DFS toan bo do thi:" << endl;
        int componentCount = 0;
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                componentCount++;
                cout << "\nThanh phan lien thong " << componentCount << ":" << endl;
                dfsRecursive(i);
            }
        }
        
        cout << "\nTong so thanh phan lien thong: " << componentCount << endl;
        analyzeCycles();
    }
    
    // Phan tich chu trinh
    void analyzeCycles() {
        bool hasCycle = false;
        
        cout << "\nPhan tich canh:" << endl;
        for (auto& edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            EdgeType type = get<2>(edge);
            
            string typeStr;
            switch (type) {
                case TREE: typeStr = "Cay"; break;
                case BACK: typeStr = "Nguoc"; hasCycle = true; break;
                case FORWARD: typeStr = "Xuoi"; break;
                case CROSS: typeStr = "Cheo"; break;
            }
            
            cout << "Canh (" << u << "," << v << "): " << typeStr << endl;
        }
        
        cout << "\nDo thi co chu trinh: " << (hasCycle ? "Co" : "Khong") << endl;
    }
    
    // Tim tat ca duong di tu start den end
    void findAllPaths(int start, int end) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        vector<bool> tempVisited(numVertices, false);
        
        findAllPathsHelper(start, end, currentPath, allPaths, tempVisited);
        
        cout << "\nTat ca duong di tu " << start << " den " << end << ":" << endl;
        for (int i = 0; i < allPaths.size(); i++) {
            cout << "Duong " << i + 1 << ": ";
            for (int j = 0; j < allPaths[i].size(); j++) {
                cout << allPaths[i][j];
                if (j < allPaths[i].size() - 1) cout << " -> ";
            }
            cout << endl;
        }
        
        if (allPaths.empty()) {
            cout << "Khong co duong di tu " << start << " den " << end << endl;
        }
    }
    
private:
    void findAllPathsHelper(int current, int end, vector<int>& path, 
                           vector<vector<int>>& allPaths, vector<bool>& tempVisited) {
        path.push_back(current);
        tempVisited[current] = true;
        
        if (current == end) {
            allPaths.push_back(path);
        } else {
            for (int neighbor : adjList[current]) {
                if (!tempVisited[neighbor]) {
                    findAllPathsHelper(neighbor, end, path, allPaths, tempVisited);
                }
            }
        }
        
        path.pop_back();
        tempVisited[current] = false;
    }
    
public:
    // Sap xep topo (chi cho do thi co huong)
    vector<int> topologicalSort() {
        resetArrays();
        stack<int> topoStack;
        
        // Goi DFS cho tat ca dinh
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                topoDFS(i, topoStack);
            }
        }
        
        vector<int> result;
        while (!topoStack.empty()) {
            result.push_back(topoStack.top());
            topoStack.pop();
        }
        
        return result;
    }
    
private:
    void topoDFS(int u, stack<int>& topoStack) {
        visited[u] = true;
        
        for (int v : adjList[u]) {
            if (!visited[v]) {
                topoDFS(v, topoStack);
            }
        }
        
        topoStack.push(u);
    }
    
public:
    // In thong tin thoi gian
    void printTimes() {
        cout << "\nThong tin thoi gian DFS:" << endl;
        cout << setw(6) << "Dinh" << setw(12) << "Start" << setw(12) << "Finish" 
             << setw(10) << "Cha" << endl;
        cout << string(40, '-') << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << setw(6) << i 
                 << setw(12) << startTime[i]
                 << setw(12) << finishTime[i]
                 << setw(10) << parent[i] << endl;
        }
        cout << endl;
    }
    
    void printDFSTree() {
        cout << "Cay DFS:" << endl;
        for (int i = 0; i < numVertices; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " -> " << i << endl;
            }
        }
        cout << endl;
    }
    
    void printGraph() {
        cout << "Bieu dien do thi don:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Kiem tra tinh lien thong
    bool isConnected() {
        dfsRecursive(0);
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};

// Demo cho do thi don
void demonstrateSimpleDFS() {
    cout << "=== DEMO DFS CHO DO THI DON ===" << endl << endl;
    
    SimpleDFS graph(6);
    
    // Tao do thi mau
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(1, 2); // Tao chu trinh
    
    graph.printGraph();
    
    // DFS de quy
    cout << "1. DFS DE QUY:" << endl;
    graph.dfsComplete();
    graph.printTimes();
    graph.printDFSTree();
    
    // DFS khong de quy
    cout << "2. DFS KHONG DE QUY:" << endl;
    graph.dfsIterative(0);
    
    // Tim tat ca duong di
    graph.findAllPaths(0, 5);
    
    // Kiem tra lien thong
    cout << "\nDo thi co lien thong: " 
         << (graph.isConnected() ? "Co" : "Khong") << endl;
}

int main() {
    demonstrateSimpleDFS();
    return 0;
}