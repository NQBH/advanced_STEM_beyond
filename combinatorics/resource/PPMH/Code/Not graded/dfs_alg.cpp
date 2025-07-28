#include <iostream>
#include <vector>
using namespace std;

int n = 8, Vs = 1, Vt = 5;
vector<vector<int>> adj = {
    {},         
    {2, 3},     
    {3, 4},     
    {1, 5},     
    {6},       
    {},         
    {2},       
    {8},        
    {}         
};

vector<bool> visited(n + 1, false);
vector<int> path;
vector<vector<int>> allPaths;

void dfs(int u) {
    path.push_back(u);
    if (u == Vt) {
        allPaths.push_back(path);
    } else {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
        visited[u] = false;
    }
    path.pop_back();
}

int main() {
    dfs(Vs);

    cout << allPaths.size() << endl;
    for (const auto& p : allPaths) {
        for (int v : p) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}