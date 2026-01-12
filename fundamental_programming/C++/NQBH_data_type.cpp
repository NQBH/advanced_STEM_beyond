#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//-----------------------------------------------------------------------------//
	// các kiểu dữ liệu & các phép toán cơ bản: NMLT, pp. 41--45
	//-----------------------------------------------------------------------------//

	double a, b;
	cin >> a >> b;

	// 4 basic arithmetic operations: 4 phép toán số học cơ bản
	double S = a + b, D = a - b, P = a * b;
	cout << "Sum S = " << S << '\n';
	cout << "Difference D = " << D << '\n';
	cout << "Product P = " << P << '\n';
	if (b == 0) cout << "Error: Divisible by 0";
	else {
		double Q = a / b;
		cout << "Quotient Q = " << Q << '\n';
	}

	// 6 basic bitwise operations: 6 phép toán cơ bản trên từng bit
	int x, y;
	cin >> x >> y;
	cout << "x & y = " << (x & y) << '\n'; // bitwise and
	cout << "x | y = " << (x | y) << '\n'; // bitwise or
	cout << "x ^ y = " << (x ^ y) << '\n'; // bitwise xor
	cout << "~x = " << (~x) << '\n'; // not bit
	int n;
	cin >> n;
	cout << "x << n = " << (x << n) << '\n'; // left shift: = x * 2 ^ n
	cout << "x >> n = " << (x >> n) << '\n'; // right shift	= floor(x / (2 ^ n))

	//-----------------------------------------------------------------------------//
	// thư viện hàm có sẵn: NMLT, pp. 66--70
	//-----------------------------------------------------------------------------//

	// absolute value function: hàm trị tuyệt đối
	float X, absX;
	cin >> X;

	// method 1: dùng if else để viết hàm trị tuyệt đối
	if (X >= 0) absX = X;
	else absX = -X;
	cout << "Absolute value of X = " << absX << '\n';

	// method 2: dùng phép toán luận lý
	absX = (X >= 0) * X + (X < 0) * (-X);
	cout << "Absolute value of X = " << absX << '\n';

	// method 3: dùng hàm có sẵn double fabs(double x) trong thư viện cmath
	cout << fabs(X) << '\n';

	//-----------------------------------------------------------------------------//
	// characters & strings: ký tự & chuỗi: NMLT pp. 52--58
	//-----------------------------------------------------------------------------//
	
	char c = 'a'; // char: kiểu dữ liệu ký tự character
	cout << "character c = " << c << '\n';
	string s, t; // string: kiểu dữ liệu chuỗi
	s = "Nguyen Van A";
	t = " hoc gioi.";
	cout << s + t << '\n'; // nối 2 chuỗi lại: dễ hơn cú pháp của ngôn ngữ C nhiều: nên ưu tiên dùng C++ cho chuỗi ký tự

	//-----------------------------------------------------------------------------//
	// phép gán & lệnh viết ngắn: NMLT pp. 58--59
	//-----------------------------------------------------------------------------//

	cin >> x >> y;
	--x; // tương đương với x = x - 1;
	cout << "x = " << x << '\n';
	y += 3; // tương đương với y = y + 3;
	y -= x; // tương đương với y = y - x;
	cout << "y = " << y << '\n';
	x = 9;
	x <<= 3; // tương đương với x = x << 3;
	cout << "x = " << x << '\n';
	x >>= 2; // tương đương với x = x >> 2;
	cout << "x = " << x << '\n';

	// Problem 4: Check Table 2.1, NMLP, p. 68
	cin >> a;
	if (a < 0) cout << "Error: x must be nonnegative"; // căn bậc 2 chỉ xác định với số thực không âm
	else cout << sqrt(a) << '\n';
}