#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        long long a;
        cin >> n >> a;
        vector<long long> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        
        vector<long long> cand;
        cand.push_back(v[0]);
        for (int i = 0; i + 1 < n; ++i)
            if (v[i] != v[i + 1])
                cand.push_back(v[i] + v[i + 1]);        // *2 later
        cand.push_back(v.back());
        
        long long best = 0;
        long long ans_b = (a > 0 ? a - 1 : 0LL);           // safe default
        
        for (auto x : cand) {
            long long mid_num = x;                        // numerator, will divide by 2
            // count v < mid_num/2
            auto itL = lower_bound(v.begin(), v.end(), (mid_num + 1) / 2);
            // lower_bound gives first >= (mid_num+1)/2
            // because of integer division this is first >= ceil(mid/2)
            // we need strict < mid/2, therefore:
            long long cntL = itL - v.begin();
            if (mid_num % 2 == 1) {                       // mid = k+0.5
                // v == (mid_num-1)/2  are still < mid
                long long eq = upper_bound(itL, v.end(), (mid_num - 1) / 2) - itL;
                cntL += eq;
            }
            // count v > mid_num/2
            auto itR = upper_bound(v.begin(), v.end(), mid_num / 2);
            long long cntR = v.end() - itR;
            if (mid_num % 2 == 1) {                       // mid = k+0.5
                // v == (mid_num+1)/2  are still > mid
                long long eq = upper_bound(itR, v.end(), (mid_num + 1) / 2) - itR;
                cntR += eq;
            }
            
            // try border <= a
            if (cntL > best) {
                best = cntL;
                ans_b = (a > 0 ? a - 1 : 0LL);
            }
            // try border > a
            if (cntR > best) {
                best = cntR;
                ans_b = a + 1;
            }
        }
        cout << ans_b << '\n';
    }
    return 0;
}