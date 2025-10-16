#include <iostream>
#include <vector>
using namespace std;
int main() {
	int m, n, k;
	cout << " nhap so cot " << endl;
	cin >> m >> n;
	cout << " nhap so cot k " << endl;
	cin >> k;
	vector<vector<int>> a(m, vector<int>(n)), b(n, vector<int>(k));
	cout << " nhap ma tran a " << endl;
	for (int i = 0; i < m; i++) for(int j = 0; j < n ; j ++ )
		cin >> a[i][j];
	cout << " nhap ma tran b " << endl;
	for (int i = 0; i < n; i++) for (int j = 0; j < k; j++)
		cin >> b[i][j];
	vector<vector<int>> c(m, vector<int>(k, 0));
	for (int i = 0; i< m ; i++ ) for(int k = 0 ; k < n ; k ++ )
		for (int j = 0; j < k; j++)
			c[i][j] += a[i][k] * b[k][j];
	cout << " ma tran tich la " << endl;
	for (int i = 0; i < m; i ++ ) for (int j = 0; j < n ; j ++ )
		cout << c[i][j] << " ";
	return 0;

}