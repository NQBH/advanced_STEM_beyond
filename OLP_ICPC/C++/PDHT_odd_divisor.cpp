#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        bool yn = false;
        while (n % 2 == 0) n = n / 2;
        if (n >= 3) yn = true;
        if (yn) cout << "YES\n";
        else cout << "NO\n";
    }
}
