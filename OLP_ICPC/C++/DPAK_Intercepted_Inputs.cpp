
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        vector<int>a(k + 1);
        int gridCube = k - 2;
        map<int,int> ma;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            ma[a[i]]++;
        }
        int n = -1, m = -1;
        for (int i = 1; i <= k && n == -1; i++) {
            if (gridCube % a[i] == 0) {
                int val = gridCube / a[i];
                if (val == a[i]) {
                    if (ma[val] > 1) {
                        n = m = val;
                    }
                }
                else {
                   if (ma.find(val) != ma.end()) {
                     n = a[i];
                        m = val;
                    }
                }
            }

        }
        cout << n << " " << m << endl;
    }
}
