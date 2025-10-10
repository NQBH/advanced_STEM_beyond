#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool check = false;
        while (n % 2 == 0) n /= 2;
        if (n > 1) check = true;
        if (check) cout << "YES"; else cout << "NO";
        cout << endl;
    }
}