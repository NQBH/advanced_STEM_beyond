#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int m, n;
vector<int> a, f;

void dp() {
    cin >> n >> m;
    vector<int> s(m + 1), t(m + 1), c(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> s[i] >> t[i] >> c[i];
    }
    f.resize(n + 1, MOD);
    // f[i] : chi phi toi thieu tu thoi diem 0 -> i
    f[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = s[i] + 1; j <= t[i]; j++) {
            f[j] = min(f[j], f[s[i]] + c[i]);
        }
    }
    cout << f[n] << endl;

}

int main(){
    int t; cin >> t;
    while(t--) {
        dp();
    }
}