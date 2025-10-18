#include <iostream>
using namespace std;
int main() {
	int n;
	cout << "Nhap kich thuoc ma tran: ";
	cin >> n;
	if (n <= 0) {
		cout << "Vui long nhap so nguyen duong!" << endl;
		return 0;
	}
	cout << "\n---Ma tran 0---\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << 0 << " ";
		}
		cout << endl;
	}
	cout << "\n---Ma tran don vi---\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
