#include <iostream>
using namespace std;
#define ll long long

int main() {
	ll n;
	while (cin >> n and n != 0) {
		ll sum = 0;
		ll days = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				++days;
				sum += i;
				if (days == n) break;
			}
			if (days == n) break;
		}
		cout << n << " " << sum << "\n";
	}
}