#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n; cin >> n;
    ll sum = 0;
    for (ll i = 0; i < n - 1; i++) {
        ll x; cin >> x;
        sum += x;
    }
    ll total = n * (n + 1) / 2;
    ll missing = total - sum;
    cout << missing << "\n";
    return 0;
}