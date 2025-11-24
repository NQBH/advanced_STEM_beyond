#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<array<int,3>> cons; // c,l,r
        cons.reserve(q);
        for (int i = 0; i < q; i++) {
            int c, l, r;
            cin >> c >> l >> r;
            cons.push_back({c, l, r});
        }

        vector<long long> a(n+1);
        // Base pattern: cycle 0..k
        for (int i = 1; i <= n; i++)
            a[i] = i % (k+1);

        // Handle min = k constraints (type 1)
        for (auto &tup : cons) {
            int c = tup[0], l = tup[1], r = tup[2];
            if (c == 1) {
                // must have min = k in [l,r]
                a[l] = k;
                for (int i = l+1; i <= r; i++)
                    if (a[i] < k) a[i] = k+1;
            }
        }

        // Handle MEX = k constraints (type 2)
        for (auto &tup : cons) {
            int c = tup[0], l = tup[1], r = tup[2];
            if (c == 2) {
                // need 0..k-1 inside [l,r]
                for (int i = 0; i < k && l+i <= r; i++)
                    a[l+i] = i;

                // rest cannot contain k → set to k+1
                int start = l + k;
                for (int i = start; i <= r; i++)
                    a[i] = k+1;
            }
        }

        // Output the array
        for (int i = 1; i <= n; i++) {
            cout << a[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
