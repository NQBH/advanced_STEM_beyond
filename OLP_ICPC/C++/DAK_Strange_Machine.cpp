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
int n, q, x;
string s;
void solve()
{
    cin >> n >> q;
    cin >> s;
    int ans;
    bool checkB = false;
    for (int i = 0; i < s.size(); i++) if (s[i] == 'B') {checkB = true; break;}
    for (int i = 1; i <= q; i++) {
        cin >> x;
        ans = 0;
        if (checkB == false) ans = x;
        else {
            int j = 0;
            while (x > 0)
            {
                ans++;
                //cout << n <<" "<< j<<endl;
                if (s[j] == 'A') x--;
                else x /= 2;
                if (j == n - 1) j = 0; else j++;
            }
        }
        cout << ans << endl;
    }

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
