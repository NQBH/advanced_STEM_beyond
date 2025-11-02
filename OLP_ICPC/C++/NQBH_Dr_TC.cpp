#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int num1 = 0;
		for (char c : s)
			if (c == '1') ++num1;
		cout << num1 * (n - 1) + (n - num1) << '\n';
	}
}