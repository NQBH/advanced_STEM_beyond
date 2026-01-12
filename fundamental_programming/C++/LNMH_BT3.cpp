#include <iostream>
#include <math.h>
using namespace std ;
int main () {
	int a , b , c ;
	cin >> a >> b >> c ;
	if ( a == b && a == c ) {
		cout << "HLP" << '\n' ;
	}
	else if ( a > 0 && b > 0 && c > 0 ) {
		cout << "HHCN" << '\n'  ;
		// tính diện tích xung quanh của hình hộp chữ nhật
		float Sxp = ( a + b ) * 2 * c ;
		cout << "dien tich xung quanh hhcn = " << Sxp << '\n';
		// tính diện tích toàn phần của hình hộp chữ nhật
		float Stp = ( a + b ) * 2 * c + 2 * a * b ;
		cout << "dien tich toan phan hhcn = " << Stp << '\n';
		// tính thể tích hình hộp chữ nhật
		float V = a * b * c ;
		cout << "the tich hhcn = " << V << '\n';
		// tính đường chéo của hình hộp chữ nhật
		double DC = sqrt( a * a + b * b + c * c) ;
		cout << "duong cheo cua hhcn = " << DC << '\n';
	}

	else  {
		cout << -1;
	}
	return 0;
}
