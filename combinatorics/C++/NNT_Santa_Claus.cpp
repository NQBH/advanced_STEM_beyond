#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <limits>
#include <climits>
#include <utility>
using namespace std;

// Type Aliases
typedef long long ll;
typedef pair<int,int> pii;
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

// We have 8 undirected edges in the "House of Santa Claus" graph:
//   (1–2), (2–3), (3–5), (5–1), (5–4), (4–3), (1–3), (2–5)
// We'll build an adjacency list of directed arcs, pairing each undirected
// edge with a unique ID so we can mark it "used" exactly once total.
vector<vector<pair<int,int>>> adj;  // adj[u] = list of (v, edgeID)
bool usedEdge[8];
vi current;
vector<string> results;

// depth = how many edges have been used so far
void dfs(int u, int depth) {
    if (depth == 8) {
        // we've used all edges, record the 9‐vertex path
        string s;
        for (int x : current) s += char('0' + x);
        results.pb(s);
        return;
    }
    // explore neighbors in increasing order → lex order of strings
    for (auto [v,eid] : adj[u]) {
        if (!usedEdge[eid]) {
            usedEdge[eid] = true;
            current.pb(v);
            dfs(v, depth+1);
            current.pop_back();
            usedEdge[eid] = false;
        }
    }
}

// Solve Function
void solve() {
    // build graph
    adj.assign(6, vector<pair<int,int>>());  // 1–5 used; ignore 0
    int eid = 0;
    auto add_edge = [&](int u, int v) {
        adj[u].pb({v, eid});
        adj[v].pb({u, eid});
        eid++;
    };
    add_edge(1,2);
    add_edge(2,3);
    add_edge(3,5);
    add_edge(5,1);
    add_edge(5,4);
    add_edge(4,3);
    add_edge(1,3);
    add_edge(2,5);

    // sort adjacency lists so we always go in increasing‐vertex order
    for (int u = 1; u <= 5; u++) {
        sort(all(adj[u]), [](auto &a, auto &b){
            return a.F < b.F;
        });
    }

    memset(usedEdge, 0, sizeof(usedEdge));
    current.clear();
    results.clear();

    // start at vertex 1
    current.pb(1);
    dfs(1, 0);

    // results are already in lex order because of our sorted DFS
    for (auto &s : results) {
        cout << s << "\n";
    }

    cout << "Total paths: " << results.size() << '\n';
}

// Main
int main() {
    fast_io;
    int t = 1;
    // cin >> t; // Uncomment for multiple test cases
    while (t--) solve();
    return 0;
}