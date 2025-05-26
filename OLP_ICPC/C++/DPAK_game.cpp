#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, k;
vector<int> h, f; // f: dynamic programming array

void dp() {
    cin >> n >> k;
    h.clear();
    f.clear();
    h.resize(n + 1), f.resize(n + 1, INT_MAX);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    f[1] = 0;
    f[2] = abs(h[2] - h[1]);

    for (int i = 3; i <= n; i++) {
        for (int j = i-1; j >= max(1, i - k); j--) {
            f[i] = min(f[i], f[j] + abs(h[i] - h[j]));
        }
    }
    //for (int i = 1; i <= n; i++) {
    //    cout << "f[" << i << "] = " <<f[i] << endl;
    //}
    cout << f[n] << endl;
}

int main(){
    int t; cin >> t;
    while(t--) {
        dp();
    }
}