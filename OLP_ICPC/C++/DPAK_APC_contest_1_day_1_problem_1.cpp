#include <bits/stdc++.h>
using namespace std;

string replaceStr(string &s, const string &pattern, const string &repl) {
    int n = s.size();
    int m = pattern.size();
    string ans = "";
    for (int idx = 0; idx < n; ) {    
        bool match = true;
        if (idx + m <= n) {
            for (int i = 0; i < m; i++) {
                if (s[idx + i] != pattern[i]) {
                    match = false;
                    break;
                }
            }
        }
        else match = false;
        if (match) {
            for (auto c : repl) {
                ans += c;
            }
            idx += m;
        }
        else {
            ans += s[idx];
            idx++;
        }
    }
    return ans;
}
signed main() {
    const string oldLong = "Google Developer Student Club";
    const string newLong = "Applied Programming Club";
    const string oldShort = "GDSC";
    const string newShort = "APC";
    int n; cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        s = replaceStr(s, oldLong, newLong);
        s = replaceStr(s, oldShort, newShort);
        cout << s << endl;
    }
}