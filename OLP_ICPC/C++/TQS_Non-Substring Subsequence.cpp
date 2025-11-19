#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, r, l, n, q;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> q >> s;
        while (q--)
        {
            cin >> l >> r;
            cout << (( (s.find(s[l - 1]) < l - 1) || (s.rfind(s[r - 1]) > r - 1) ) ? "YES\n" : "NO\n");
        }
    }
}
