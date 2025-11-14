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
int main()
{
    //IOfile();
    int t, x; cin >> t;
    int l, r;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            if (x == 1) l = i;
            if (x == n) r = i;
        }
        if (l > r) swap(l, r);
        cout << min({n - l + 1, r, l + n - r + 1}) << endl;
    }
    return 0;
}
