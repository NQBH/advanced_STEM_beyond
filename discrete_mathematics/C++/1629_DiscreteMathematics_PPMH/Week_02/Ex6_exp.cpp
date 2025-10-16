#include <iostream>
using namespace std;
int main(){
    
// Problem 6
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
	
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i;
			Q = j;
			if (P == true && Q == false) P_imply_Q = false; // P => Q
			else P_imply_Q = true;
			if (P_imply_Q != (!P || Q)) ans = false;
		}
	cout << ans << '\n';
}