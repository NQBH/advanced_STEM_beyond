#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, count;
bool isInCol[13], isInDiag1[26], isInDiag2[26]; // mảng đánh dấu cột, đường chéo phụ & đường chéo chính
vector<int> curr_queen_set_x, curr_queen_set_y; // 2 tập chỉ hàng & cột: tập X có thể bỏ qua do n quân Hậu được sinh lần lượt theo từng hàng

void print_queen_set() { // in kết quả dạng (x, y)
	for (int i = 0; i < n; ++i) {
		cout << "(" << curr_queen_set_x[i] << ", " << curr_queen_set_y[i] << ")";
		if (i < n - 1) cout << ", ";
	}
	cout << '\n';
}

void gen_queen_set(int curr_row) { // backtracking
	for (int curr_col = 1; curr_col <= n; ++curr_col) {
		// xác định đường chéo phụ & chính hiện tại
		int curr_diag1 = curr_row + curr_col, curr_diag2 = curr_row - curr_col + 13; // +13 để tránh chỉ số âm

		// kiểm tra xem tọa mới có thỏa không
		if (isInCol[curr_col] == true) continue;
		if (isInDiag1[curr_diag1] == true) continue;
		if (isInDiag2[curr_diag2] == true) continue;

		// thêm vào tập hợp hiện tại nếu thỏa mãn
		curr_queen_set_x.push_back(curr_row);
		curr_queen_set_y.push_back(curr_col);
		isInCol[curr_col] = true;
		isInDiag1[curr_diag1] = true;
		isInDiag2[curr_diag2] = true;

		// gọi đệ quy thêm quân tiếp theo hoặc in kết quả
		if (curr_queen_set_x.size() == n) {
			++count;
			print_queen_set();
		}
		else gen_queen_set(curr_row + 1);

		// xóa quân vừa thêm vào khỏi tập hợp
		curr_queen_set_x.pop_back();
		curr_queen_set_y.pop_back();
		isInCol[curr_col] = false;
		isInDiag1[curr_diag1] = false;
		isInDiag2[curr_diag2] = false;
	}
}

int main() {
	count = 0;
	cin >> n;
	memset(isInCol, 0, sizeof(isInCol));
	memset(isInDiag1, 0, sizeof(isInDiag1));
	memset(isInDiag2, 0, sizeof(isInDiag2));
	gen_queen_set(1);
	cout << count;
}