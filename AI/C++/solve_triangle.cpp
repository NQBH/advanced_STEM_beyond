#include <iostream>
#include <cmath>
using namespace std;

// define structure named node
struct node {
	string fact;
	double val;
};

int main() {
	node a, b, c, A, B, C, P, p, S, ha, hb, hc, ma, mb, mc, pa, pb, pc;
	cin >> a.val >> b.val >> c.val;

	// compute perimeter & semi-perimeter
	P.val = a.val + b.val + c.val;
	p.val = P.val / 2;
	cout << "P = " << P.val << "\n";
	cout << "p = " << p.val << "\n";

	// compute area by Heron formula S = sqrt(p(p - a)(p - b)(p - c))
	S.val = sqrt(p.val * (p.val - a.val) * (p.val - b.val) * (p.val - c.val));
	cout << "S = " << S.val << "\n";

	// use cosine theorem to compute angles of triangle given
	double cosA = (b.val * b.val + c.val * c.val - a.val * a.val) / (2 * b.val * c.val);
	double cosB = (c.val * c.val + a.val * a.val - b.val * b.val) / (2 * a.val * c.val);
	double cosC = (a.val * a.val + b.val * b.val - c.val * c.val) / (2 * a.val * b.val);
	A.val = acos(cosA);
	B.val = acos(cosB);
	C.val = acos(cosC);
	cout << "A = " << A.val * 180 / M_PI << "\n";
	cout << "B = " << B.val * 180 / M_PI << "\n";
	cout << "C = " << C.val * 180 / M_PI << "\n";

	// compute heights ha, hb, hc

	// compute medians ma, mb, mc

	// compute bisectors pa, pb, pc

	// compute radiuses of innercircle, outercircle, duong tron bang tiep r, R, ra, rb, rc
}