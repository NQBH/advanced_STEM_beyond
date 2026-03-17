#include <iostream>
using namespace std;

// hàm in ra "Hello world." 1 lần
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

void hcn(long long a, long long b) {
	cout << 2 * (a + b) << ' ' << a * b;
}

// Viết hàm nhân đôi f(x) = 2 * x
long long f(int x) { // khi x tiến tới giới hạn của kiểu int, thì 2 * x sẽ vượt quá kiểu int, nên phải xài long long cho output của hàm
	return 2LL * x; 
}

// Viết hàm tính giá trị tuyệt đối của số thực
double abs_function(double x) {
	if (x >= 0) return x;
	else return -x; // if x < 0
}

// Viết hàm tính f(x,y) = 2 * x + 3 * y
long long f(int& x, int& y) { // tham biến &: thay đổi giá trị của biến số sau khi gọi hàm
	// câu hỏi: có thể thay đổi giá trị của biến số x & y không sau khi gọi hàm
	long long res = 2 * x + 3 * y;
	x *= 2; // x = 2 * x;
	y *= 5; // y = 5 * y;
	return res;
}

int main() {
	/*
	for (int i = 1; i <= 20; ++i) print_hello(i);

	hcn(5, 4); // gọi hàm với các giá trị cụ thể của biến số
	long long a, b;
	cin >> a >> b;
	hcn(a, b); // gọi hàm với các biến vừa được khai báo & nhập vào
	

	// sử dụng hàm nhân đôi
	cout << f(2147483647) << '\n'; // output: 20
	int x = 10;
	cin >> x;
	cout << f(x) << '\n';

	// sử dụng hàm trị tuyệt đối
	cout << abs_function(-3.75) << '\n'; // sử dụng hàm với giá trị cụ thể của biến số
	int y;
	cin >> y;
	cout << abs_function(y) << '\n'; // sử dụng hàm với biến số được khai báo & đã nhập giá trị vào

	// hàm lồng hàm: hàm hợp
	x = -5;
	cout << abs_function(f(5)) << '\n';
	*/
	int x = 3, y = 4;
	cout << f(x, y) << '\n';
	// debug: vá lỗi chương trình
	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';
}