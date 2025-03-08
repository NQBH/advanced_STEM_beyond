#include <iostream>
using namespace std;
int main() {
	int i, j, n, count, a[20];
	cin >> a[0]; // input 1st element
	while (a[0] != -1) { // if it is not end of input, input a new test case
		n = 1;
		for ( ; ; ++n) {
			cin >> a[n];
			if (a[n] == 0) break;
		}
		count = 0; // determine how many items in each list are twice some other item
		for (i = 0; i < n - 1; ++i) { // enumerate all pairs
			for (j = i + 1; j < n; ++j) {
				if (a[i]*2 == a[j] || a[j]*2 == a[i]) // accumulation
					++count;
			}
		}
		cout << count << endl; // output result
		cin >> a[0]; // input 1st element of next test case
	}
	return 0;
}