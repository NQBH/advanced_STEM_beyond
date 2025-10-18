#include <iostream>
using namespace std;
int main() {
	int m, n;
	cout << "Nhap so hang m:";
	cin >> m;
	cout << "Nhap so cot n:";
	cin >> n;
	double A[m][n];
	cout << "Nhap cac phan tu cua ma tran A: \n";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	cout << "\nMa tran A:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	return 0;
}