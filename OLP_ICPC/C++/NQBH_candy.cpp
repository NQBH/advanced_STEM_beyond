#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> spell; // backwards
		if (n % 2 == 0) cout << "-1\n";
		else {
			while (n > 1)
				if (n % 4 == 1) {
					spell.push_back(1);
					n = (n + 1) / 2;
				} else {
					spell.push_back(2);
					n = (n - 1) / 2;
				}
			cout << spell.size() << '\n';
			for (int i = spell.size() - 1; i >= 0; --i) {
				cout << spell[i] << " \n"[i == 0];
			} 
		}
	}
}