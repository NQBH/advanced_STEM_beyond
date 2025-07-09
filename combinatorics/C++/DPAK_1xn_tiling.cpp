#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> f(n + 1, 0);
    f[2] = 1;
    f[4] = 3;    
    for (int i = 6; i <= n; i += 2) f[i] = f[i - 2] + 2 * f[i - 4];
    cout << f[n];
}