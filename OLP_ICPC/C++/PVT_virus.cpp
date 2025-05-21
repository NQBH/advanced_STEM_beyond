/*
    Virus problem (not ViruSs)
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int a[100005];
        for(int i = 0; i <= k+1; ++i) a[i] = 0;
        a[1] = n;
        for(int i = 1; i <= k; ++i) {
            int temp = 0;
            for(int j = i; j >= 1; --j) {
                a[j+1] = a[j];
                temp += a[j+1] * j;
            }
            a[1] = temp;
        }
        int sum = 0;
        for(int i = 1; i <= k+1; ++i) sum += a[i];
        cout << sum << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    solve();
    return 0;
}