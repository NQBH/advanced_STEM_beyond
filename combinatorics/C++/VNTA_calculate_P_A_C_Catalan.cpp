#include<bits/stdc++.h>
using namespace std;

// n_max = 20
long long Pn(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

// n_max = 20
long long nAk(int n, int k) {
    long long res = Pn(n) / Pn(n - k);
    return res;
}

// n_max = 20
long long nCk(int n, int k) {
    long long res = Pn(n) / (Pn(n - k) * Pn(k));
    return res;
}

// n_max = 10
long long catalan_n(int n) {
    long long res = Pn(2 * n) / (Pn(n) * Pn(n + 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    cout << Pn(n) << endl << nAk(n, k) << endl << nCk(n, k) << endl << catalan_n(n);
}