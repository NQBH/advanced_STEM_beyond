#include <iostream>
using namespace std ;

int main() {
	float n, a, soAm, soDuong, so0;
	cout << "nhap cac so thuc a : "; cin >> n;
	if (
	    n <= 0) {
		cout << "khong hop le";
	}
	else {
		for (int i = 1; i <= n; ++i) {
			cout << "so thuc a " << i << " = "; cin >> a;
			if (a > 0) {
				soDuong++;
			}
			else if (a < 0) {
				soAm++;
			}
			else {
				so0++;
			}
		}
		cout << "so so duong la : " << soDuong << endl;
		cout << "so so am la : " << soAm << endl;
		cout << "so so 0 la : " << so0 << endl;
	}
	return 0;
}

