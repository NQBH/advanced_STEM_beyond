#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,x,y;
        cin >> n >> x >> y;
        if (n % min(x,y))
        {
            cout << (long long)(ceil(n/min(x,y))+1)<< "\n";
        }
        else cout << (long long)((n/min(x,y))) << "\n";
    }
}

