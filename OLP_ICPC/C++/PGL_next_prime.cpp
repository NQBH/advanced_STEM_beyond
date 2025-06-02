#include <iostream>
using namespace std;
#define ll long long

bool prime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll x = 3; x * x <= n; x += 2) {
        if (n % x == 0) return false;
    }
    return true;
}

int main() {
    int t; cin >> t;

    while (t--) {
        ll n; cin >> n;
        n++;
        while (!prime(n)) n++;
        cout << n << endl;
    }
}