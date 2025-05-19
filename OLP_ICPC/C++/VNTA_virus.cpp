#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
using namespace std;

const int mod = 1e9 + 7;
void fib(long n, long k) {
	vector<int> f(100001, 0);
	f[0] = 0; f[1] = 1;
	for (int i = 2; i <= 100001; i++) {
        f[i] = f[i - 1] + f[i -2];
        f[i] %= mod;
	}
    int ans = f[1];
    for (int i = 1; i <= k; i++) {
        ans += f[2 * i];

    }
    ans *= n;
    ans %= mod;
    cout << "TA: " << ans << endl;
}

int main(){
    KhangGPT40_TramAnhGrok3;
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        fib(n, k);
    }

    return 0;
}