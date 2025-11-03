#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        s = " " + s;
        int n = s.size() - 1;
        vector<char> a;
        vector<char> b;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'T') {
                a.push_back('T');
            }
            else {
                b.push_back(s[i]);
            }
        }
        for (auto c : a) {
            cout << c;
        }
        for (auto c : b) {
            cout << c;
        }
        cout << endl;
    }
}