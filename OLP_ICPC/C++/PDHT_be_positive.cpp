#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        int neg = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == -1) neg++;
            else if (a[i] == 0) zero++;
        }
        int ans = zero + (neg % 2 == 1 ? 2 : 0);
        cout << ans << "\n";
    }
}
