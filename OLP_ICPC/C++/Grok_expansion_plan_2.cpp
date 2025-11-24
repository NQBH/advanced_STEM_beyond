#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        
        long long cnt4 = 0, cnt8 = 0;
        for (char c : s) {
            if (c == '4') cnt4++;
            else cnt8++;
        }
        
        long long total_steps = cnt4 + cnt8;
        long long max_chebyshev = cnt8 + cnt4;
        long long max_manhattan = 2 * cnt8 + cnt4;
        
        long long ax = abs(x);
        long long ay = abs(y);
        long long cheb = max(ax, ay);
        long long manh = ax + ay;
        
        bool ok = (cheb <= max_chebyshev) && (manh <= max_manhattan);
        
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}