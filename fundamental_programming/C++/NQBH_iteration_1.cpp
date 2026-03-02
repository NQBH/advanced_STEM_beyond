#include <iostream>
using namespace std;

int main() {
	// for loop
	for (int i = 1; i <= 100; ++i) { // nếu body của vòng for chỉ có 1 lệnh thì không cần dấu { }
		cout << "i = " << i << ' ';
	} // biến i sẽ tự động mất ngay khi kết thúc vòng for
	// cout << i; // error: i đã chết sau khi hết vòng for
	int i; // phạm vi sử dụng (scope) của biến i sẽ xuyên suốt hàm main (trừ khi chủ động hủy biến này)
	for (i = 1; i <= 50; i += 2) {
		cout << "i = " << i << ' ';
	} // biến i vẫn sống & đang giữ giá trị 51
	cout << "\ni = " << i << ' ';

	// while loop
	i = 1;
	int S = 0;
	while (S < 1000) {
		S += i; // tương đương với S = S + i;
		++i; // tương đương với i = i + 1;
	}
	cout << "i = " << i << '\n';
	cout << "S = " << S - i + 1 << '\n';

	// break vs. continue
	for (int i = 1; i <= 1000; ++i) {
		if (i * i == 100) break; // tìm được mục tiêu: dừng hoàn hoàn vòng for
		if (i * i != 100) continue; // bỏ qua vòng lặp hiện tại & chuyển tới vòng lặp kế
		// các lệnh nằm ngoài chỉ thị break & continue
		cout << i << ' ';
	}
}