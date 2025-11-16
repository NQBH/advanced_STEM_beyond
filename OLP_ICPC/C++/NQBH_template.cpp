#include <bits/stdc++.h>
using namespace std;

// binary search
int binary_search(int A[], int sizeA, int target) {
	int lo = 1, hi = sizeA;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (A[mid] == target) return mid;
		else if (A[mid] < target) lo = mid + 1;
		else hi = mid - 1;
	}
	return -1;
}

int last_true(int lo, int hi, function<bool(int)> f) {
	// if none of the values in the range work, return lo -1
	--lo;
	while (lo < hi) {
		// find the middle of the current range (rounding up)
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) lo = mid; // if mid works, then all numbers smaller than mid also work
		else hi = mid - 1; // if mid does not work, greater values would not work either
	}
	return lo;
}

int last_true(int lo, int hi, function<bool(int)> f) {
	--lo;
	for (int dif = hi - lo; dif > 0; dif /= 2)
		while (lo + dif <= hi && f(lo + dif)) lo += dif;
	return lo;
}

// check prime
bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;


	}

	// BINARY SEARCH
	// all numbers satisfy the condition (outputs 10)
	cout << last_true(2, 10, [](int x) { return true; }) << endl;
	// outputs 5
	cout << last_true(2, 10, [](int x) { return x * x <= 30; }) << endl;
	// no numbers satisfy the condition (outputs 1)
	cout << last_true(2, 10, [](int x) { return false; }) << endl;
}