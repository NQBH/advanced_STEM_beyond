#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        long long n, C, D;
        cin >> n >> C >> D;
        vector<long long> a(n), b(n);
        long long max_a = LLONG_MIN, max_b = LLONG_MIN;
        long long min_d = LLONG_MAX, max_d = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            max_a = max(max_a, a[i]);
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            max_b = max(max_b, b[i]);
            long long d = b[i] - a[i];
            min_d = min(min_d, d);
            max_d = max(max_d, d);
        }
        
        long long low_d_val = max_d - D;
        long long high_d_val = min_d + C;
        if (low_d_val > high_d_val) {
            cout << -1 << '\n';
            continue;
        }
        
        long low_a_val = max_a - C;
        long long low_b_val = max_b - D;
        long long diff_switch = low_b_val - low_a_val;
        long long diff_opt = max(low_d_val, min(high_d_val, diff_switch));
        
        long long L_min = max(static_cast<long long int>(low_a_val), low_b_val - diff_opt);
        
        long long cost = 0;
        for (int i = 0; i < n; ++i) {
            long long m_i = min(a[i], b[i] - diff_opt);
            cost += max(0LL, L_min - m_i);
        }
        
        cout << cost << '\n';
    }
    return 0;
}