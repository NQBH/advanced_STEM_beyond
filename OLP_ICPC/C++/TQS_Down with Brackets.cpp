#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        string s; cin >> s;
        ll ans = 0;
        ll dem = 0;
        for (ll i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                ll j = i;
                while (j < s.size() - 1 and dem != 0) {
                    if (s[j] == '(') dem++;
                    else dem--;
                    j++;
                }
                ans++;
                i = j;
            }
            else dem++;
        }
        if (ans >= 2) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
