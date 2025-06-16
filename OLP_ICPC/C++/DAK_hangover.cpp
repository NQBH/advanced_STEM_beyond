#include <bits/stdc++.h>
using namespace std;
/*
(\_/)
( * *)
 / ?? <3
*/
void IOfile();
int n;
float x;
void solve() {
    int r = 300, l = 0;
    while ((r - l) > 1) {
        int g = (l + r) / 2;
        float s = 0;
        for (int i = 2; i <= g; i++)
            s += (1 / float(i));
        if (s < x) l = g;
        else r = g;
    }
    if (l > 0) cout << l << " card(s)" << endl;
}

int main() {
    //IOfile();
    while (cin >> x)
        solve();
    return 0;
}

void IOfile() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}