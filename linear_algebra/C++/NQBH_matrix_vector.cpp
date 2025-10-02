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
}