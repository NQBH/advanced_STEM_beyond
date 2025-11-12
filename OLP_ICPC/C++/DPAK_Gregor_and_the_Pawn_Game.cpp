#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<char> up(n + 1);
        vector<char> down(n + 1);
        vector<bool> final(n + 1, false);

        for (int i = 1; i <= n; i++) cin >> up[i];
        for (int i = 1; i <= n; i++) cin >> down[i];
        for (int i = 1; i <= n; i++) {
            if (down[i] == '1') {
                if (i == 1 || i == n) {
                    if (up[i] == '0') {
                        final[i] = true;
                    }
                    else if (up[(i == 1 ? i + 1 : i - 1)] == '1') {
                        final[(i == 1 ? i + 1 : i - 1)] = true;
                    }
                }
                else {
                    if (up[i] == '0') {
                        if (final[i] == true) {
                            if (up[i - 1] == '1' || up[i + 1] == '1') {
                                final[(up[i - 1] == '1' ? i - 1 : i + 1)] = true;
                            }
                        }
                        else {
                            final[i] = true;
                        }
                    }
                    else {
                        if (up[i - 1] == '1') {
                            if (final[i - 1] == true) {
                                if (up[i + 1] == '1') {
                                    if (final[i + 1] == false) {
                                        final[i + 1] = true;
                                    }
                                }
                            }
                            else {
                                final[i - 1] = true;
                            }
                        } 
                        else if (up[i + 1] == '1') {
                            if (final[i + 1] == true) {
                                if (up[i - 1] == '1') {
                                    if (final[i - 1] == false) {
                                        final[i - 1] = true;
                                    }
                                }
                            }
                            else {
                                final[i + 1] = true;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += final[i];
        }
        cout << ans << endl;
    }
}
