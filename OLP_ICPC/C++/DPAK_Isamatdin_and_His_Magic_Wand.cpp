#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        bool odd = false, even = false;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) even = true;
            else odd = true;
        }
        if (even == false || odd == false) {
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
        }
        else {
            sort(a.begin() + 1, a.end());
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
}
