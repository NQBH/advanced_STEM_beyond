#include <bits/stdc++.h>
#define int long long
using namespace std;

int C(int n) {
    if (n < 0) return 0;
    return n * (n - 1) / 2;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        
        int pos = -1, neg = -1;
        for (int i = 1; i <= n; i++) {
            int curPossi = C(i);
            int curNegga = C(n - i);
            if (curPossi + curNegga == k) {
                pos = i;
                neg = n - i;
                break;
            }
        }
        if (pos == -1) {
            cout << "NO";
        }
        else {
            cout << "YES" << endl;
            for (int i = 1; i <= pos; i++) {
                cout << 1 << " ";
            }
            for (int i = 1; i <= neg; i++) {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
}
