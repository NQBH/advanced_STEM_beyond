#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int x, y, k;
    cin >> x >> y >>k;
    cout << (k * (y + 1) - 1) / (x - 1) + k + !!((k * (y + 1) - 1) % (x - 1)) << endl;
}

main() {
	int t;
    cin >>t;
	while(t--)
        solve();
	return 0;
}
