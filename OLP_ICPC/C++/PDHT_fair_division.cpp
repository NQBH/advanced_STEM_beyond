#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 1) cnt1++;
            else cnt2++;
        }
        int sum = cnt1 + 2 * cnt2;
        if (sum % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        if ((sum / 2) % 2 == 1 && cnt1 == 0) cout << "NO\n";
        else cout << "YES\n";
    }
}
