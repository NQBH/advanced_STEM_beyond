#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e16;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
    for (int i = 5; i * i <= n; i+= 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
signed main() {
    int t; cin >> t;
 
    while (t--) {
        int l, r; cin >> l >> r;
        int a = -1, b = -1;
        bool check = false;
        if (r < 4) {
            cout << -1 << endl;
            continue;
        }
        int num = -1;
        for (int i = r; i >= l; i--) {
            if (i % 2 == 0) {
                check = true;
                num = i;
                break;
            }
        }
        if (check == false) {
            if (isPrime(l)) {
                cout << -1;
            }
            else {
                for (int i = 2; i * i <= l; i++) {
                    if (l % i == 0) {
                        cout << i << " " << l - i;
                        break;
                    }
                }
            }
        }
        else {
            cout << num / 2 << " " << num / 2;
        }
        cout << endl;
    }
}