#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        map<char, int> ma;
        for (int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
        }

        int max_freq = -1, min_freq = 100;
        char max_c_freq, min_c_freq;
        for (auto it : ma) {
            if (it.second < min_freq) {
                min_freq = it.second;
                min_c_freq = it.first;
            }
            if (it.second > max_freq) {
                max_freq = it.second;
                max_c_freq = it.first;
            }
        }
        if (max_c_freq != min_c_freq)
            for (auto &i : s) {
                if (i == min_c_freq) {
                    i = max_c_freq;
                    break;
                }
            }
        else {
            for (auto i = 1; i < n; i++) {
                if (s[i] == max_c_freq && s[i - 1] != s[i]) {
                    s[i - 1] = s[i];
                    break;
                }
                else if (s[i - 1] == max_c_freq && s[i] != s[i - 1]) {
                    s[i] = s[i - 1];
                    break;
                }
            }
        }
        cout << s << endl;

    }
    return 0;
}