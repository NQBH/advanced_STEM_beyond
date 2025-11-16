#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*  For a fixed divisor d we have to add exactly one edge of cost d
    inside every maximal contiguous block where every p_i is divisible by d.
    The total cost is the sum of d * (number of such blocks) over all d.
    We enumerate only the divisors that appear in the array (at most ~2·10^7
    divisor occurrences, which is safe for the 1 s limit).                 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    // collect every divisor of every a[i]
    map<int, pair<int, int>> info;   // d -> (positions divisible by d, number of blocks)
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        vector<int> divs;
        for (int d = 1; d * d <= x; ++d) {
            if (x % d == 0) {
                divs.push_back(d);
                if (d != x / d) divs.push_back(x / d);
            }
        }
        for (int d : divs) {
            auto &[cnt, blk] = info[d];
            ++cnt;
            if (i == 0 || a[i - 1] % d != 0) ++blk;   // new block starts
        }
    }
    
    ll answer = 0;
    for (auto &[d, pr] : info) {
        int cnt = pr.first, blk = pr.second;
        if (cnt >= 2)                     // at least one edge possible
            answer += ll(d) * (cnt - blk); // one edge per block
    }
    cout << answer << '\n';
    return 0;
}
// WA test 1 CF