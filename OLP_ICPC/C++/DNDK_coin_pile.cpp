#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		long long c = a + b;
		if (a > b) {
			swap(a, b);
		}
		if (c % 3 != 0 or b > 2 * a) {
			cout << "NO" << "\n";
		}
		else
			cout << "YES" << "\n";
	}
}