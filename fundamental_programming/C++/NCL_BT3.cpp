#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c ;

	if (a == b == c > 0) {
		cout << "HLP" << endl;

	}
	else if (a > 0 && b > 0 && c > 0) {
		cout << "HHCN" << endl;

		int  dtxq = 2 * (a + b) * c;
		int  dttp = 2 * (a * b + a * c + b * c);
		float  duong_cheo   = sqrt(a * a + b * b + c * c);
		int  the_tich = a * b * c ;

		cout << "dien tich xung quanh " << dtxq << endl;
		cout << "dien tich toan phan " << dttp << endl;
		cout << "duong cheo hhcn " << duong_cheo << endl;
		cout << "the tich hhcn " << the_tich << endl;

	}
	else {
		cout << "-1"  << endl;
	}

	return 0;
}