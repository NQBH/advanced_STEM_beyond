#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        vector<tuple<long long, long long, int>> monsters; // (b, c, idx)
        for (int j = 0; j < m; ++j) {
            long long b, c;
            cin >> b;
            monsters.emplace_back(b, 0LL, j);
        }
        for (int j = 0; j < m; ++j) {
            long long c;
            cin >> c;
            get<1>(monsters[j]) = c;
        }
        
        // sort swords
        sort(a.begin(), a.end());
        
        // sort monsters by b ascending
        sort(monsters.begin(), monsters.end());
        
        multiset<long long> S(a.begin(), a.end());
        int ans = 0;
        
        for (auto& [b, c, idx] : monsters) {
            auto it = S.lower_bound(b);
            if (it == S.end()) continue; // cannot kill
            
            long long x = *it;
            S.erase(it);
            ++ans;
            
            if (c > 0) {
                long long newDmg = max(x, c);
                S.insert(newDmg);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}
// WA CF