#include <iostream>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7; // tránh tràn số nguyên lớn

int main() {
    ll n; cin >> n;
    ll res = 1;

    // Với mỗi vị trí có 2 cách chọn các bit (0 hoặc 1)
    for (ll i = 0; i < n; ++i)
        res = (res * 2) % MOD;
    cout << res << "\n";
    return 0;
}