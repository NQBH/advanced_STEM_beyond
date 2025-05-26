#include <iostream>
#include <vector>
#include <string>
#include <queue> // Cần cho BFS

using namespace std;

class Solution {
private:
    int n; 
    int m; 
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
            int curr_r = curr.first;
            int curr_c = curr.second;

            // Duyệt qua 4 hướng lân cận
            for (int i = 0; i < 4; ++i) {
                int next_r = curr_r + dr[i];
                int next_c = curr_c + dc[i];

                // Kiểm tra xem ô lân cận có hợp lệ không (trong giới hạn, là sàn, và chưa thăm)
                if (next_r >= 0 && next_r < n &&
                    next_c >= 0 && next_c < m &&
                    grid[next_r][next_c] == '.' &&
                    !visited[next_r][next_c]) {
                    
                    visited[next_r][next_c] = true; // Đánh dấu là đã thăm
                    q.push({next_r, next_c});      // Thêm vào hàng đợi để khám phá tiếp
                }
            }
        }
    }

public:
    Solution(int n_val, int m_val, const vector<string>& map_data)
        : n(n_val), m(m_val), grid(map_data) {
        // Khởi tạo mảng visited với kích thước n x m và tất cả các giá trị là false
        visited.resize(n, vector<bool>(m, false));
    }

    int countRooms() {
        int room_count = 0; // Biến đếm số phòng

        // Duyệt qua tất cả các ô trên bản đồ
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                // Nếu tìm thấy một ô sàn chưa được thăm, đó là một phòng mới
                if (grid[r][c] == '.' && !visited[r][c]) {
                    room_count++; // Tăng số phòng
                    explore_room(r, c); // Bắt đầu khám phá tất cả các ô trong phòng này
                }
            }
        }
        return room_count; // Trả về tổng số phòng
    }

};

// Hàm main để chạy chương trình
int main() {
    int input_n, input_m;
    cin >> input_n >> input_m; // Đọc chiều cao và chiều rộng

    vector<string> input_grid(input_n);
    for (int i = 0; i < input_n; ++i) {
        cin >> input_grid[i]; // Đọc từng dòng của bản đồ
    }

    // Tạo một đối tượng Solution với dữ liệu đã đọc
    Solution solver(input_n, input_m, input_grid);

    // Gọi hàm countRooms để lấy kết quả và in ra
    cout << solver.countRooms() << endl;

    return 0;
}