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
		int n0 = 0, n1 = 0;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == '0') ++n0;
			else ++n1;
		if (!n0) cout << "0\n";
		else if (!n1) cout << "1\n";
		else {
			int n0segment = 0;
			if (s[0] == '0') ++n0segment;
			for (int i = 1; i < s.size(); ++i)
				if (s[i - 1] == '1' && s[i] == '0') ++n0segment;
			cout << min(2, n0segment) << '\n';
		}
	}
}