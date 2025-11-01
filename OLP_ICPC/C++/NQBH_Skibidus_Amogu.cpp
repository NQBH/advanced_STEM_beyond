#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s == "us") cout << "i\n";
		else {
			for (int i = 0; i < s.size() - 2; ++i) cout << s[i];
			cout << "i\n";
		}
	}
}