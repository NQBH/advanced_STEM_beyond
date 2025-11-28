#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string n;
		cin >> n;
		if (n.size() == 1) cout << "0\n";
		else {
			int ans = 0, i;
			for (i = n.size() - 1; i >= 0; --i)
				if (n[i] == '0') ++ans;
				else break;
			for (int j = 0; j < i; ++j)
				if (n[j] != '0') ++ans;
			cout << ans << '\n';
		}
	}
}