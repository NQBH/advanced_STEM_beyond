#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll R, x, d, n;
        cin >> R >> x >> d >> n;
        char a;
        ll cnt = 0;
        while (n--) {
            cin >> a;
            if (a == '1') {
                cnt++;
                R -= d;
            }
            if (a == '2') {
                if (R >= x) continue;
                else {
                    cnt++;
                    R -= d;
                }
            }
        }
        cout << cnt << "\n";
    }
}
