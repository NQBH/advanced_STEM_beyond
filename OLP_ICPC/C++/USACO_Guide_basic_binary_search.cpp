#include <functional>
#include <iostream>
using namespace std;

int last_true(int lo, int hi, function<bool(int)> f) {
	// if none of the values in the range work, return lo - 1
	--lo;
	while (lo < hi) {
		// find the middle of the current range (rounding up)
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) lo = mid; // if mid works, then all numbers smaller than mid also work
		else hi = mid - 1; // if mid does not work, greater values would not work either
	}
	return lo;
}

int last_true_bin_jump(int lo, int hi, function<bool(int)> f) {
	--lo;
	for (int dif = hi - lo; dif > 0; dif /= 2)
		while (lo + dif <= hi && f(lo + dif)) lo += dif;
	return lo;
}

int first_true(int lo, int hi, function<bool(int)> f) {
	++hi;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main() {
	// all numbers satisfy the condition (output 10)
	cout << last_true(2, 10, [](int x) { return true; }) << '\n';
	cout << last_true(2, 10, [](int x) { return x * x <= 30; }) << '\n'; // output 5
	// no numbers satisfy the condition (output 1)
	cout << last_true(2, 10, [](int x) { return false; }) << '\n';

	cout << first_true(2, 10, [](int x) { return true; }) << '\n'; // output 2
	cout << first_true(2, 10, [](int x) { return x * x >= 30; }) << '\n'; // output 6
	cout << first_true(2, 10, [](int x) { return false; }) << '\n';
}