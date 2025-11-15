#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        bool inf = false; // has cycle
        for (int i = 0; i < n - 1; ++i) {
            if ((s[i] == '*' && s[i + 1] == '*') || (s[i] == '>' && s[i + 1] == '*') || (s[i] == '*' && s[i + 1] == '<') || (s[i] == '>' && s[i + 1] == '<')) {
                inf = true;
                break;
            }
        }
        if (inf) {
            cout << "-1\n";
            continue;
        } else {
            int n_less = 0, n_more = 0;
            for (int i = 0; i < n; ++i)
                if (s[i] == '<') ++n_less;
                else if (s[i] == '>') ++n_more;
                else {
                    ++n_less;
                    ++n_more;
                }
            cout << max(n_less, n_more) << '\n';
        }
    }
}