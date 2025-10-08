#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1), l(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> l[i];
        vector<int> temp;
        for (int i = 1; i <= n; i++) {
            if (l[i] == 0) temp.push_back(a[i]);
        }
        sort(temp.begin(), temp.end(), greater<int>());
        int j = 0;
        for (int i = 1; i <= n; i++) {
            if (l[i] == 0) {
                cout << temp[j++] << ' ';
            }
            else {
                cout << a[i] << ' ';
            }
        }
        cout << endl;
    }
}
