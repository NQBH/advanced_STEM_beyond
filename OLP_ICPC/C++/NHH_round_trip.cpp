#include <iostream> 
#include <vector> 
using namespace std; 

bool dfs(const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent, int city, int parent_city, int& start, int& end){
    visited[city] = true; 
    for (int neighbor : adj[city]){
        if (!visited[neighbor]){
            parent[neighbor] = city;
            if(dfs(adj, visited, parent, neighbor, city, start, end)) return true; 
        } else if (neighbor != parent_city){ // Gặp lại đỉnh đã thăm không phải cha
            start = neighbor; end = city;
            return true;
        }
    }
    return false;
}

int main(){
    int n, m; cin >> n >> m; 
    vector<vector<int>> pairRoad(n + 1);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        pairRoad[a].push_back(b);
        pairRoad[b].push_back(a);
    }

    vector<bool> visited(n + 1);
    vector<int> parent(n + 1, -1);
    int start = -1, end = -1;

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            if (dfs(pairRoad, visited, parent, i, -1, start, end)){
                break;
            }
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Reconstruct and output the cycle
    vector<int> route;
    for (int v = end; v != start; v = parent[v]) route.push_back(v);
    route.push_back(start);
    route.push_back(end); // để khép chu trình đúng format

    cout << route.size() << "\n";
    for (int i = route.size() - 1; i >= 0; i--) cout << route[i] << " ";
    cout << endl;

    return 0;
}
