#include <cmath>
#include <iostream>
using namespace std;

int main() {
	/*
	cout << boolalpha; // In true/false thay vì 1/0

	// Problem 1
	// (a) x + 1 = 2
	int x;
	cin >> x;
	if (x == 1) cout << "true";
	else cout << "false";

	// (b) x + y = z
	int y, z;
	cin >> x >> y >> z;
	if (x + y == z) cout << "true";
	else cout << "false";

	// Problem 2

	bool p = (x + 1 == 2), q = (x + y == z);
	cout << "p: " << p << '\n';
	cout << "q: " << q << '\n';
	cout << "p and q: " << (p && q) << '\n'; // or p and q
	cout << "p or q: " << (p || q) << '\n'; // or p or q
	cout << "negative p: " << (!p) << '\n';
	cout << "negative q: " << (!q) << '\n';
	cout << "p xor q: " << (p ^ q) << '\n';

	// Problem 3
	// p => q
	if (p == true && q == false) cout << "p => q: false";
	cout << "p => q: true";
	cout << "Original proposition: p => q: " << (!p || q) << '\n';
	cout << "Converse proposition: q => p: " << (p || !q) << '\n';
	cout << "Contrapositive proposition: !q => !p: " << (!p || q) << '\n';
	cout << "Inverse proposition: !p => !q: " << (p || !q) << '\n';

	// Problem 4
	double n;
	cin >> n;
	if (pow(2, n) >= 100) cout << "true" << '\n';
	else cout << "false\n";

	// Problem 5
	

	// Problem 6
	bool p, q;
	cout << "Problem 6\n";
	bool ans = true;
	for (int i = 0; i <= 1; ++i) {
		for (int j = 0; j <= 1; ++j) 
			for (int k = 0; k <= 1; ++k) {
			p = i;
			q = j;
			r = k;
			if ((p || (p && q)) != p) ans = false;
		}
	}
	cout << "p or (p and q): " << ans;

	/*
	// p => q <=> !p or q
	bool P, Q, P_imply_Q;
	P = false, Q = false;
	if (P == true && Q == false) P_imply_Q = false; // P => Q
	else P_imply_Q = true;
	if (P_imply_Q != (!P || Q)) ans = false;

	P = false, Q = true;
	if (P == true && Q == false) P_imply_Q = false; // P => Q
	else P_imply_Q = true;
	if (P_imply_Q != (!P || Q)) ans = false;

	P = true, Q = false;
	if (P == true && Q == false) P_imply_Q = false; // P => Q
	else P_imply_Q = true;
	if (P_imply_Q != (!P || Q)) ans = false;

	P = true, Q = true;
	if (P == true && Q == false) P_imply_Q = false; // P => Q
	else P_imply_Q = true;
	if (P_imply_Q != (!P || Q)) ans = false;

	cout << ans << '\n';

	// shorter solution

	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i;
			Q = j;
			if (P == true && Q == false) P_imply_Q = false; // P => Q
			else P_imply_Q = true;
			if (P_imply_Q != (!P || Q)) ans = false;
		}
	cout << ans << '\n';

	*/
	// Problem 7
	// Problem 66a
	bool p, q, r, s, is_satisfiable = false;
	for (int p = 0; p <= 1; ++p)
		for (int q = 0; q <= 1; ++q)
			for (int r = 0; r <= 1; ++r)
				for (int s = 0; s <= 1; ++s) {
					if ((p || q || !r) && (p || !q || !s) && (p || !r || !s) && (!p || !q || !s) && (p || q || !s)) {
						is_satisfiable = true;
						cout << "satisfiable\n" << p << " " << q << " " << r << " " << s << '\n';
						// return 0;					
					}
				}
	if (is_satisfiable == false) cout << "unsatisfiable";

}