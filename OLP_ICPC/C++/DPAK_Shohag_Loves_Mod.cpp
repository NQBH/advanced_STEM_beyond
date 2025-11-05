#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
    
        int cnt = 1;
        for (int i = 1; cnt++ <= n; i += 2) {
            cout <<  i << " ";
        }
        cout << endl;
    }
}
