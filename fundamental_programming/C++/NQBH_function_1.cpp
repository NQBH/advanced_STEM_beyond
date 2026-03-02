#include <iostream>
using namespace std;

// hàm in ra "Hello world." 1 lần
void print_hello(int a) { // void: kiểu dữ liệu trống rỗng
	cout << "Hello world from student " << a << '\n';
}

void hcn(long long a, long long b) {
	cout << 2 * (a + b) << ' ' << a * b;
}

int main() {
	for (int i = 1; i <= 20; ++i) print_hello(i);

	hcn(5, 4); // gọi hàm với các giá trị cụ thể của biến số
	long long a, b;
	cin >> a >> b;
	hcn(a, b); // gọi hàm với các biến vừa được khai báo & nhập vào

}