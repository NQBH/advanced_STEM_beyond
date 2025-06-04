#include <bits/stdc++.h>
#define ll long long
using namespace std;
//Thuat toan Primality tests
bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; //t -> test cases
    cin >> t;

    while (t--) {
        ll n; //điểm mốc
        cin >> n;

        ll candidate = n + 1;
        if (candidate % 2 == 0 && candidate != 2) candidate++; // bắt đầu từ số lẻ nếu không phải 2

        while (!isPrime(candidate)) {
            candidate += 2; // bỏ qua số chẵn
        }

        cout << candidate << '\n';
    }
}
