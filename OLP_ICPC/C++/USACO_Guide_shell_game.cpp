#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> shell_at_pos(3); // shell_at_pos[i] stores the label of the shelll located at position i
	for (int i = 0; i < 3; ++i) shell_at_pos[i] = i; // place the shells down arbitrarily
	vector<int> counter(3);
	for (int i = 0; i < n; ++i) {
		int a, b, g;
		cin >> a >> b >> g;
		--a, --b, --g; // 0-indexing: offset all positions by 1
		swap(shell_at_pos[a], shell_at_pos[b]); // perform Bessie's swapping operation
		++counter[shell_at_pos[g]];
	}
	cout << max({counter[0], counter[1], counter[2]}) << '\n';
}