#include <iostream>
#define ll long long
using namespace std;

// return position of left most set bit. The rightmost position is considered as 0
ll get_leftmost_bit(ll n) {
	ll m = 0;
	while (n > 1) {
		n = n >> 1;
		++m;
	}
	return m;
}
// given the position of previous leftmost set bit in n (or an upper bound on leftmost position) returns the new position of leftmost set bit in n
ll get_next_leftmost_bit(ll n, ll m) {
	ll temp = 1 << m;
	while (n < temp) {
		temp = temp >> 1;
		--m;
	}
	return m;
}
// returns count of set bits present in all numbers from 1 to n
ll count_set_bit(ll n) { // time complexity: O(log n), auxiliary space: O(1)
	// base case: if n = 0, then set bit count = 0
	if (n == 0) return 0;
	// get the position of leftmost set bit in n. This will be used as an upper bound for next set bit function
	ll m = get_leftmost_bit(n);
	// get position of next leftmost set bit
	m = get_next_leftmost_bit(n, m);
	// if n is of the form 2^x - 1: done. Since positions are considered starting from 0, 1 is added to m
	if (n == (1LL << (m + 1)) - 1) return (m + 1) * (1 << m);
	// update n for next recursive call
	n = n - (1LL << m);
	return (n + 1) + count_set_bit(n) + m * (1LL << (m - 1));
}

int main() {
	ll n;
	cin >> n;
	cout << count_set_bit(n);
}