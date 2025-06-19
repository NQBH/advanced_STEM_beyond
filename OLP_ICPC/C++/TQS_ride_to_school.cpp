#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n;
    while (n) {
        long long kq = 1e9;
        while (n--) {
            cin >> a >> b;
            if (b >= 0 )
                kq = min(kq, (long long)(b + ceil(4.5 * 3600 / a)));
        }
        cout << kq << "\n";
        cin >> n;
    }
}