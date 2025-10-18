#include <iostream>
using namespace std;
int main() {
	int m, n;
	cout << "Nhap so hang m va so cot n:";
	cin >> m >> n;
	double A[m][n], B[m][n], C[m][n];
	cout << "Nhap ma tran A:\n";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	cout << "Nhap ma tran B:\n";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> B[i][j];
// Cong (+)
	cout << "\nA+B=\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] + B[i][j] << " ";
		cout << endl;
	}
// Tru (-)
	cout << "\nA-B=\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] - B[i][j] << " ";
		cout << endl;
	}
	return 0;
}
