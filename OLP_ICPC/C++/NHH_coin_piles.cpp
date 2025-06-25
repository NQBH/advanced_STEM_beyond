#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;


int main() {
    ll t, a, b, sum = 0;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        sum = a + b;
        if (sum % 3 == 0 && max(a, b) <= 2 * min(a, b)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}