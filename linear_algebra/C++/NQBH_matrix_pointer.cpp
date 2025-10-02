#include <iostream>
using namespace std;

int main() {
	int num_row, num_col;
	cin >> num_row >> num_col;

	// allocate memory for rows (array of pointers)
	int** matrix = new int*[num_row];

	// allocate memory for columns in each row
	for (int i = 0; i < num_row; ++i) matrix[i] = new int[num_col];

	// initialize & acess elements
	for (int i = 0; i < num_row; ++i) {
		for (int j = 0; j < num_col; ++j) {
			matrix[i][j] = i * num_col + j + 1; // Example initialization
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}

	// deallocate memory
	for (int i = 0; i < num_row; ++i) delete[] matrix[i];
	delete[] matrix;
}