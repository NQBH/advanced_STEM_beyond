#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int n; cin >> n;
    vector<int>a(n + 1);
    int SUM = 0;
    int zero = 0, negga = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0)zero++;
        if (a[i] < 0) negga++;
    }
    vector<int> calc;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) SUM += a[i] - 1;
        else if (a[i] < 0) SUM += -1 - a[i];
        else SUM++;
    }
    if (negga % 2 == 1) {
        if (zero == 0)
            SUM += 2;
    }
    cout << SUM;

}
