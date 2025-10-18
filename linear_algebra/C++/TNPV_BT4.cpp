#include <iostream>
using namespace std;
int main() {
	int m, n, p;
	cout << "Nhap so hang cua A: ";
	cin >> m;
	cout << " Nhap so cot cua A dong thoi so hang cua B: ";
	cin >> n;
	cout << "Nhap so cot cua B: ";
	cin >> p;
	int A[100][100], B[100][100], C[100][100];
	cout << "Nhap so phan tu cua ma tran A: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "A[" << i << "][" << j << "]= ";
			cin >> A[i][j];
		}
	}
	cout << "Nhap so phan tu cua ma tran B: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cout << "B[" << i << "][" << j << "]= ";
			cin >> B[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	cout << "\n Ma tran sau khi nhan: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
