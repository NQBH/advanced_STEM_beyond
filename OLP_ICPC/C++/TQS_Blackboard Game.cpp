#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        if (n % 4 == 0) cout << "Bob\n";
        else cout << "Alice\n";
    }
}
