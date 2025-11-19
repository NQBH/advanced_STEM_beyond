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
void solve()
{
    cin >> n;
    cin >> s;
    int p = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) if (s[i] == '1') {p = i; break;}
    for (int i = p + 1; i < n; i++) if (s[i] != s[i - 1]) cnt++;
    //cout << "cnt: ";
    cout << cnt << endl;
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
/*
1010
3-> 1001
4-> 1000
1-> 0111
->3
10101
1-> 01010
2-> 00101
4-> 00110
5-> 00001
->4
010101
giong ben tren
0101010
101010
1-> 010101
2-> 001010
3-> 000101
5-> 000110
6-> 000001
->5
1010101
1->0101010
2->0010101
3->0001010
4->0000101
6->0000110
7->0000001
->6
1101 (chuan hoa) 101
1 -> 0010
3 -> 0001
*/
