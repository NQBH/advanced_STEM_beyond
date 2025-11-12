#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    int t = 1; //cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        vector<int> first(n + 1), second(n + 1);
        for (int i = 1; i <= n; i++) cin >> first[i];
        for (int i = 1; i <= n; i++) cin >> second[i];
        if (first[1] == 0) {
            cout << "NO" << endl; continue;
        }
        bool check = false;
        if (first[s] == 1) {
            check = true;
        }
        for (int i = s; i <= n; i++) {
            if (first[i] == 1 && second[i] == 1 && second[s] == 1) {
                check = true;
                break;
            }
        }
        
        cout << (check ? "YES" : "NO") << endl;
    }
}
