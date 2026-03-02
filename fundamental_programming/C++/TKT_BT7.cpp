#include <iostream>
using namespace std;

int main() {
	double n, num, max, min;
	cout << "hay nhap so luong cac so thuc ";
	cin >> n;
	if (n <= 0) {
		cout << "so luong khong hop le!" << endl;
	}
	cout << "so thuc ban dau la  = ";
	cin >> num;
	max = num;
	min = num;
	for (int i = 1; i <= n; ++i) {
		cout << "hay nhap so thuc tiep theo " << i << "= ";
		cin >> num;
		if (max < num) {
			max = num;
		}
		if (min > num) {
			min = num;
		}
	}
	cout << "\n ket qua la:" << endl;
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	return 0;
}
