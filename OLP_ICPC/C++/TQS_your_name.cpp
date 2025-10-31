#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        map<char, ll> A, B;
        char a[n], b[n];
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            A[a[i]]++;
        }
        for (ll i = 0; i < n; ++i) {
            cin >> b[i];
            B[b[i]]++;
        }
        bool check = true;
        for (auto i = A.begin(); i != A.end(); ++i) {
            if ((*i).second == B[(*i).first]) continue;
            else {
                check = false;
                break;
            }
        }
        if (check) {
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n";
    }
}
