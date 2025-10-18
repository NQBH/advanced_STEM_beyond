#include <iostream>
using namespace std;
int main() {
	int m, n, p;
	cout << "Nhap so hang m va so cot n cua A:";
	cin >> m >> n;
	cout << "Nhap so cot p cua B:";
	cin >> p;
	double A[m][n], B[n][p], C[m][p];
	cout << "Nhap ma tran A:\n";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	cout << "Nhap ma tran B:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			cin >> B[i][j];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < p; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	cout << "\nMa tran C=A*B:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
	return 0;
}
