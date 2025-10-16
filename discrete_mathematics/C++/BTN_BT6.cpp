#include <iostream>
using namespace std;

int main() {
	bool P, Q, R, left, right, ans;

	cout << "=== Kiem tra cac quy tac logic (Table 7 + 8) ===\n\n";

	// P -> Q ≡ ¬P ∨ Q
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			if (P == true && Q == false) left = false;
			else left = true;
			right = (!P || Q);
			if (left != right) ans = false;
		}
	cout << "1) P->Q ≡ ¬P∨Q: " << (ans ? "Dung" : "Sai") << '\n';

	// P -> Q ≡ ¬Q -> ¬P
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			if (P == true && Q == false) left = false; else left = true;
			if (!Q == true && !P == false) right = false; else right = true;
			if (left != right) ans = false;
		}
	cout << "2) P->Q ≡ ¬Q->¬P: " << (ans ? "Dung" : "Sai") << '\n';

	// P ∨ Q ≡ ¬P -> Q
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = P || Q;
			if (!P == true && Q == false) right = false; else right = true;
			if (left != right) ans = false;
		}
	cout << "3) P∨Q ≡ ¬P->Q: " << (ans ? "Dung" : "Sai") << '\n';

	// P ∧ Q ≡ ¬(P -> ¬Q)
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = P && Q;
			if (P == true && (!Q) == false) right = false; else right = true;
			right = !right;
			if (left != right) ans = false;
		}
	cout << "4) P∧Q ≡ ¬(P->¬Q): " << (ans ? "Dung" : "Sai") << '\n';

	// ¬(P->Q) ≡ P ∧ ¬Q
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			if (P == true && Q == false) left = false; else left = true;
			left = !left;
			right = (P && !Q);
			if (left != right) ans = false;
		}
	cout << "5) ¬(P->Q) ≡ P∧¬Q: " << (ans ? "Dung" : "Sai") << '\n';

	// ----- Table 8 -----
	// P <-> Q ≡ (P->Q) ∧ (Q->P)
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = (P == Q);
			if (P == true && Q == false) right = false; else right = true;
			if (Q == true && P == false) R = false; else R = true;
			right = right && R;
			if (left != right) ans = false;
		}
	cout << "A) P<->Q ≡ (P->Q)∧(Q->P): " << (ans ? "Dung" : "Sai") << '\n';

	// P <-> Q ≡ ¬P <-> ¬Q
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = (P == Q);
			right = ((!P) == (!Q));
			if (left != right) ans = false;
		}
	cout << "B) P<->Q ≡ ¬P<->¬Q: " << (ans ? "Dung" : "Sai") << '\n';

	// P <-> Q ≡ (P∧Q) ∨ (¬P∧¬Q)
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = (P == Q);
			right = (P && Q) || ((!P) && (!Q));
			if (left != right) ans = false;
		}
	cout << "C) P<->Q ≡ (P∧Q)∨(¬P∧¬Q): " << (ans ? "Dung" : "Sai") << '\n';

	// ¬(P<->Q) ≡ P<->¬Q
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = !(P == Q);
			right = (P == (!Q));
			if (left != right) ans = false;
		}
	cout << "D) ¬(P<->Q) ≡ P<->¬Q: " << (ans ? "Dung" : "Sai") << '\n';

	cout << "\n=== Hoan tat kiem tra ===\n";
	return 0;
}