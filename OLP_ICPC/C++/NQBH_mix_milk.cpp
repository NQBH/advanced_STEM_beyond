#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> c(3), m(3);
	for (int i = 0; i < 3; ++i) cin >> c[i] >> m[i];
	for (int i = 0; i < 100; ++i) {
		int curr = i % 3, next = (i + 1) % 3, pour_amount = min(m[curr], c[next] - m[next]);
		m[curr] -= pour_amount;
		m[next] += pour_amount;
	}
	for (int i : m) cout << i << '\n';
}