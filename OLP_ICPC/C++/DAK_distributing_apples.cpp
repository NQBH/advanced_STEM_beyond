#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int Pow(int a, int b) {
    if (b == 0) return 1;
    ll u = Pow(a, b / 2);
    u = u * u % MOD;
    if (b % 2 == 1) u = u * a % MOD;
    return u;
}
int n, m;
int inv(int x)
{
    return Pow(x, MOD - 2);
}
ll fact[2000200];

int nCr(int a, int b)
{
    return fact[a] * inv(fact[b] * fact[a - b] % MOD) % MOD;
}
int main() {
    //freopen("b.inp","r",stdin);
    //freopen("b.out","w",stdout);
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++)
        fact[i] = fact[i - 1] * i % MOD;

    cin >> n >> m;
    cout << nCr(n + m - 1, m);
}