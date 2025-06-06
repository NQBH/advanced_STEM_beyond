#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    if (n == 2) {
        int x;
        cin >> x;
        if (x == 1) {cout << 2; return 0;}
        else {cout << 1; return 0;}
    }
    long long a[n - 1];
    for (long long i = 0; i < n - 1; i++) cin >> a[i];
    sort(a, a + n - 1);
    if (a[n - 2] != n) {cout << n; return 0;}
    for (long long i = 0; i < n - 2; i++) {
        if (a[i + 1] - a[i] > 1) {
            cout << a[i] + 1;
            return 0;
        }
    }
}