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
int a[200200];
bool kt[200200];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int M = 0;
    for (int i = n; i > 0; i--) {
        M = max(M, a[i]);
        if (M > 0) kt[i] = true;
        else kt[i] = false;
        M--;
    }
    for (int i = 1; i <= n; i++) cout << kt[i] << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
