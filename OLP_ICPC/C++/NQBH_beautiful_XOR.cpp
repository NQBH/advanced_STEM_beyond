#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> decimalToBinaryString(int n) {
	vector<int> ret;
	while (n > 0) {
		ret.push_back(n % 2 == 0 ? 0 : 1);
		n /= 2;
	}
	// reverse(binaryString.begin(), binaryString.end()); // Reverse the string as bits are collected in reverse order
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a == b) cout << 0 << '\n';
		else {
			vector<int> str_a = decimalToBinaryString(a), str_b = decimalToBinaryString(b);
			int a_sz = str_a.size(), b_sz = str_b.size();
			// cout << "a_sz = " << a_sz << " b_sz = " << b_sz;
			if (a_sz < b_sz) cout << -1 << '\n';
			else if (a_sz == b_sz) { // & a > b
				int x = 0;
				for (int i = 0; i < str_a.size(); ++i)
					x += (str_a[i] ^ str_b[i]) * (1 << i);
				cout << 1 << '\n' << x << '\n';
			} else { // str_a.size() > str_b.size() & a > b
				int x1 = 0, x2 = 0;				
				for (int i = b_sz; i < a_sz; ++i)
					if (str_a[i]) x1 += (1 << i);
				int a1 = a ^ x1;
				x2 = a1 ^ b;
				if (x2 <= a1) {
					cout << 2 << '\n' << x1 << ' ' << x2 << '\n';
					continue;
				}
				x1 = 0, x2 = 0;
				for (int i = 0; i < b_sz; ++i) {
					x1 += (str_a[i] ^ str_b[i]) * (1 << i);
				}
				a1 = a ^ x1;
				x2 = a1 ^ b;
				if (x2 <= a1) {
					cout << 2 << '\n' << x1 << ' ' << x2 << '\n';
					continue;
				}
			}
		}
	}
}