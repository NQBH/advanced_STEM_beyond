#include <bits/stdc++.h>
using namespace std;

int n;
int a[100100];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {

        if (a[i] > a[i - 1]) cnt++;
        if (a[i] == a[i - 1]) {a[i] += 1; cnt++;}
        if (a[i] < a[i - 1]) a[i] = a[i - 1];
    }
    cout << cnt << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
