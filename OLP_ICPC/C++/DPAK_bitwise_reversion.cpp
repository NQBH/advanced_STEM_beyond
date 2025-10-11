#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        /*
        x = a & b, y = b & c, z = a & c
        3 2 6
        011
        010
        110
        4 8 12
        0100
        1000
        1100
        */
        int x, y,z; cin >> x >> y >> z;
        vector<int> cnt(32, 0);
        int i = 0;
        while (x > 0) {
            cnt[i++] = x % 2; x /= 2;
        }
        i = 0;
        while (y > 0) {
            cnt[i++] += y % 2; y /= 2;
        }
        i = 0;
        while(z > 0) {
            cnt[i++] += z % 2; z /= 2;
        }
        bool check = true;
        for (int i = 0; i < 32; i++) {
            if (cnt[i] > 0) {
                if (cnt[i] == 2) check = false;
            }
        }
        cout << (check ? "YES" : "NO") << endl;
    }
}
