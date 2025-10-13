#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> a(n);
        a[0] = 1;
        int next_unused = 2;
        for (int i = 1; i < n; ++i) {
            ll ans = b[i] - b[i - 1];
            if (ans > i)
                a[i] = next_unused++;
            else
                a[i] = a[i - ans];
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << '\n';
    }
    return 0;
}