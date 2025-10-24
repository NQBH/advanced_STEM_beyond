#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e16;

struct prob {
    int room;
    int second;
};

signed main() {
    int t; cin >> t;
 
    while (t--) {
        int n; cin >> n;
        vector<prob>a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].room >> a[i].second;
        }
        int MIN = oo;
        for (int i = 1; i <= n; i++) {
            MIN = min(MIN, a[i].room + (a[i].second - 1) / 2);
        }
        cout << MIN << endl;
    }
}