#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        s = " " + s;
        set<char> ms;
        ms.insert(s[1]);
        ms.insert(s[n]);
        bool ok = false;
        for (int i = 2; i < n; i++) {
            if (ms.find(s[i]) != ms.end()) {
                ok = true;
                break;
            }
            else {
                ms.insert(s[i]);
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}