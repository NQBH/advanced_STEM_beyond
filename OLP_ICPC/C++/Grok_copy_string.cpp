#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    
    while (T--) {
        int n, kmax;
        cin >> n >> kmax;
        string s, t;
        cin >> s >> t;
        
        if (s == t) {
            cout << "0\n";
            continue;
        }
        
        // Check necessary condition: first differing position
        bool possible = true;
        int first_diff = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                if (first_diff == -1) first_diff = i;
                for (int j = 0; j < i; ++j) {
                    if (s[j] != t[j]) {
                        possible = false;
                        break;
                    }
                }
                if (!possible) break;
            }
        }
        if (!possible) {
            cout << "-1\n";
            continue;
        }
        
        // Backward construction
        vector<string> path;
        string cur = t;
        path.push_back(cur);
        
        while (cur != s && (int)path.size() <= kmax) {
            string prev(n, ' ');
            prev[0] = cur[0];
            
            for (int i = 1; i < n; ++i) {
                if (s[i] == cur[i]) {
                    prev[i] = cur[i];
                } else if (s[i] == cur[i - 1]) {
                    prev[i] = cur[i - 1];
                } else {
                    prev[i] = cur[i]; // must keep
                }
            }
            
            cur = prev;
            path.push_back(cur);
        }
        
        if (cur != s || (int)path.size() - 1 > kmax) {
            cout << "-1\n";
        } else {
            int k = path.size() - 1;
            cout << k << '\n';
            for (int i = 1; i <= k; ++i) {
                cout << path[i] << '\n';
            }
        }
    }
    return 0;
}
// WA CF