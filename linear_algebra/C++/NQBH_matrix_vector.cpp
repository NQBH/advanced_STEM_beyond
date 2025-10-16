#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num_row, num_col;
	cin >> num_row >> num_col;

	// declare & initialize a vector of vectors
	vector<vector<int>> matrix(num_row, vector<int>(num_col));

	// initialize & acess elements
	for (int i = 0; i < num_row; ++i) {
		for (int j = 0; j < num_col; ++j) {
			matrix[i][j] = i * num_col + j + 1; // example initialization
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}

	// input matrix
	int m, n;
	cin >> m >> n;
	vector<vector<int>> A(m, vector<int>(m));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) cin >> A[i][j];

	// output matrix
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) cout << A[i][j];

	// input vector b
	int p;
	cin >> p;
	vector<int> b(p);
	for (int i = 0; i < p; ++i) cin >> b[i];

	if (m != p) cout << "Impossible";
	else {
		vector<vector<int>> Ab(m, vector<int>(n + 1));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j <= n; ++j) Ab[i][j] = 0; // do it
	}

	// BT2
	// (b) nhan 1 hang r voi hang so thuc alpha
	int m, n;
	cin >> m >> n;
	vector<vector<int>> A(m, vector<int>(n));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) cin >> A[i][j];

	int r; // r: hang muon nhan alpha vao
	cin >> r;
	double alpha;
	cin >> alpha;
	for (int i = 0; i < n; ++i)
		A[r][i] *= alpha;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) cout << A[i][j] << " ";
		cout << '\n';
	}


}