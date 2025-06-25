#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main() {
    ll n; cin >> n;
    ll count = 0;
    ll n5 = 5;
    ll res = n / n5;

    while (res != 0) {
        count += res;
        n5 = n5 * 5;
        res = n / n5;
    }
    cout << count << " ";
    return 0;
}