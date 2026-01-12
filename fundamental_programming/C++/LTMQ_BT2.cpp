#include <cmath>
#include <iostream>
using namespace std;
int main() {
	float a, b;
	cout << "nhap a" << endl;
	cin >> a;
	cout << "nhap b" << endl;
	cin >> b;
	float dientich, chuvi, duongcheo;
	dientich = a * b;
	chuvi = a + b / 2;
	duongcheo = sqrt(a * a + b * b);
	cout << "dientich =" << dientich;
	cout << "chuvi =" << chuvi;
	cout << "duongcheo =" << duongcheo;
	return 1;
}
