#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

    int n, k; cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    set<int> s;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    int num = 1;
    for (int floor = n; floor >= 1; floor--) {
        for (int i = 1; i <= n - floor + 1; i++) {
            a[floor][i] = num++;
            if (s.find(a[floor][i]) != s.end()) {
                a[floor][i] = 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) cout << 0 << " ";
            else cout << "(" <<i <<"," <<j<<")" << " ";
        }
        cout << endl;
    }
}