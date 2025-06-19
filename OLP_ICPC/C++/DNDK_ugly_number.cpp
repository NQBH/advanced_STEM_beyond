#include <iostream>
using namespace std;

bool ugly(int x) {
	while (x % 2 == 0) x /= 2;
	while (x % 3 == 0) x /= 3;
	while (x % 5 == 0) x /= 5;
	return x == 1;
}

int main() {
	int n;
	while (cin >> n and n != 0) {
		int count = 0;
		int i = 1;
		while (true) {
			if (ugly(i)) {
				++count;
				if (count == n) {
					cout << i << "\n";
					break;
				}
			}
			++i;
		}
	}
}