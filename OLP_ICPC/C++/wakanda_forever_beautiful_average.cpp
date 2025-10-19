#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << *max_element(a.begin(), a.end()) << '\n';
	}
}