#include <cmath> // thư viện toán để xài các hàm toán học thông dụng
#include <iostream> // input output: thư viện để nhập xuất dữ liệu
using namespace std; // standard namespace: để viết các hàm chuẩn cho gọn: không cần khai báo std:: đằng trước

int main() { // hàm chính: kiểu trả về là số nguyên (integer)
	cout << "Hello world.\n" ; // Phải dùng dấu " " cho chuỗi ký tự thay vì ' ' cho 1 ký tự

	// định nghĩa hằng số: số không thay đổi (constant)
	#define Pi 3.14159 // không cần dấu ; cuối lệnh
	int a = 2; // khai báo 1 biến a có kiểu dữ liệu là số nguyên & có giá trị bằng 2
	int b = 10;

	// tính chu vi hình tròn C = 2 * pi * r
	// float r = 1.25;
	float r;
	cout << "Nhập giá trị của bán kính đường tròn vào r = ";
	cin >> r; // nhập giá trị của bán kính đường tròn vào
	float C = 2 * Pi * r;
	cout << "Chu vi hình tròn bán kính r = " << r << " bằng " << C << '\n'; // '\n': xuống dòng

	// tính diện tích hình tròn S = pi * r ^ 2
	float S = Pi * r * r;
	float S1 = Pi * pow(r, 2); // phải khai báo thư viện cmath để xài hàm pow: tính lũy thừa
	cout << "Diện tích hình tròn bán kính r = " << r << " bằng " << S << '\n';
}