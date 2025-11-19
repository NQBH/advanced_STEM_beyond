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
string s;
int n;
void solve() {
    cin >> n;
    cin >> s;
    int p = -1, pp;
    for (int i = 0; i < n; i++) if (s[i] != '?') {p = i; break;}
    pp = p;
    if (p == -1) {s += 'R'; pp = n + 1;}
    for (int i = pp - 1; i >= 0; i--) {
        if (s[i] == '?') {
            if (s[i + 1] == 'R') s[i] = 'B';
            else s[i] = 'R';
        }
    }
    for (int i = pp + 1; i < n; i++) {
        if (s[i] == '?') {
            if (s[i - 1] == 'R') s[i] = 'B';
            else s[i] = 'R';
        }
    }
    cout << s.substr(0, n) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
