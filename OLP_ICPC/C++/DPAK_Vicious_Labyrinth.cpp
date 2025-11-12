#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main(){
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (n == 2) {
            cout << "2 1" << endl;
            continue;
        }
        vector<int> ans(n + 1);
        ans[n] = n - 1;
        ans[n - 1] = n;
        for (int i = 1; i < n - 1; i++) {
            ans[i] = (k % 2 != 0 ? n : n - 1);
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}