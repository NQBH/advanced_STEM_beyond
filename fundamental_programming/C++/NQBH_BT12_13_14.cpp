#include <cmath>
#include <iostream>
using namespace std;

int main() {
	// problem 12
	double Sm = 0; // khai báo biến Sm & khởi tạo giá trị 0. kiểu dữ liệu double vì khi m < 0, Sm là số thực
	int m, n;
	cout << "Enter m, n = ";
	cin >> m >> n;
	if (m == 0) Sm = n; // Sm = 1^0 + 2^0 + ... + n^0 = 1 + 1 + ... + 1 = n
	else for (int i = 1; i <= n; ++i) Sm += pow(i, m);
	cout << "Sm = " << Sm << '\n';

	// problem 13
	// 1st solution: use while loop
	Sm = 0; // khai báo biến Sm & khởi tạo giá trị 0. kiểu dữ liệu double vì khi m < 0, Sm là số thực
	int i = 1;
	double M, term = 1; // term := i^m
	cout << "Enter m, M = ";
	cin >> m >> M;
	while (Sm + term <= M) {
		Sm += term;
		++i;
		term = pow(i, m);
	}
	cout << Sm << '\n';

	// 2nd solution
	Sm = 1;
	int max_iteration = 10000;
	for (i = 2; i <= max_iteration; ++i) {
		term = pow(i, m);
		if (Sm + term > M) break;
		else Sm += term;
	}
	cout << Sm << '\n';

	// problem 14
	double A, a;
	cout << "\nEnter A = ";
	cin >> A;
	string true_PIN, input_PIN; // 0 can be at the beginning of PIN, cannot use integer naively
	cout << "\nEnter true PIN = ";
	cin >> true_PIN; // 6 digits, from 0 to 9
	int max_trial; // maximum number of trials
	cout << "\nEnter maximum of trials = ";
	cin >> max_trial;
	bool ok = false;
	for (int i = 1; i <= max_trial; ++i) {
		cout << "\nEnter PIN = ";
		cin >> input_PIN;
		if (input_PIN == true_PIN) {
			ok = true;
			break;
		} else cout << "\nWrong PIN. Re-enter PIN = ";

	}
	if (ok) {
		cout << "Mã PIN đúng. Cho phép rút tiền.\nVui lòng nhập số tiền bạn muốn rút: ...\n";
		cout << "\nEnter a = ";
		cin >> a;
		if (a > A) cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?\n";
		else {
			cout << "Bạn đã rút thành công " << a << " VND.\nSố dư khả dụng: " << A - a << " VND.\n";
			cout << "Bạn muốn in hóa đơn? (Yes/No)?\n";
			string bill;
			cin >> bill;
			if (bill == "Yes") cout << "Đang in hóa đơn. Vui lòng đợi để nhận cả hóa đơn, cash, & thẻ.\n";
			else cout << "Vui lòng đợi để nhận cash, & thẻ.\n";
			cout << "Cảm ơn bạn đã giao dịch tại ngân hàng X.\nVui lòng đánh giá chất lượng dịch vụ.\n";
		}
	} else cout << "Bạn đã bị khóa thẻ. Vui lòng liên hệ chi nhánh ngân hàng X gần nhất để hỗ trợ nhận lại thẻ.\nXin chân thành cảm ơn.\n";

}