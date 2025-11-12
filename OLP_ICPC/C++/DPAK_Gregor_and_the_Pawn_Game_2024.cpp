#include <bits/stdc++.h>
#define int long long
#define yes cout << "yes";
#define no cout << "no";
#define endl '\n';

using namespace std;
const int oo = LLONG_MAX;

signed main() {

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string ss, st;
        cin >> ss >> st;
        int ans = 0;

        if (st[0] == '1') {
            
            if (ss[0] == '0') {
                ss[0] = '2';
                ans++;
            }
            else if (ss[1] == '1') {
                ans++;
                ss[1] = '2';
            }
        }
        if (st[n-1] == '1') {

            if (ss[n-1] == '0') {
                ss[n-1] = '2';
                ans++;
            }
            else if (ss[n-2] == '1') {
                ans++;
                ss[n-2] = '2';
            }
        }
        
        for (int i = 1; i < n - 1; i++) {
            if (st[i] == '1') {
                if (ss[i] == '0') {
                    ss[i] = '2';
                    ans++;
                }
                else if (ss[i - 1] == '1') {
                    ss[i-1] = '2';
                    ans++;
                }
                else if (ss[i + 1] == '1') {
                    ss[i + 1] = '2';
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}