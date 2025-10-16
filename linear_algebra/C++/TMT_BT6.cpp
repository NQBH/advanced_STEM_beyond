#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Đọc kích thước ma trận A: m hàng, n cột
    int m, n;
    cin >> m >> n;
    
    // Khai báo ma trận A kích thước m x n (sửa lỗi: dùng n thay vì m)
    vector<vector<int>> A(m, vector<int>(n));
    
    // Đọc các phần tử của A
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    
    // Đọc kích thước vector b: p phần tử
    int p;
    cin >> p;
    
    // Khai báo vector b kích thước p x 1
    vector<int> b(p);
    for (int i = 0; i < p; ++i) {
        cin >> b[i];
    }
    
    // Kiểm tra điều kiện: số hàng của A phải bằng kích thước b
    if (m != p) {
        cout << "Impossible" << endl;
        return 0; 
    }
    
    // Tạo ma trận bổ sung [A|b]: kích thước m x (n+1)
    vector<vector<int>> Ab(m, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            Ab[i][j] = A[i][j];  
        }
        Ab[i][n] = b[i];
    }
    
    // Xuất ma trận [A|b] với định dạng đẹp
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {  
            cout << Ab[i][j];
            if (j < n) cout << " "; 
        }
        cout << endl;
    }
    
    return 0;
}
