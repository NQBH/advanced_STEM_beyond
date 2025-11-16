#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T -- > 0) {
		int n, s;
		cin >> n >> s;
		int m = n / 2 + 1;
		cout << s / m << '\n';
	}
}