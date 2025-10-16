#include <iostream>
#include <vector>
using namespace std;
int main() {
	int m, n, c;
	cout << " so hang " << endl;
	cin >> m;
	cout << " so cot " << endl;
	cin >> n;
	vector<vector<int>> A(m, vector<int>(n));
	cout << " nhap ma tran " << endl;
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
		cin >> A[i][j];

	}
	cout << " nhap so c " << endl;
	cin >> c;
	cout << " ma tran sau khi nhan voi so c " << endl;
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
		cout << A[i][j] * c << " ";
		cout << endl;
		return 0;
	}
}