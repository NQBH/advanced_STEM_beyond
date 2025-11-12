#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll b = n * (n - 1) / 2;
        ll i = n - 1;
        if (k >= n - 1) n = 1;
        else
        {
            while (b > 0 and k - i >= 0)
            {
                b -= i;
                k -= i;
                i--;
                n--;
            }
        }
        cout << n << "\n";
    }
}
