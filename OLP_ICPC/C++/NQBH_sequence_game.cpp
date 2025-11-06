#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;
		vector<int> a(n);
		for (int &i : a) cin >> i;
		cin >> x;
		if (x >= *min_element(a.begin(), a.end()) && x <= *max_element(a.begin(), a.end())) cout << "YES\n";
		else cout << "NO\n";		
	}
}