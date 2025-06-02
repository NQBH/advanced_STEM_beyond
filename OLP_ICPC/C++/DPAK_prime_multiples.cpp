#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int N = 1e6;
const int mod = 1e9 + 7;

signed main() {
    int n, k; cin >> n >> k;
    vector<int> a(k);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        ans += n / a[i];
    }

    int mask = 1 << k;
    for (int i = 0; i < mask; i++) {
        vector<int> temp;
        for (int j = 0; j < k; j++) {
            if ((1 << j)&i) {
                temp.push_back(a[j]);
            }
        }
        if (temp.size() <= 1) {
            continue;
        }
        int temp_n = n;
        for (auto c : temp) {
            temp_n /= c;
        }
        if (temp.size() % 2 == 0) {
            ans -= temp_n;
        }
        else {
            ans += temp_n;
        }
    }
    cout << ans;
    return 0;
}