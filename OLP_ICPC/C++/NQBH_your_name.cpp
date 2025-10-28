#include <algorithm>
#include <iostream>
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
		string s, t;
		cin >> s >> t;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if (s == t) cout << "YES\n";
		else cout << "NO\n";
	}
}