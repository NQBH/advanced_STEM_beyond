#include <bitset>
#include <iostream>
using namespace std;

int main() {
	int a = 5;
	cout << bitset<32>(a) << '\n';     // Binary representation of a
	cout << bitset<32>(~a) << '\n';    // Binary of NOT a
	// bitset<32> means we represent the number using 32 bits.

	// turn bits on/off/flip
	int x = 1;
	a = a | (1 << x); // turn on bit x: make sure bit x = 1 (keep others unchanged)
	a = a & ~(1 << x); // turn off bit x: make sure bit x = 0.
	a = a ^ (1 << x); // flip bit x: 1 -> 0, 0 -> 1

	// check if bit x is on
	if (a & (1 << x)) cout << "ON";
	else cout << "OFF";

	if ((a >> x) & 1) cout << "ON";

	// even/odd check
	if (x & 1) cout << "Odd";
	else cout << "Even";

	// can a string form a palindrome?
	string s;
	cin >> s;
	int ans = 0;
	for (char c : s) ans ^= 1 << (c - 'a');
	// if at most 1 bit is ON -> palindrome possible
	if (ans == 0 || (ans & (ans - 1)) == 0) cout << "YES"; // trick (ans & (ans - 1)) == 0 checks whether ans has only 1 bit ON, i.e., ans is a power of 2
	else cout << "NO";

	/* build-in bit functions (gcc)
	__builtin_popcount(x): count 1s in integer
	__builtin_popcountll(x): count 1s in long long
	__builtin_clz(x): count leading 0s = count how many 0s come before the 1st 1 from the left.
	__builtin_ctz(x): count trailing 0s= count how many 0s come after the last 1 from the right. These are useful to find the position of the 1st or last set bit quickly
	__lg(x): position of highest bit (approximately floor(log2(x)))
	*/
	x = 8;
	cout << __builtin_popcount(x) << endl; // 1
	cout << __lg(x) << endl;               // 3
	cout << (1 << __lg(x)) << endl;        // 8
	// all bitwise operations work in O(1). Mastering them can make your code shorter, faster, & smarter.
}
/* Source: https://codeforces.com/blog/entry/147619
Nour777's blog: Bitwise Operations in C++
*/