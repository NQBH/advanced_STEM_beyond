#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define el "\n";
#define elif else if
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pops pop_back
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define cel cout << "\n";
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> link(n + 1);
    vector<bool> visited(n + 1, 0);
    visited[1] = 1;
    queue<int> q;
    q.push(1);
    wh(m) {
        cin >> x >> y;
        link[x].pb(y);
        link[y].pb(x);
    }
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        for (auto i : link[temp]) {
            if (!visited[i]) {q.push(i); visited[i] = 1;}
        }
    }
    bool check = 0;
    frs(i, 1, visited.size()) { // visited.size() = n + 1
        if (!visited[i]) {check = 1; cout << i << el}
    }
    if (!check) {cout << 0;}
}

SORAI {
    Sanic_speed
    int t = 1; //cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
