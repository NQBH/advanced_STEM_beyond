#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, v; cin >> n >> v;
    if (v + 1 >= n) {
        cout << n - 1;
    }
    else {
        int ans = v;
        for (int i = 2; i <= n - v; i++) ans += i;
        cout << ans;
    }    
}