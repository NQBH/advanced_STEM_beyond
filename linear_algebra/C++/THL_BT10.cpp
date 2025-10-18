#include <iostream>
#include <vector>
using namespace std;
int main(){
	int m,n;
	cout <<"Nhap so hang, so cot: ";
	cin >> m >> n;
	vector < vector < int > > A(m, vector <int>(n));
	cout << "Nhap cac phan tu cua ma tran:\n";
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			cin >>A[i][j];
	double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	cout << "Det(A)= " << det;
	return 0;
}
