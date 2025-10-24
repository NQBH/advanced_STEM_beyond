#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e16;

signed main() {
    int t; cin >> t;
 
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        if (a > b) swap(a, b);
        int op = 0;
        while (a < b) {
            a += c;
            b -= c;
            op++;
        }
        cout <<op<<endl;
    }
}