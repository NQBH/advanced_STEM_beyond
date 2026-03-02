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

int main() {
	for (int i = 1; i <= 30; ++i) print_hello(i);

	tong_hieu_tich_thuong(2, 3);
	int a, b;
	cin >> a >> b;
	tong_hieu_tich_thuong(a, b);
}