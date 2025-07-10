#include <stdio.h>
#include <time.h>
#define num_row 5
#define num_col 7
#define max_row 20
#define max_col 20

int size_input(int max_val) {
	int val;
	while (1) {
		scanf("%d", &val);
		if (val < 1 || val > max_val) printf("Invalid value\n");
		else break;
	}
	return val;
}

void array_2D_input(int a[max_row][max_col], int& m, int& n) {
	printf("Number of rows (<=%d): ", max_row);
	m = size_input(max_row);
	printf("Number of columns (<=%d): ", max_col);
	n = size_input(max_col);
	printf("Input elements: \n");
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
}

void array_2D_output(int a[max_row][max_col], int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) printf("%d", &a[i][j]);
		printf("\n");
	}
}

int main() {
	// initialization 1D array
	/*
	int a[5][5], x = 2, y = 3;
	a[0][0] = a[4][4] = 0;
	a[y - x][(x + y) / 2] = 5; // a[1][2] = 5;
	a[1][4] = a[1][2] * 8;
	*/
	int a[num_row][num_col];
	srand((unsigned)time(NULL));
	for (int i = 0; i < num_row; ++i)
		for (int j = 0; j < num_col; ++j) a[i][j] = rand() % 100;

	int a[max_row][max_col], num_row, num_col;
	printf("num_row = ");
	scanf("%d", &num_row);
	printf("num_col = ");
	scanf("%d", &num_col);
	if (num_row < 1 || num_row > max_row || num_col < 1 || num_col > max_col) {
		printf("Invalid size!\n");
		return;
	}
	// 2D array input
	for (int i = 0; i < num_row; ++i)
		for (int j = 0; j < num_col; ++j) scanf("%d", &a[i][j]);
	// 2D array output
	for (int i = 0; i < num_row; ++i) {
		for (int j = 0; j < num_col; ++j) printf("%d", a[i][j]);
		printf("\n");
	}
	// initialization
	/*
	int bp[10][2] = {{1, 1}, {2, 4}, {3, 9}, {4, 16}, {5, 25}, {6, 36}, {7, 49}, {8, 64}, {9, 81}, {10, 100}};
	int bp[10][2] = {1, 1, 2, 4, 3, 9, 4, 16, 5, 25, 6, 36, 7, 49, 8, 64, 9, 81, 10, 100};
	int bp[][2] = {1, 1, 2, 4, 3, 9, 4, 16, 5, 25, 6, 36, 7, 49, 8, 64, 9, 81, 10, 100};
	*/
}