#include <iostream>
using namespace std;
int main() {
	int m, n;
	cout << "Nhap so hang m va so cot n:";
	cin >> m >> n;
	double A[m][n];
	cout << "Nhap ma tran A: \n";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	cout << "\nMa tran chuyen vi A^T:\n";
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	return 0;
}
