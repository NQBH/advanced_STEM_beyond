#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int SUM = 0;
        while (n > 0) {
            SUM += n;
            n /= 2;
        }
        cout << SUM << endl;
    }
}
