#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<char> s(n + 1);
        for (int i = 1; i <= n; i++) cin >> s[i];
        vector<int> a(q + 1);
        for (int i = 1; i <= q; i++) cin >> a[i];
        int cntA = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'A') cntA++;
        }
        if (cntA == n) {

            for (int i = 1; i <= q; i++) {
                cout << a[i] << endl;
            }
        }
        else {
            for (int i = 1; i <= q; i++) {
                int ops = 0;
                for (int j = 1 ; a[i] > 0 ; j++, j = (j > n) ? 1 : j) {
                    if (s[j] == 'A')  {
                        a[i]--;
                    }
                    else {
                        a[i] /= 2;
                    }
                    ops++;
                }
//               cout << endl;
                cout << ops << endl;
            }
        }
    }
}
