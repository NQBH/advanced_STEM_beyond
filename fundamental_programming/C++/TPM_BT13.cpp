#include <bits/stdc++.h>
#include <cmath>
#define int long long
using namespace std;

signed main() {
    int m, n, s = 0, M, i = 1;
    cin >> n >> m >> M;
    while (s <= M) {
        i++;
        if (i <= n) {
            if (s + pow(i, m) <= M) {
                if (s + pow(i, m) == M) {
                    s += pow(i, m);
                    break;
                } else s += pow(i, m);
            } else break;
        } else break;
    }
    cout << s;
    return 0;
}