#include <iostream>
using namespace std;
int main() {
	int m, n;
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	int A[100][100], B[100][100];
	cout << "Nhap so phan tu : \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "A[" << i << "][" << j << "]= ";
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			B[j][i] = A[i][j];
		}
	}
	cout << "\nMa tran goc: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nMa tran chuyen vi: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}
}
