#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 5; // size of array
	vector<int> elements{0, 1, 1, 1, 1, 1}; // 1 based indexing
	// n + 2 because we are not using the 0th index & we need 1 more element in the array
	vector<int> diff(n + 2, 0);
	int update_value = 10, l = 2, r = 5;
	diff[l] += update_value;
	diff[r + 1] -= update_value;
	for (int i = 1; i <= n; ++i) {
		diff[i] += diff[i - 1];
		elements[i] += diff[i];
	}
	for (int i = 1; i <= n; ++i) cout << elements[i] << " ";
}