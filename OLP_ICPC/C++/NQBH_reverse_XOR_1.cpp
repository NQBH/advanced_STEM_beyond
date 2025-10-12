#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        bool yes = false;
        for (int l = 1; l <= 60; l++) {
            if ((n >> l) != 0) continue;
            bool ok = true;
            for (int k = 0; k < (l + 1) / 2; k++) {
                unsigned long long bit1 = ((n >> k) & 1);
                int pos2 = l - 1 - k;
                unsigned long long bit2 = ((n >> pos2) & 1);
                if (bit1 != bit2) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            if (l % 2 == 1) {
                int mid = (l - 1) / 2;
                unsigned long long bitm = ((n >> mid) & 1);
                if (bitm != 0) continue;
            }
            yes = true;
            break;
        }
        cout << (yes ? "YES\n" : "NO\n");
    }
}