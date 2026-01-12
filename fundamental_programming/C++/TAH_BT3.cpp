#include <iostream>
#include <math.h>
using namespace std ;
int main () {
	int a , b , c;
	cin >> a >> b >> c;
	if (a == b && a == c) {
		cout << " HLP" << '\n';
	}
	else {
		if (a > 0 && b > 0 && c > 0) {
			cout << "HHCN"  << '\n';
			// tính diện tích xung quanh hình hộp chữ nhật
			float  Sxq = (a + b) * 2 * c;
			cout << "diện tích xung quanh hình hộp chữ nhật " << a << b << c << " bằng " << Sxq << '\n';
			// tính diện tích toàn phần hình hộp chữ nhật
			float Stp = (a + b) * 2 * c + 2 * a * b;
			cout << "diện tích toàn phần hình hộp chữ nhật " << a << b << c << " bằng " << Stp << '\n';
			// tính thể tích hình hộp chữ nhật
			float V = a * b * c;
			cout << "thể tích hình hộp chữ nhật " << a << b << c << " bằng " << V << '\n';
			// tính đường chéo hình hộp chữ nhật
			double d = sqrt(a * a + b * b + c * c);
			cout << "đường chéo hình hộp chữ nhật " << a << b << c << " bằng " << d << '\n';
		}
		else {
			cout << -1;
		}
	}

	return 0;
}