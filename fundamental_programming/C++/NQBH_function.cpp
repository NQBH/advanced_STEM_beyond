#include <cmath>
#include <iostream>
using namespace std;

void print_hello(int a) { // kiểu void: trống rỗng, không cần giá trị trả về
	cout << "Hello world from student " << a << '\n';
	// không cần return
}

void tong_hieu_tich_thuong(long long a, long long b) {
	cout << a + b << ' ' << a - b << ' ' << a * b << ' ';
	if (b == 0) cout << "divisible by zero\n";
	else cout << a / b;
}

int tong(int a, int b) {
	return a + b;
}

// function f(x) = 3 * x + 5
long long f(int x) { // vì khi x kiểu int đủ lớn (sát 2 tỷ) thì f(x) vượt quá kiểu int, phải xài long hoặc long long
	return 3 * x + 5; // 3x + 5 thuộc kiểu long hoặc long long
}

long long g(int& x, int& y) { // khai báo tham biến: đổi giá trị của biến số trong hàm đó
	x *= 2;
	y *= 3;
	return 3 * x + 5 * y; // 3x + 5 thuộc kiểu long hoặc long long
}

// absolute value function (hàm trị tuyệt đối) f(x) = |x|, = x if x >= 0 & = -x if x < 0
double abs_function(double x) {
	if (x >= 0) return x;
	else return -x; // if x < 0
}

// round function: hàm làm tròn
double round(double x); // khai báo hàm: để tiện sử dụng ở nhiều file khác trong mã nguồn

double round(double x) {
	if (x >= 0) return floor(x + 0.5);
	else return -floor(-x + 0.5);
}

int main() {
	/*
	for (int i = 1; i <= 30; ++i) print_hello(i);

	tong_hieu_tich_thuong(2, 3);
	int a, b;
	cin >> a >> b;
	tong_hieu_tich_thuong(a, b);

	// xài hàm f
	int x = 100;
	cin >> x;
	cout << f(x) << '\n';; // f(x) là 1 số nguyên long long: có thể xài tùy ý
	int y = 10 * x;
	cout << f(x) + 2 * f(y) << '\n';

	// minh họa cách lồng hàm
	x = -100;
	cout << abs(f(x)) << '\n';
	*/
	int x = 2, y = 3;
	cout << g(x, y) << '\n'; // long long
	// debug: sau khi gọi hàm g(x, y) xong thì giá trị của 2 biến x, y như thế nào?
	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';

}