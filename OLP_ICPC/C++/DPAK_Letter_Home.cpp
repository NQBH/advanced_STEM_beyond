#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, start;
        cin >> n >> start;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        int ans = 0;
        if (start >= a[n]) {
            ans = start - a[1];
        }
        else if (start <= a[1]) {
            ans = a[n] - start;
        }
        else {
            int left = 0, right = 0;
            int cntLeft = 0, cntRight = 0;
            for (int i = start; i <= a[n]; i++) {
                cntLeft++;
            }
            for (int i = a[n]; i >= a[1]; i--) {
                cntLeft++;
            }
            for (int i = start; i >= a[1]; i--) {
                cntRight++;
            }
            for (int i = a[1]; i <= a[n]; i++) {
                cntRight++;
            }
            ans = min(cntLeft, cntRight) - 2;
        }
        cout << ans << endl;

    }
}