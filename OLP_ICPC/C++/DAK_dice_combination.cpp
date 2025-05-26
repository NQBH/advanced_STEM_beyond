#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
using namespace std;
 
const int MOD = 1e9+7;
 
int f[1000100];
int n;
int dp(int n)
{
    if (f[n]!=0) return f[n];
    for (int i=1;i<=6;i++)
        if (n-i>=0) f[n]=(f[n]+dp(n-i)) % MOD;
    return f[n];
}
int main()
{
    f[0]=1;
    f[1]=1;
    f[2]=2;
    cin >> n;
    cout << dp(n);
    return 0;
}