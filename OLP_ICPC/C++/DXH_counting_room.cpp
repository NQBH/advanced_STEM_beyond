#include <iostream>
#include <vector>
#include <string>
#include <queue> // cần cho BFS
using namespace std;

class Solution {
private:
    int n, m;
    vector<string> grid;
    vector<vector<bool>> visited;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void explore_room(int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int curr_r = curr.first, curr_c = curr.second;
            // duyệt qua 4 hướng lân cận
            for (int i = 0; i < 4; ++i) {
                int next_r = curr_r + dr[i];
                int next_c = curr_c + dc[i];
                // kiểm tra xem ô lân cận có hợp lệ không (trong giới hạn, là sàn, & chưa thăm)
                if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m &&
                        grid[next_r][next_c] == '.' && !visited[next_r][next_c]) {
                    visited[next_r][next_c] = true; // đánh dấu là đã thăm
                    q.push({next_r, next_c});       // thêm vào hàng đợi để khám phá tiếp
                }
            }
        }
    }

public:
    Solution(int n_val, int m_val, const vector<string>& map_data)
        : n(n_val), m(m_val), grid(map_data) {
        // khởi tạo mảng visited với kích thước n x m & tất cả các giá trị là false
        visited.resize(n, vector<bool>(m, false));
    }

    int countRooms() {
        int room_count = 0; // biến đếm số phòng
        // duyệt qua tất cả các ô trên bản đồ
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                // nếu tìm thấy 1 ô sàn chưa được thăm, đó là 1 phòng mới
                if (grid[r][c] == '.' && !visited[r][c]) {
                    ++room_count; // tăng số phòng
                    explore_room(r, c); // bắt đầu khám phá tất cả các ô trong phòng này
                }
            }
        }
        return room_count; // trả về tổng số phòng
    }
};

// hàm main để chạy chương trình
int main() {
    int input_n, input_m;
    cin >> input_n >> input_m; // đọc chiều cao & chiều rộng
    vector<string> input_grid(input_n);
    for (int i = 0; i < input_n; ++i) cin >> input_grid[i]; // đọc từng dòng của bản đồ    
    Solution solver(input_n, input_m, input_grid); // tạo 1 đối tượng Solution với dữ liệu đã đọc
    cout << solver.countRooms(); // gọi hàm countRooms để lấy kết quả & in ra
}