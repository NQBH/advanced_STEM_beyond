#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n, count[3] = {0}, current_pebble_location[3] = {1, 2, 3};
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int a, b, g;
		cin >> a >> b >> g;
		for (int i = 0; i < 3; ++i) {
			if (current_pebble_location[i] == a) current_pebble_location[i] = b;
			else if (current_pebble_location[i] == b) current_pebble_location[i] = a;
			if (current_pebble_location[i] == g) ++count[i - 1];
		}
	}
	cout << max({count[0], count[1], count[2]}) << '\n';
}