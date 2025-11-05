#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n; cin >> n;
    ll s = 0;
    while (n--) {
        char a; ll b;
        cin >> a >> b;
        if (a == 'P') s += b;
        else {
            s -= b;
            if (s < 0) {
                cout << "YES" << "\n";
                s = 0;
            }
            else cout << "NO" << "\n";
        }
    }
}