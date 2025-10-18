#include <iostream>
using namespace std;
int main() {
	int n;
	cout << "Nhap kich thuoc ma tran: ";
	cin >> n;
	int A[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "A[" << i << "][" << j << "] = ";
			cin >> A[i][j];
		}
		cout << endl;
	}
	cout << "Ma tran vua nhap: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	int duongcheo = true;
	int tren = true;
	int duoi = true;
	int doixung = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && A[i][j] != 0) {
				duongcheo = false;
			}
			if (i > j && A[i][j] != 0) {
				tren = false;
			}
			if (i < j && A[i][j] != 0) {
				duoi = false;
			}
			if (A[j][i] != A[i][j]) {
				doixung = false;
			}
		}
	}
	cout << "Ket qua:\n";
	if (duongcheo = true) {
		cout << "day la ma tran duong cheo\n";
	}
	else {
		cout << "day KHONG la ma tran duong cheo\n";
	}
	if (tren = true) {
		cout << "day la ma tran tam giac tren\n";
	}
	else {
		cout << "day KHONG la ma tran tam giac tren\n";
	}
	if (duoi = true) {
		cout << "day la ma tran tam giac duoi\n";
	}
	else {
		cout << "day KHONG la ma tran tam giac duoi\n";
	}
	if (doixung = true) {
		cout << "day la ma tran doi xung\n";
	}
	else {
		cout << "day KHONG la ma tran doi xung\n";
	}
	return 0;
}
