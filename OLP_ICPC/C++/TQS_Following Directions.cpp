#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s;
        cin >> s;
        ll a = 0, b = 0;
        bool check = false;
        for (auto i : s) {
            if (i == 'L') a -= 1;
            else if (i == 'R') a += 1;
            else if (i == 'U') b++;
            else b--;
            if (a == 1 and b == 1) {
                cout << "YES\n";
                check = true;
                break;
            }
        }
        if (!check) cout << "NO\n";

    }
}
