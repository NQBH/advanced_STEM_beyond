#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool ok1 = false;
		vector<int> d(n), s(n);
		map<int, int> m; // m[i] = fastest activated trap in room i
		for (int i = 0; i < n; ++i) {
			cin >> d[i] >> s[i];
			if (d[i] == 1 && s[i] == 1) ok1 = true;

		}
		if (ok1) {
			cout << 1 << '\n';
			continue;
		}
		

	}
}