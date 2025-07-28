#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Multigraph {
private:
    unordered_map<int, vector<int>> adj;

    void dfsUtil(int v, unordered_set<int>& visited) {
        visited.insert(v);
        cout << v << " ";
        for (int neighbor : adj[v]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsUtil(neighbor, visited);
            }
        }
    }

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v); 
    }

    void dfs(int start) {
        unordered_set<int> visited;
        cout << "DFS traversal: ";
        dfsUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Multigraph G;
    G.addEdge(0, 1);
    G.addEdge(0, 1); 
    G.addEdge(1, 2);
    G.addEdge(2, 0);
    G.addEdge(2, 3);
    G.addEdge(3, 3); 

    G.dfs(2);

    return 0;
}