#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
    	int m, a, b, c;
    	cin >> m >> a >> b >> c;
    	int ans = 0, rem = 0;
    	ans += min(m, a);
    	rem += m - min(m, a);
    	ans += min(m, b);
    	rem += m - min(m, b);
    	ans += min(rem, c);
    	cout << ans << '\n';
    }
}