#include <bits/stdc++.h>
using namespace std;

void XOR(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans ^= i;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    XOR(n);
}