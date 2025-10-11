#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int x;
        set<int> ms; for (int i = 1; i <= n; cin >> x, ms.insert(x), i++);
        cout << ms.size() << endl;
    }
}