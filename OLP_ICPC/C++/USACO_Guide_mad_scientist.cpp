#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cow_num, min_flips = 0;
	cin >> cow_num;
	vector<char> a(cow_num), b(cow_num);
	for (char &c : a) cin >> c;
	for (char &c : b) cin >> c;
	// diff[i] is true if the cows differ at the ith position
	// notice that there's an extra false at the beginning
	vector<bool> diff(cow_num + 1);
	for (int i = 0; i < cow_num; ++i) diff[i + 1] = a[i] != b[i];
	/*
	 * count the number of times [false, true] occurs in diff
	 * this is equivalent to the number of continous segments of trues
	 * that extra false at the beginning comes in handy here,
	 * since if we didn't have it we've have to have an edge case for
	 * the first segment that doesn't have a preceding false
	 */
	for (int i = 0; i < cow_num; ++i)
		if (!diff[i] && diff[i + 1]) ++min_flips;
	cout << min_flips << '\n';
}