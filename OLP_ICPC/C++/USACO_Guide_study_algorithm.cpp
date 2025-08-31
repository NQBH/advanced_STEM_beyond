#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int algorithms[n];
	for (int i = 0; i < n; ++i) cin >> algorithms[i];
	sort(algorithms, algorithms + n);
	int i = 0, count = 0; // count = the number of minutes used so far
	while (i < n && count + algorithms[i] <= x) {
		// while there is enough time, learn more algorithms
		count += algorithms[i];
		++i;
	}
	cout << i << '\n';
}