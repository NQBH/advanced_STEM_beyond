#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--) {
        int l[3], r[3];
        for (int i = 0; i < 3; i++) {
            cin >> l[i] >> r[i];
        }

        bool ok = false;
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                for (int c = 0; c < 3; c++) {
                    if (a == b || b == c || a == c) continue;

                    int l1 = l[a], r1 = r[a];
                    int l2 = l[b], r2 = r[b];
                    int l3 = l[c], r3 = r[c];

                    int area = l1 * r1 + l2 * r2 + l3 * r3;
                    int S = sqrt(area);

                    if (r1 == r2 && r2 == r3 && l1 + l2 + l3 == S && r1 == S) {
                        ok = true;
                    }

                    if (l1 == l2 && l2 == l3 && r1 + r2 + r3 == S && l1 == S) {
                        ok = true;
                    }

                    if (l1 == S && r1 < S && r2 == r3 && r1 + r2 == S && l2 + l3 == S) {
                        ok = true;
                    }

                    if (r1 == S && l1 < S && l2 == l3 && l1 + l2 == S && r2 + r3 == S) {
                        ok = true;
                    }
                }
            }
        }
    if (ok) cout << "YES"; else cout << "NO";
    cout << endl;
    }
}