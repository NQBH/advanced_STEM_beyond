#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
//    int t; cin >> t;
//    while (t--) {
        int q; cin >> q;
        int peopleAtStop = 0;
        while (q--) {
            char type; cin >> type;
            int people; cin >> people;
            if (type == 'B') {
                if (peopleAtStop >= people) {
                    cout << "NO" << endl;
                    peopleAtStop -= people;
                }
                else if (peopleAtStop < people) {
                    cout << "YES" << endl;
                    peopleAtStop = 0;
                }
            }
            else {
                peopleAtStop += people;
            }
        }
    }
//}
