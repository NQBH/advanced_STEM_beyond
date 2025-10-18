#include <iostream>
using namespace std;
int main() {
	int m, n;
	double c;
	cout << "Nhap so hang m va so cot n:";
	cin >> m >> n;
	cout << "Nhap hang so c:";
	cin >> c;
	double A[m][n];
	cout << "Nhap ma tran A:\n";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	cout << "\nMa tran c*A:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << c*A[i][j] << " ";
		cout << endl;
	}
	return 0;
}
