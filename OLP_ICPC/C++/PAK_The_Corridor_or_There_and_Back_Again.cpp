#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    while (N--) {
        int n, d, s, k, ans; cin >> n ; ans = 1e9;
        vector<int> traproom(n + 1), traptime(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> traproom[i]; cin >> traptime[i];
            if (traptime[i] % 2 == 0) { k = traproom[i] + (traptime[i] / 2 - 1) ;}
            else {k = traproom[i] + traptime[i] / 2; }
            ans = min (ans , k);
        }
        cout << ans << '\n';


    }
}