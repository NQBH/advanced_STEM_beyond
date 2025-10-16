#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	int m;
	cout << "nhap so hang, cot: ";
	cin >> n >> m;

	vector<vector<int>> A(m, vector<int>(n, 0));

	//-----------------------------------------

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	//--------------------------------------
	int k;
	cout << "nhap so phan tu cua vector B: ";
	cin >> k;
	vector<vector<int>> B(k, vector<int>(1));
	if (k != m) {
		cout << "IMPOSSIBLE!!!";
		return 0;
	}

	for (int i = 0; i < m; ++i) {
		cin >> B[i][0];
	}
	
	for (int i = 0; i < m; ++i) {
		cout << B[i][0] <<endl;
	}

	//-----------------------------------------------

	cout << "ma tran bo sung [A|b]:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << "|      " << B[i][0] << endl;
	}

	return 0;
}