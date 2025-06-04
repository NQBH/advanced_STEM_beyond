#include <iostream>
using namespace std;

static const long long MOD = 1000000007;

int main() {
    int n; cin >> n;
    // base cases: !0 = 1,  !1 = 0
    if (n == 0) {
        cout << 1 << "\n";
        return 0;
    }
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    long long prev2 = 1; // !(0) = 1
    long long prev1 = 0; // !(1) = 0

    for (int i = 2; i <= n; ++i) {
        long long current = ( (long long)(i - 1) * ((prev1 + prev2) % MOD) ) % MOD;
        prev2 = prev1;
        prev1 = current;
    }

    cout << prev1 << "\n";
    return 0;
}