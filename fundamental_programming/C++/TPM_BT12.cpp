#include <bits/stdc++.h>
#include <cmath>
#define int long long
using namespace std;

signed main() {
    int m, n, s = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        s += pow(i, m);
    }
    cout << s;
    return 0;
}