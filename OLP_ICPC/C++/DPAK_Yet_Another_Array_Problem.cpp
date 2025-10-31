#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<bool> isPrime(1e3 + 5, true);
vector<int> prime;
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 1e3; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 1e3; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= 1e3; i++) {
        if (isPrime[i]) prime.push_back(i);
    }
}
signed main() {
    sieve();
//    cout << prime.size();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        cin >> a[1];
//        int GCD = a[1];

        bool odd = false, even = false;
        if (a[1] % 2 == 1) odd = true;
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) even = true;
            else odd = true;
        }
        if (odd == true) {
            cout << 2;
        }
        else {
            int ans = -1;
            for (auto p : prime) {
                bool check = true;
                for (int i = 1; i <= n; i++) {
                    if (a[i] % p != 0) {
                        check = false;
                        break;
                    }
                }
                if (check == false) {
                    ans = p;
                    break;
                }
            }
            cout << ans;
        }
        cout << endl;
    }
}
