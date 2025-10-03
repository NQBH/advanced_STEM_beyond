#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = a; i <= c; i += a) {
		if (i % b == 0) continue;
		else if (c % i != 0) continue;
		else if (d % i == 0) continue;
		else {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}