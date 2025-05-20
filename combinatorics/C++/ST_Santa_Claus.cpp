#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 6;
vector<pair<int, int>> edges;
bool used[20]; 
vector<int> path;
int countWays = 0;

int findEdgeIndex(int u, int v) {
    for (int i = 0; i < edges.size(); ++i) {
        if (!used[i] && (
            (edges[i].first == u && edges[i].second == v) ||
            (edges[i].first == v && edges[i].second == u))) {
            return i;
        }
    }
    return -1;
}

void dfs(int u, int depth) {
    path.push_back(u);

    if (depth == edges.size()) {
        // In ra 1 cach ve hop le
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
        countWays++;
        path.pop_back();
        return;
    }

    for (int v = 1; v <= 5; ++v) {
        int edgeId = findEdgeIndex(u, v);
        if (edgeId != -1) {
            used[edgeId] = true;
            dfs(v, depth + 1);
            used[edgeId] = false;
        }
    }

    path.pop_back();
}

int main() {
    edges = {
        {1, 2}, {1, 3}, {1, 5},
        {2, 3}, {2, 5},
        {3, 4}, {3, 5},
        {4, 5}
    };

    cout << "Cac duong di (Euler path) cua House of Santa Claus:\n";
    dfs(1, 0);

    cout << "\nTong so cach ve hop le: " << countWays << endl;

    return 0;
}