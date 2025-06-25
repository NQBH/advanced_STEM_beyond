#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll sum = 0;
    for (int j = 60; j >= 0; --j) {
        ll bit = 1ll << j; // 2^j
        sum += n / (bit * 2) * bit;
        sum += max(0ll, n % (bit * 2) - (bit - 1));
    }
    cout << sum << '\n';
}