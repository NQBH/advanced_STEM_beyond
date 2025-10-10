#include <bits/stdc++.h>
#define int long long
using namespace std;

int C(int k) {
    return k * (k - 1) / 2;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int a, b, k; cin >> a >> b >> k;
        vector<int> boy(k + 1), girl(k + 1);
        for (int i = 1; i <= k; i++) {
            cin >> boy[i];
        }
        for (int i = 1; i <= k; i++) {
            cin >> girl[i];
        }
        map<int, int> mb, mg;
        mb[boy[1]]++, mg[girl[1]]++;
        int ans = 0;
        for (int i = 2; i <= k; i++) {
            int group = i - 1;
            group -= mb[boy[i]];
            group -= mg[girl[i]];
            ans += group;
            mb[boy[i]]++;
            mg[girl[i]]++;
        }
        cout << ans << endl;
    }
}