#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> c(3), m(3);
	for (int i = 0; i < 3; ++i) cin >> c[i] >> m[i];
	for (int i = 0; i < 100; ++i) {
		int curr = i % 3, next = (i + 1) % 3, max_pour_amount = c[next] - m[next];
		if (m[curr] <= max_pour_amount) {
			m[next] += m[curr];
			m[curr] = 0;
		}
		else {
			m[curr] -= max_pour_amount;
			m[next] = c[next];
		}
	}
	for (int i = 0; i < 3; ++i) cout << m[i] << '\n';
}