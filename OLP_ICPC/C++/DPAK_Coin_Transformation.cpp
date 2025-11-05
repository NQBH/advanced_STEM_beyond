#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int val = 0;
        int coin = 1;
        while (n > 0) {
            if (n / 4 > 0) {
                coin = coin * 2;
                n /= 4;
            }
            else break;
        }
        cout << coin << endl;
    }
    return 0;
}