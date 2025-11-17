#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, neg = 0;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i){
		cin >> x[i] >> y[i];
		if (x[i] < 0) ++neg;
	}
	if (neg <= 1 || neg >= n - 1) cout << "YES";
	else cout << "NO";
}