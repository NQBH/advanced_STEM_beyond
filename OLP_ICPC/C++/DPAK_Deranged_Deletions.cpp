#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n + 1, 0), b(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin() + 1, b.end());

        if (b == a) {
            cout << "NO";
        }
        else {
            int first = -1, second = -1;
            for (int i = 1; i <= n && first == -1; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (a[j] < a[i]) {
                        first = a[i];
                        second = a[j];
                        break;
                    }
                }
            }
            cout << "YES" << endl << 2 << endl << first << " " << second;
        }
        cout << endl;
    }
}