#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int n, q; cin >> n >> q;
    set<int> idx;
    multiset<int> dist;
    vector<int>a(n + 1);
    for (int i = 1 ; i <= n; i++) {
        int x; cin >> x;
        idx.insert(x);
        a[i] = x;
    }
    sort(a.begin() + 1, a.end());
    for (int i = 2; i <= n; i++) {
        dist.insert(a[i] - a[i - 1]);
    }
    if (n == 1) cout << 0 << endl;
    else cout << a[n] - a[1] - *dist.rbegin() << endl;
    while (q--) {
        int t, x; cin >> t >> x;
        if (t == 0) { // remove
            auto it = idx.find(x);
            bool hasL = (it != idx.begin());
            bool hasR = (next(it) != idx.end());
            if (hasL) {
                int L = *prev(it);
                auto dit = dist.find(x - L);
                if (dit != dist.end()) dist.erase(dit);
            }
            if (hasR) {
                int R = *next(it);
                auto dit = dist.find(R - x);
                if (dit != dist.end()) dist.erase(dit);
            }
            if (hasL && hasR) {
                int L = *prev(it), R = *next(it);
                dist.insert(R - L);
            }
            idx.erase(it);
        } else { // add
            auto res = idx.insert(x);
            auto it = res.first;

            bool hasL = (it != idx.begin());
            bool hasR = (next(it) != idx.end());

            if (hasL && hasR) {
                int L = *prev(it), R = *next(it);
                auto dit = dist.find(R - L);
                if (dit != dist.end()) dist.erase(dit);
                dist.insert(x - L);
                dist.insert(R - x);
            } else if (hasL) {
                int L = *prev(it);
                dist.insert(x - L);
            } else if (hasR) {
                int R = *next(it);
                dist.insert(R - x);
            }
        }
        if (idx.size() <= 1) cout << 0 << endl;
        else cout << *idx.rbegin() - *idx.begin() - *dist.rbegin() << endl;
    }
}