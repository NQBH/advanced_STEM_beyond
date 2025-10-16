#include <iostream>
using namespace std;

int main() {
	bool P, Q, R, left, right, ans;


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
	cout << "1) p->q ≡ ¬p∨q " << (ans ? "dung" : "Sai") << '\n';

	// P -> Q ≡ ¬Q -> ¬P
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			if (P == true && Q == false) left = false; else left = true; 
			if (!Q == true && !P == false) right = false; else right = true;
			if (left != right) ans = false;
		}
	cout << "2) p->q ≡ ¬q->¬p" << (ans ? "dung" : "Sai") << '\n';

	// P ∨ Q ≡ ¬P -> Q
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = P || Q;
			if (!P == true && Q == false) right = false; else right = true;
			if (left != right) ans = false;
		}
	cout << "3) p∨q ≡ ¬p->q " << (ans ? "dung" : "Sai") << '\n';

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
	cout << "4) p∧q ≡ ¬(p->¬q) " << (ans ? "dung" : "Sai") << '\n';

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
	cout << "5) ¬(p->q) ≡ p∧¬q " << (ans ? "dung" : "Sai") << '\n';

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
	cout << "A) p<->q ≡ (p->q)∧(q->p) " << (ans ? "dung" : "Sai") << '\n';

	// P <-> Q ≡ ¬P <-> ¬Q
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = (P == Q);
			right = ((!P) == (!Q));
			if (left != right) ans = false;
		}
	cout << "B) p<->q ≡ ¬p<->¬q " << (ans ? "dung" : "Sai") << '\n';

	// P <-> Q ≡ (P∧Q) ∨ (¬P∧¬Q)
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = (P == Q);
			right = (P && Q) || ((!P) && (!Q));
			if (left != right) ans = false;
		}
	cout << "C) p<->q ≡ (p∧q)∨(¬p∧¬q) " << (ans ? "dung" : "Sai") << '\n';

	// ¬(P<->Q) ≡ P<->¬Q
	ans = true;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j) {
			P = i; Q = j;
			left = !(P == Q);
			right = (P == (!Q));
			if (left != right) ans = false;
		}
	cout << "D) ¬(p<->q) ≡ p<->¬q " << (ans ? "dung" : "Sai") << '\n';


	return 0;
}