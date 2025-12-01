#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool can_match(ll q, ll r, ll k) {
    if (q == 0) return r >= 1 && r < k;
    if (r >= k) return false;
    ll max_y = (k - r) / q;
    return max_y > r && max_y >= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        
        vector<ll> Q(n), R(n);
        unordered_map<ll, int> freqQ, freqR;
        
        for (int i = 0; i < n; i++) {
            cin >> Q[i];
            freqQ[Q[i]]++;
        }
        
        for (int i = 0; i < n; i++) {
            cin >> R[i];
            freqR[R[i]]++;
        }
        
        int answer = 0;
        
        // Create sorted lists for greedy matching
        vector<pair<ll, int>> q_list, r_list;
        for (auto& p : freqQ) q_list.emplace_back(p);
        for (auto& p : freqR) r_list.emplace_back(p);
        
        sort(q_list.begin(), q_list.end());
        sort(r_list.begin(), r_list.end());
        
        vector<int> q_remain(q_list.size());
        vector<int> r_remain(r_list.size());
        for (int i = 0; i < q_list.size(); i++) q_remain[i] = q_list[i].second;
        for (int i = 0; i < r_list.size(); i++) r_remain[i] = r_list[i].second;
        
        // Greedy: match from smallest q values first
        for (int i = 0; i < q_list.size(); i++) {
            for (int j = 0; j < r_list.size(); j++) {
                if (q_remain[i] == 0 || r_remain[j] == 0) continue;
                
                if (can_match(q_list[i].first, r_list[j].first, k)) {
                    int matches = min(q_remain[i], r_remain[j]);
                    answer += matches;
                    q_remain[i] -= matches;
                    r_remain[j] -= matches;
                }
            }
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}