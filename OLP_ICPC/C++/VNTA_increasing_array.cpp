#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, s = 0;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            s += (a[i] - a[i + 1]);
            a[i + 1] += a[i] - a[i + 1];
        }
    }
    cout << s;
}