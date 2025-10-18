#include <iostream>
using namespace std;
int main() {
	double a, b, c, d;
	cout << "a11: ";
	cin >> a;
	cout << "a12: ";
	cin >> b;
	cout << "a21: ";
	cin >> c;
	cout << "a22: ";
	cin >> d;
	double det = a * d - b * c;
	cout << "\n---Ma tran---\n";
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
	cout << "det = " << det;
	return 0;
}
