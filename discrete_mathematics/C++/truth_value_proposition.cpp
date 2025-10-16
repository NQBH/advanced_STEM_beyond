#include <iostream>
using namespace std;

int main() {
	bool p, q; // bool is a data type in C++, which can be true or false
	if (1 + 1 == 2) cout << "true";
	else cout << "false";
	if (2 + 2 == 3) cout << "true";
	else cout << "false";
	if (1 + 1 == 2) p = true;
	else p = false;
	if (2 + 2 == 3) q = true;
	else q = false;
	cout << "Proposition 1 + 1 = 2 is " << p << '\n';
	cout << "Proposition 2 + 2 = 3 is " << q << '\n';

	// Problem 1 (a): Input x then decide if x + 1 = 2 is true or false
	int x;
	cin >> x;
	if (x + 1 == 2) cout << "x + 1 = 2 is true";
	else cout << "x + 1 = 2 is false";

	// Problem 1 (b): Input x then decide if x + 1 = 2 is true or false
	int y, z;
	cin >> x >> y >> z;

	// Problem 2
	p = (x + 1 == 2);
	q = (x + y == z);
	cout << " p and q is " << (p && q) << '\n'; // (p and q)
	cout << " p or q is " << (p || q) << '\n'; // (p or q)
	cout << " p xor q is " << (p ^ q) << '\n'; // (p xor q)
}