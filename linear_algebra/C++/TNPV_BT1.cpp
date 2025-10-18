#include <iostream>
using namespace std;

int main() {
	int m, n;
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	int A[100][100];
	cout << "Nhap cac phan tu cua ma tran A: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "A[" << i << "][" << j << "] =";
			cin >> A[i][j];
		}
	}
	cout << "Ma tran A: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
