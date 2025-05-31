#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long ppow(long long a, long long b, int mod) {
    if (a == 0 && b == 0) return 1;
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    long long a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            cout << 0 << "\n";
            continue;
        }
        long long d = ppow(b, c, MOD - 1);
        cout << ppow(a, d, MOD) << '\n';
    }
}