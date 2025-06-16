#include <bits/stdc++.h>
#define ll long long
using namespace std;

const double INVALD_VAL = 999.0;
const char T = 'T';
const char D = 'D';
const char H = 'H';
const char E = 'E';

void solve(double &nT, double &nD, double &nH) {
	if (nH == INVALD_VAL) {
		nH = nT + 0.5555 * (6.11 * exp(5417.7530 *
		                               (1.0 / 273.16 - 1.0 / (nD + 273.16))) -
		                    10.0);
	} else if (nT == INVALD_VAL) {
		nT = nH - 0.5555 * (6.11 * exp(5417.7530 *
		                               (1.0 / 273.16 - 1.0 / (nD + 273.16))) -
		                    10.0);
	} else {
		nD = 1.0 / ((1.0 / 273.16) -
		            ((log((((nH - nT) / 0.5555) + 10.0) / 6.11)) / 5417.7530)) -
		     273.16;
	}
}

int main(void) {
	while (true) {
		bool isEnd = false;
		char letter = E;
		double nT, nD, nH;
		nT = nD = nH = INVALD_VAL;
		for (int i = 0; !isEnd && i < 2; i++) {
			cin >> letter;
			switch (letter) {
			case T: {
				cin >> nT;
				break;
			}
			case D: {
				cin >> nD;
				break;
			}
			case H: {
				cin >> nH;
				break;
			}
			default: {
				isEnd = true;
				break;
			}
			}
		}
		if (isEnd == true) {
			break;
		} else {
			solve(nT, nD, nH);
			cout << fixed << setprecision(1) << "T " << nT << " D " << nD
			     << " H " << nH << endl;
		}
	}
	return 0;
}