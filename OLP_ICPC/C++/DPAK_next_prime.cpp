#include <bits/stdc++.h>
#define int long long
using namespace std;
int N = 1e6;
const int mod = 1e9 + 7;

bool check(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
    for (int i = 7; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 4) == 0) return false;
    }
    return true;
}

signed main(){
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        for (int i = x + 1; i <= x + 1500; i++) {
            if (check(i)) {
                cout << i << endl;
                break;
            }
        }        
    }
    return 0;
}