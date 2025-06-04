#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;
ll pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll x) {
    return pow(x, mod - 2);
}
ll fac(ll x) {
    ll res = 1;
    for (int i = 1; i <= x; i++) {
        res = (res * i) % mod;
    }
    return res;
}
int main() {
    string s; cin >> s;
    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }
    ll ans = fac(s.size());
    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            ans = (ans * inv(fac(count[i]))) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}