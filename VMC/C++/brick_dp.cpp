#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numRow, numCol;
vector<vector<int>>dp;
int main() {
	
	cin >> numRow >> numCol;

	// dp[i][j] : Cách chọn từ hàng 1 đến hàng i khi chọn viên gạch thứ j

	dp.resize(numRow + 1, vector<int>(numCol + 1, 0));

	for (int i = 1; i <= numCol; i++) {
		dp[1][i] = 1;
	}



	int ways = 0;
	for (int row = 2; row <= numRow; row++) {
		for (int col = 1; col <= numCol; col++) {
			if (row % 2 == 0) {
				if (col == 1) {
					for (int BrickInPreviousRow = 2; BrickInPreviousRow <= numCol; BrickInPreviousRow++)
						dp[row][col] += dp[row - 1][BrickInPreviousRow];
				}
				else {
					for (int BrickInPreviousRow = 1; BrickInPreviousRow <= numCol; BrickInPreviousRow++) {
						if (BrickInPreviousRow == col || BrickInPreviousRow == col - 1) {
							
						}
						else {
							dp[row][col] += dp[row - 1][BrickInPreviousRow];
						}
					}
				}
			}
			else {
				if (col == numCol) {
					for (int BrickInPreviousRow = 1; BrickInPreviousRow < numCol; BrickInPreviousRow++)
						dp[row][col] += dp[row - 1][BrickInPreviousRow];
				}
				else {
					for (int BrickInPreviousRow = 1; BrickInPreviousRow <= numCol; BrickInPreviousRow++) {
						if (BrickInPreviousRow == col || BrickInPreviousRow == col + 1) {

						}
						else {
							dp[row][col] += dp[row - 1][BrickInPreviousRow];
						}
					}
				}
			}
		}
	}

	for (int row = 1; row <= numRow; row++) {
		for (int col = 1; col <= numCol; col++) {
			cout << dp[row][col] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= numCol; i++) {
		ways += dp[numRow][i];
	}
	cout << ways;


}
	