#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        bool inf = false;
        for (int i = 0; i < s.size() - 1; ++i)
            if (s[i] != '<' && s[i + 1] != '>') {
                inf = true;
                break;
            }
        if (inf) cout << "-1\n";
        else {
            int nl = 0, nr = 0;
            for (int i = 0; i < s.size(); ++i)
                if (s[i] == '<') ++nl;
                else if (s[i] == '>') ++nr;
            cout << s.size() - min(nl, nr) << '\n';
        }
    }
}