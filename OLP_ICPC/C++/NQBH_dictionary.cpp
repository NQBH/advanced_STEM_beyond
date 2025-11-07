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
		cout << (s[0] - 'a') * 25 + s[1] - 'a' + (s[0] > s[1] ? 1 : 0) << '\n';
	}
}