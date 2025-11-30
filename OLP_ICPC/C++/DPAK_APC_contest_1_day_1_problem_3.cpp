#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, k; cin >> n >> k;
    unordered_map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    int distinct = freq.size();
    int extra = 0; 
    for (auto &p : freq) {
        extra += p.second - 1;
    }
    if (k <= extra) cout << distinct;
    else cout << max(0LL, distinct - (k - extra));
    
}
