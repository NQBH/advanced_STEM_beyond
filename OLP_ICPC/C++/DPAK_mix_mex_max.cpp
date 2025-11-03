#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> b;
        for (int i = 1; i <= n; i++) {
            if (a[i] != -1) b.push_back(a[i]);
        }
        n = b.size();
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) ok = false;
        }
        set<int> ms;
        for (int i = 0; i < n; i++) {
            ms.insert(b[i]);
        }
        if (ms.size() != 1) ok = false;
        if (ms.size() == 0) ok = true; 
        cout << (ok ? "YES" : "NO") << endl;
    }
}