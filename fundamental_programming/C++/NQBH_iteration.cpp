#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i <= 100; ++i) { // cho biến i kiểu số nguyên chạy từ giá trị 1 cho tới 100 với bước nhảy bằng 1
		cout << "i = " << i << ' ';
	} // hết vòng for thì biến i tự biến mất

	int i;
	for (i = 1; i <= 100; ++i) {
		cout << "Do homework " << i << '\n';
	} // hết vòng for thì biến i vẫn giữ giá trị 100
	for (i = 101; i <= 500; ++i) {
		cout << "Eat pho " << i << '\n';
	} // hết vòng for thì biến i vẫn giữ giá trị 500

	// Compute sum of 1st n positive integers -- Tính tổng của n số nguyên dương đầu tiên
	int n, S1 = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) { // nếu body của vòng for chỉ có 1 lệnh duy nhất thì không cần bao bởi cặp { }
		S1 += i; // tương đương với S1 = S1 + i;
	}

	// Tính tổng n số tự nhiên <= 1000 lớn nhất có thể
	S1 = 0; // reset value of S1: khởi tạo lại giá trị của S1
	i = 1;
	while (S1 <= 1000) {
		S1 += i; // tương đương với S1 = S1 + i;
		++i; // tương đương i = i + 1;
	}

	S1 = 0, i = 1;
	do {
		S1 += i;
		++i;
	} while (S1 <= 1000);
	
	// continue vs. break
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		if (i == 3) continue; // bỏ qua các lệnh bên dưới của vòng lặp hiện tại, chuyển tới vòng lặp tiếp theo
		if (i * i == 100) break; // đã tìm được i thỏa mãn điều kiện, ngưng cả vòng lặp for hoàn toàn, chuyển tới lệnh tiếp theo ngay sau vòng for
		// các lệnh nằm ngoài phạm vi của chỉ thị break & continue
		S1 += i;
		if (S1 & 1) cout << "S is odd\n";
		else cout << "S is even\n";
	}
}