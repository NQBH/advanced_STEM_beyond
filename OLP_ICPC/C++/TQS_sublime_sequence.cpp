#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q; cin >> q;
    while (q--) {
        int x, n; cin >> x >> n;
        if (n & 1) cout << x << "\n";
        else cout << 0 << "\n";
    }
}
