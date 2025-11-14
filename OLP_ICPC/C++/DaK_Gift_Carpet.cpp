#include <bits/stdc++.h>
using namespace std;
/*
(\_/)          (\___/)
( " ")         ( ^ ^  )
 /  >> <3      he(#)(#)
/   ??         (") (")
bruth lmeo lmeo
*/
void IOfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("b.inp", "r", stdin);
    freopen("b.out", "w", stdout);
}
int n, m;
string s[23];
void solve() {
    cin >> n >> m;
    int vika = 0;
    cin.ignore();
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
        {
            if (vika == 0 && s[j][i] == 'v') {vika++; break;}
            if (vika == 1 && s[j][i] == 'i') {vika++; break;}
            if (vika == 2 && s[j][i] == 'k') {vika++; break;}
            if (vika == 3 && s[j][i] == 'a') {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}
int main()
{
    //IOfile();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
