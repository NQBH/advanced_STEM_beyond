#include <iostream>
#include <math.h>
using namespace std ;
int main () {
	double a ;
	double b ;
	cin >> a ;
	cin >> b ;
	// tính chu vi hình chữ nhật
	int C = (a + b) * 2;
	// tính diện tích hình chữ nhật
	int S = a * b ;
	cout << "chu vi hình chữ nhật a  = " << a << b << " bang " << C << '\n';
	cout << "diện tích hình chữ nhật a  = "  << a << b << " bang " << S << '\n';
	// tính độ dài hai đường chéo hình chữ nhật
	double d = sqrt(a * a + b * b);
	cout << "độ dài hai đường chéo hình chữ nhật a  = "  << a << b << " bang " << d << '\n';
	return 0;
}