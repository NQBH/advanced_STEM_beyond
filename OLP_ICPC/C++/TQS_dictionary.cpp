#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        string n; cin >> n;
        int ans = (int(n[0]) - 97) * 25 + int(n[1] - 97);
        if (n[1] < n[0]) ans++;
        cout << ans << "\n";
    }
}
