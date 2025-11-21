#include <bits/stdc++.h>
using namespace std;
#define ll long long
double solve(double n)
{
    if (n==1) return 1;
    return 1/n + solve(n-1);
}
int main()
{
    ll n; cin >> n;
    double ans = solve(n);
    cout << ans;
}
