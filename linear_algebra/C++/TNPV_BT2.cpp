#include <iostream>
using namespace std;

int main() {
	int m, n;
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	int A[100][100], B[100][100], C[100][100];
	cout << "Nhap cac phan tu ma tran A: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "A[" << i << "][" << j << "] = ";
			cin >> A[i][j];
		}
	}
	cout << "Nhap cac phan tu ma tran B: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "B[" << i << "][" << j << "] = ";
			cin >> B[i][j];
		}
	}
	int Tong[100][100], Hieu[100][100];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			Tong[i][j] = A[i][j] + B[i][j];
			Hieu[i][j] = A[i][j] - B[i][j];
		}
	}
	cout << "Ma tran tong A+B: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << Tong[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Ma tran hieu A-B: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << Hieu[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
