#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> constraints(n + 1, vector<int>());
        
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            if (l < r) {
                constraints[l].push_back(r - 1);
            }
        }
        
        // Use difference array approach for XOR constraints
        vector<int> parity(n + 1, 0);
        
        for (int i = 1; i <= n - 1; i++) {
            for (int r : constraints[i]) {
                parity[i]++;
                if (r + 1 <= n - 1) {
                    parity[r + 1]--;
                }
            }
        }
        
        // Compute prefix XOR requirements
        vector<int> required_xor(n, 0);
        int current = 0;
        for (int i = 1; i <= n - 1; i++) {
            current += parity[i];
            required_xor[i] = current % 2;
        }
        
        // Count positions where we have freedom
        int free_positions = 0;
        bool consistent = true;
        
        for (int i = 1; i <= n - 1; i++) {
            if (required_xor[i] == 0) {
                free_positions++; // t[i] can be 0 or 1
            }
        }
        
        // Total ways: 2^(number of free positions) * 2^(choice for s[1])
        long long answer = 1LL << free_positions;
        answer = answer * 2 % MOD;
        
        cout << answer << "\n";
    }
    
    return 0;
}