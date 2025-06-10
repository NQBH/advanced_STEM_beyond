#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007
ll pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int main() {
    int n; cin >> n;
    cout << pow(2, n) << endl;
}