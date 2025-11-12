#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct cell {
    int x, y;
};

bool corner(cell a, int n, int m) {
    return a.x == 1 && a.y == 1 || a.x == 1 && a.y == m || a.x == n && a.y == 1 || a.x == n && a.y == m;
}
signed main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        cell a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        if (corner(a,n, m) || corner(b,n,m)) {
            cout << 2 << endl; continue;
        }
        if (a.x == 1 || a.x == n || a.y == 1 || a.y == m || b.x == 1 || b.x == n || b.y == 1 || b.y == m) {
            cout << 3 << endl; continue;
        }
        cout << 4 << endl;
    
    }
}
