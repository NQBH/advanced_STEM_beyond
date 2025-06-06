#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    if (n == 1) {cout << 1; return 0;}
    if (n < 4) {cout << "NO SOLUTION"; return 0;}
    if (n % 2 == 0) {
        for (long long i = n - 1; i >= 1; i -= 2) cout << i << " ";
        for (long long i = n; i >= 2; i -= 2) cout << i << " ";
    } else {
        for (long long i = n - 1; i >= 2; i -= 2) cout << i << " ";
        for (long long i = n; i >= 1; i -= 2) cout << i << " ";
    }
}