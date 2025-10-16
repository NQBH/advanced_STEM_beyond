#include <iostream> // phải có dòng này để nhập xuất được
using namespace std; // phải có dòng này để khỏi cần viết std::

int main() { // hàm chính: phải có dòng này để chương trình chạy được
	int x; // int viết tắt của integer: số nguyên. Dòng này khai báo biến x là 1 số nguyên
	cin >> x; // nhập giá trị của biến x vào
	cout << x; // xuất giá trị của biến ra
	if (x == 1) {
		cout << "right";
	} else { // x != 1
		cout << "wrong.";
	}
	cout << '\n';

	string name;
	int si_so_co_mat;
	cin >> si_so_co_mat;
	for (int i = 1; i <= 31; ++i) {
		cout << "Tên bạn sinh viên thứ " << i << ": ";
		cin >> name;
		cout << '\n';
	}  // vòng lặp: cho 1 biến chạy i chạy từ số đầu tới số cuối
}