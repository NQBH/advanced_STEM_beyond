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
int n;
string s;
void solve() {
    cin >> n;
    cin >> s;
    int i = 1;
    s += "**";
    int coin = 0;
    while (i <= n)
    {
        //i++;
        if (s[i] == '.') i++;
        if (s[i] == '*') {
            i++;
            if (s[i] == '*') break;
        }
        if (s[i] == '@') {coin++; i++;}
    }
    cout << coin << endl;
}
int main()
{
    //IOfile();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
