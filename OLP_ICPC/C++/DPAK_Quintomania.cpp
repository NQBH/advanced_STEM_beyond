
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
	int t; cin >> t;
	while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        bool check = true;
        for (int i = 2; i <= n; i++) {
            int val = a[i] - a[i - 1];
            val = abs(val);
            if (val != 5 && val != 7) {
                check = false;
                break;
            }
        }
        cout << (check ? "YES" : "NO") << endl;
	}
}
