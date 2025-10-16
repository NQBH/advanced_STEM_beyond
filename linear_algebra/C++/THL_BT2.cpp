#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n;
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	vector < vector < int > > A(m, vector <int>(n));
	vector < vector < int > > B(m, vector <int>(n));
	vector < vector < int > > C(m, vector <int>(n));
	cout << "Nhap cac phan tu cua ma tran A: " << "(" << m << "x" << n << "):\n";
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> A[i][j];
	cout << "Nhap cac phan tu cua ma tran B: " << "(" << m << "x" << n << "):\n";
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> B[i][j];
	cout << "\nTong A+B:\n";
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			C[i][j] = A[i][j] + B[i][j];
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nTru A-B:\n";
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			C[i][j] = A[i][j] - B[i][j];
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
