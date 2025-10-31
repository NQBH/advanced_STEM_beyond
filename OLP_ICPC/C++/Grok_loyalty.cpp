#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        long long X;
        cin >> n >> X;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        vector<long long> order;
        long long S = 0;
        long long bonus = 0;
        int pos = 0;                     // first unused element in sorted array

        while (pos < n) {
            // maximal levels one item can cross now
            long long curL = S / X;
            long long max_cross = (S + X - 1) / X - curL;
            if (max_cross == 0) break;   // no item can cross a level any more

            // find smallest p >= max_cross
            auto it = lower_bound(a.begin() + pos, a.end(), max_cross);
            if (it == a.end()) break;
            long long p = *it;
            // swap with position pos to keep array sorted after removal
            swap(a[pos], *it);
            ++pos;

            // compute real crossed levels
            long long newL = (S + p) / X;
            long long cross = newL - curL;
            bonus += p * cross;
            S += p;
            order.push_back(p);
        }

        // append unused items (already sorted)
        for (int i = pos; i < n; ++i)
            order.push_back(a[i]);

        cout << bonus << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << order[i];
        }
        cout << '\n';
    }
    return 0;
}