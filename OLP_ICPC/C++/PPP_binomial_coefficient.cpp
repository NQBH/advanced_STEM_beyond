// PPP_binomial_coefficient.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll max = 1e6 + 5;
const ll mod = 1e9 + 7;

ll n;   // The number of calculations
ll a, b;

vector<ll> giai_thua_tu(1e6 + 5), giai_thua_mau(1e6 + 5);

ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute()
{
    giai_thua_tu[0] = 1;
    for (int i = 1; i < 1e6 + 5; ++i)
        giai_thua_tu[i] = giai_thua_tu[i - 1] * i % mod;

    giai_thua_mau[1e6 + 5 - 1] = power(giai_thua_tu[1e6 + 5 - 1], mod - 2);
    for (int i = 1e6 + 5 - 2; i >= 0; --i)
        giai_thua_mau[i] = giai_thua_mau[i + 1] * (i + 1) % mod;
}

ll binomial(ll x, ll y)
{
    if (y < 0 || y > x) return 0;
    return giai_thua_tu[x] * giai_thua_mau[y] % mod * giai_thua_mau[x - y] % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;   // Input the number of calculations

    precompute();

    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        cout << binomial(a, b) << "\n";
    }

    return 0;
}