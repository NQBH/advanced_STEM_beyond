#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a == b && a == c && a == d) cout <<"YES";
        else cout << "NO";
        cout << endl;
    }
}
