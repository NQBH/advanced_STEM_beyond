#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long solve(long long n) {
    long long res = 0;
    for (int i = 0; i <= 50; i++) {
        long long s = 1LL << (i + 1); //2^(i+1)
        long long fs = (n + 1) / s;
        long long r = (n + 1) % s;
        res += fs * (s / 2);
        res += max(0LL, r - (s / 2));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    cout << solve(n);
}