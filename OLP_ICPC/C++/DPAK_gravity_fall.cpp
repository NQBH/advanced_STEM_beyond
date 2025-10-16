#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<deque<int>> a(n + 1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            for (int j = 1; j <= x; j++) {
                int val; cin >> val;
                a[i].push_back(val);
            }
        }
        deque<int> ans;
        while (a.size() > 1) {
            sort(a.begin() + 1, a.end());
            
            vector<deque<int>> temp(1);
            
            int sz = a[1].size();
            while (a[1].empty() == false) {
                ans.push_back(a[1].front());
                a[1].pop_front();
            }
            
            for (int i = 2; i < a.size(); i++) {
                int curSz = a[i].size();
                for (int j = 0; j < min(curSz, sz); j++) {
                    a[i].pop_front();
                }
            }

            for (int i = 1; i < a.size(); i++) {
                if (a[i].empty() == true) continue;
                temp.push_back(a[i]);
            }
            a = temp;
        }

        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}
