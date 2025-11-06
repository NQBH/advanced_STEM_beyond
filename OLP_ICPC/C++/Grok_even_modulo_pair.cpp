#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        vector<int> v(n);
        map<int, vector<int>> pos;           // v2 -> list of indices
        for (int i = 0; i < n; ++i) {
            long long x = a[i];
            int cnt = 0;
            while (x % 2 == 0) { ++cnt; x /= 2; }
            v[i] = cnt;
            pos[cnt].push_back(i);
        }
        
        int bestV = -1;
        size_t bestCnt = 0;
        for (auto& p : pos) {
            if (p.second.size() > bestCnt) {
                bestCnt = p.second.size();
                bestV = p.first;
            }
        }
        
        if (bestCnt < 2) {
            cout << "-1\n";
            continue;
        }
        
        auto& idx = pos[bestV];
        cout << a[idx[0]] << ' ' << a[idx[1]] << '\n';
    }
    return 0;
}