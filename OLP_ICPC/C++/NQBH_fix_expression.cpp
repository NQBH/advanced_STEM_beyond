#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, c;
		char b;
		cin >> a >> b >> c;
		if (a == c && b != '=') b = '=';
		else if (a < c && b != '<') b = '<';
		else if (a > c && b != '>') b = '>';
		cout << a << b << c << '\n';
	}
}