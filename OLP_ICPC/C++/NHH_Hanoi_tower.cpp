#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

void move (ll n, ll l, ll r, ll m) {
    if (n == 1) {
        cout << l << " " << r << '\n';
        return;
    }

    // move n-1 disks from left to middle, right as the 'middle man' (by recursion)
    move(n - 1, l, m, r);
    // move the nth disk (largest disk) from left to right
    cout << l << " " << r << '\n';
    // move n-1 disks from middle to right (by recursion)
    move(n - 1, m, r, l);
}

int main() {
    ll n; cin >> n;
    cout << pow(2, n) - 1 << '\n'; // total moves
    move(n, 1, 3, 2);
    return 0;
}