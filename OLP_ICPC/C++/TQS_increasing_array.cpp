#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main()
{
    cin >> n;
    ll a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll k = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            k += (a[i] - a[i + 1]);
            a[i + 1] = a[i + 1] + (a[i] - a[i + 1]);
        }
    }
    cout << k;
}