#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<char>>& toa, vector<vector<bool>>& visited, int n, int m) {
    visited[x][y] = true;  // Đánh dấu ô (x, y) đã được thăm

    // 4 hướng di chuyển: lên, xuống, trái, phải
    int dx[] = {-1, 1, 0, 0}; // dịch hàng
    int dy[] = {0, 0, -1, 1}; // dịch cột

    for (int k = 0; k < 4; k++) { // Duyệt 4 hướng
        int nx = x + dx[k]; // Hàng mới sau khi di chuyển
        int ny = y + dy[k]; // Cột mới sau khi di chuyển

        // Kiểm tra điều kiện: 
        // 1. nx, ny vẫn nằm trong ma trận
        // 2. toa[nx][ny] là sàn ('.')
        // 3. Chưa được thăm
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && toa[nx][ny] == '.' && !visited[nx][ny]) {
            dfs(nx, ny, toa, visited, n, m); // Gọi đệ quy cho ô tiếp theo
        }
    }
}

int main(){
    int n, m; cin>>n>>m; 
    vector<vector<char>> toa(n, vector<char>(m)); 

    // Input 
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>toa[i][j]; 
        }
    }
    // cout<<endl;

    // // Output 
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         cout<<toa[i][j]; 
    //     }
    //     cout<<endl;
    // } 

    // Đếm số phòng (rooms)
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (toa[i][j] == '.' && !visited[i][j]) {
                count++; // Gặp 1 phòng mới
                dfs(i, j, toa, visited, n, m); // Đánh dấu tất cả các ô cùng phòng này
            }
        }
    }
    cout << count << endl;

    return 0;
}