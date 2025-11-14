#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const string pattern = " 2020";
signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;  s = " " + s;
        int range = n - 4;

        bool check = false;
        string temp ;
        for (int firstPick = 0; firstPick <= 4; firstPick++) {
            int secondPick = 4 - firstPick;
            temp.clear();
            for (int i = 1; i <= firstPick; i++) {
                temp += s[i];
            }
            for (int i = n - secondPick + 1; i <= n; i++) {
                temp += s[i];
            }
            if (temp == "2020") {
                check = true;
                break;
            }
        }
        cout << (check ? "YES" : "NO") << endl;

    }
    return 0;
}