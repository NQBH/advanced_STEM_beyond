//BFS
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

// Solve Function
void solve() {
    int n, v_s, v_t;
    cin >> n >> v_s >> v_t;
    string line;
    getline(cin, line); // consume newline

    vector<vi> adj(n+1);
    for (int i = 1; i <= n; i++) {
        getline(cin, line);
        istringstream in(line);
        int j;
        while (in >> j) {
            adj[i].pb(j);
        }
    }

    vector<vi> paths;
    queue<vi> q;
    q.push({v_s});

    while (!q.empty()) {
        vi path = q.front(); q.pop();
        int u = path.back();
        if (u == v_t) {
            paths.pb(path);
            continue;
        }
        for (int w : adj[u]) {
            // only extend if w not already in path (simple path)
            if (find(all(path), w) == path.end()) {
                vi next = path;
                next.pb(w);
                q.push(next);
            }
        }
    }

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