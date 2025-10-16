#include <iostream>
using namespace std;

int main() {
	cout << "Problem 6\n";
	// p => q <=> !p or q
	bool P, Q, P_imply_Q, ans = true;
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
	return 0;
}