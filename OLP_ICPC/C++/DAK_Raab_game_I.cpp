#include <bits/stdc++.h>
using namespace std;
/*
(\_/)
( * *)
 / ?? <3
*/
void IOfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("b.inp", "r", stdin);
    freopen("b.out", "w", stdout);
}
int n, a, b;
int solve()
{
    cin >> n >> a >> b;
    //n=1
    vector <int> ans1;
    vector <int> ans2;
    if (n == 1)
    {
        if (a + b == 0) {
            cout << "YES" << '\n';
            cout << 1 << '\n' << 1 << '\n';
            return 0;
        }
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    //n=2
    if (n == 2)
    {
        if (a + b == 1 || a == 2 || b == 2) {
            cout << "NO" << '\n';
            return 0;
        }
        else {
            cout << "YES" << '\n';
            if (a == 0 && b == 0) {
                cout << 1 << " " << 2 << '\n';
                cout << 1 << " " << 2 << '\n';
                return 0;
            }
            else {
                cout << 2 << " " << 1 << '\n';
                cout << 1 << " " << 2 << '\n';
                return 0;
            }
        }

    }

    if (a + b > n) {
        cout << "NO" << '\n';
        return 0;
    }
    if (a == 0 && b == 0) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) cout << i << " "; cout << '\n';
        for (int i = 1; i <= n; i++) cout << i << " "; cout << '\n';
        return 0;
    }
    if (a + b == n)
    {
        if (a == 0 || b == 0) {
            cout << "NO" << '\n';
            return 0;
        }
        else {
            cout << "YES" << '\n';
            {

                for (int i = 1; i <= n; i++) {
                    int a2 = i + a;
                    if (a2 > n) a2 -= n;
                    ans1.push_back(i);
                    ans2.push_back(a2);
                }
                for (int x : ans1) cout << x << " ";
                cout << '\n';
                for (int x : ans2) cout << x << " ";
                cout << '\n';
            }
            return 0;
        }
    }
    if (a == 0 || b == 0) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    int s = a + b;
    for (int i = 1; i <= s; i++) {
        int a2 = i + a;
        if (a2 > s) a2 -= s;
        ans1.push_back(i);
        ans2.push_back(a2);
    }
    for (int i = s + 1; i <= n; i++)
    {
        ans1.push_back(i);
        ans2.push_back(i);
    }
    for (int x : ans1) cout << x << " ";
    cout << '\n';
    for (int x : ans2) cout << x << " ";
    cout << '\n';
    return 0;
}
int main()
{
    //IOfile();
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}