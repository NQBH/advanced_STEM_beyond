#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, k;
vector<int> a, f;

void dp() {
    cin >> n >> k;
    a.clear();
    f.clear();
    a.resize(n + 1), f.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] - a[j] >= k) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    //for (int i = 1; i <= n; i++) {
    //    cout << "f[" << i <<"] = " << f[i] << endl;
    //}
    int ans = *max_element(f.begin(), f.end());
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) {
        dp();
    }
}