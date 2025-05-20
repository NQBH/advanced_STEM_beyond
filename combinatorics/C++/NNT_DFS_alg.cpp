#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstring>
#include <limits>
#include <climits>
#include <utility>
using namespace std;

// Type Aliases
typedef long long ll;
typedef pair<int, int> pii; 
typedef vector<int> vi;
typedef vector<ll> vll;

// Fast IO
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Common Macros
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

// Constants
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

// Globals for DFS
int n, v_s, v_t;
vector<vi> adj;
vector<bool> visited;
vi current;
vector<vi> paths;

void dfs(int u) {
    if (u == v_t) {
        paths.pb(current);
        return;
    }
    for (int w : adj[u]) {
        if (!visited[w]) {
            visited[w] = true;
            current.pb(w);
            dfs(w);
            current.pop_back();
            visited[w] = false;
        }
    }
}

// Solve Function
void solve() {
    cin >> n >> v_s >> v_t;
    string line;
    getline(cin, line); // consume end of line

    adj.assign(n+1, vi());
    for (int i = 1; i <= n; i++) {
        getline(cin, line);
        istringstream in(line);
        int j;
        while (in >> j) {
            adj[i].pb(j);
        }
    }

    visited.assign(n+1, false);
    visited[v_s] = true;
    current.clear();
    current.pb(v_s);
    dfs(v_s);

    cout << paths.size() << "\n";
    for (auto &p : paths) {
        for (int x : p) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// Main
int main() {
    fast_io;
    int t = 1;
    // cin >> t; // Uncomment for multiple test cases
    while (t--) solve();
    return 0;
}