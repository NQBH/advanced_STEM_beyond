#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        vector<int> odd;
        int SUM = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 1) {
                odd.push_back(a[i]);
            }
            else SUM += a[i];
        }
        if (odd.empty()) {
            cout << 0 << endl;
            continue;
        }
        if (odd.size() == 1) {
            cout << SUM + odd[0] << endl;
            continue;
        }
        sort(odd.begin(), odd.end());
        for (int i = odd.size() / 2; i < odd.size(); i++) {
            SUM += odd[i];
        }
        cout << SUM << endl;
        /*
        O  O  O  O  O
        X  X  O  O  O
        */
    }
}