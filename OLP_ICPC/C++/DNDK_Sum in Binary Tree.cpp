#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long res = 0;
		for (long long i = n; n > 0; n / 2) {
			res += n;
			n /= 2;
		}
		cout << res << endl;
	}
}
