#include <bits/stdc++.h>
using namespace std;
#define ll long long
void f(ll n)
{
    if (n != 0) {
        string a;
        cin >> a;
        f(n - 1);
        cout << a.find('#') + 1 << " ";
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        f(n);
        cout << "\n";
    }
}
