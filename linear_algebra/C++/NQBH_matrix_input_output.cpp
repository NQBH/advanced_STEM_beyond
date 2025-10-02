#include <iostream>
using namespace std;

int main() {
	// Use static 2D arrays to represent matrices
	// This is the simplest method for matrices with fixed dimensions known at compile time.
	const int num_row = 3;
    const int num_col = 4;
    int a[num_row][num_col] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // input matrix with numbers of rows & columns input from keyboard

    
    // acessing elements a[0][1]
    cout << "Element a[0][1] = " << a[0][1] << '\n';

    // acessing elements a[i][j] with i, j input from keyboard

    // print matrix
    for (int i = 0; i < num_row; ++i) {
    	for (int j = 0; j < num_col; ++j)
    		cout << a[i][j] << " ";
    	cout << '\n';
    }
}