#include <iostream>
using namespace std;

int main() {
	double a, b, c, d;
	cout << "nhap a va b va c va d ";
	cin >> a >> b >> c >> d;
	double det = a * d - b * c;

	cout << "dinh thuc cua ma tran la " << det << endl;
	return 0;
}