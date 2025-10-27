#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int res = 0;
        while (n >= 3) {
            res += (int)(n / 3);
            n = (int)(n / 3 + n % 3);
        }
        cout << res << '\n';
    }
}