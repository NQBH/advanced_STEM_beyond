#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        vector<char> s(4);
        cin >> s[1] >> s[2] >> s[3];

        if (s[1] == s[3]) {
            s[2] = '=';
        }
        else if (s[1] < s[3]) {
            s[2] = '<';
        }
        else {
            s[2] = '>';
        }

        cout << s[1] << s[2] << s[3] << endl;
    }
}
