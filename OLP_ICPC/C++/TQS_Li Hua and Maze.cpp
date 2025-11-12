#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        bool a = (x1 == 1 || x1 == n) && (y1 == 1 || y1 == m);
        bool b = (x2 == 1 || x2 == n) && (y2 == 1 || y2 == m);

        bool c = (x1 == 1 || x1 == n || y1 == 1 || y1 == m);
        bool d = (x2 == 1 || x2 == n || y2 == 1 || y2 == m);

        if (a || b)
        {
            cout << 2 << "\n";
        }
        else if (c || d)
        {
            cout << 3 << "\n";
        }
        else
        {
            cout << 4 << "\n";
        }
    }
    return 0;
}
