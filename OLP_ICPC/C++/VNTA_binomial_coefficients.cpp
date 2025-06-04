#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

long long f[MAXN], inv_f[MAXN];

long long ppow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 != 0) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

void prep() {
    f[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        f[i] = (f[i - 1] * i) % MOD;
    }
    inv_f[MAXN - 1] = ppow(f[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv_f[i] = (inv_f[i + 1] * (i + 1)) % MOD;
    }
}

long long aCb(int a, int b) {
    return (f[a] * ((inv_f[b] * inv_f[a - b]) % MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    prep();
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << aCb(a, b) << "\n";
    }
}