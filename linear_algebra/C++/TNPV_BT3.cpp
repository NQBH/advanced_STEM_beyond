#include <iostream>
using namespace std;
int main() {
	int m, n;
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	int A[100][100], B[100][100];
	cout << "Nhap cac phan tu ma tran A: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "A[" << i << "][" << j << "]= ";
			cin >> A[i][j];
		}
	}
	int k;
	cout << "\nNhap so k de nhan: ";
	cin >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = A[i][j] * k;
		}
	}
	cout << "\nMa tran sau khi nhan: ";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
