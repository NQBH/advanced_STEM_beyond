#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int Hao = 0;
        int cur = n;
        while (cur / 3 > 0) {
            Hao += cur / 3;
            cur = cur / 3 + cur % 3;
        }
        if (cur > 0) Hao += cur / 3;
        cout << Hao << endl;
    }
}
