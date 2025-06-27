#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n, k; cin >> n >> k;

    vector<string> luoi(n); // vector lưu trữ lưới 
    for (ll i = 0; i < n; ++i) cin >> luoi[i];

    // Đếm số hình vuông cho từng chữ cái A-Z
    vector<ll> result(26, 0);

    // Kích thước lớn nhất của hình vuông kết thúc ở (i, j)
    vector<vector<ll>> dp(n, vector<ll>(n, 1));

    // Tính số lượng hình vuông con có các ô giống nhau
    for (ll i = 0; i < n; ++i) {  // Duyệt từng hàng của lưới grid
        for (ll j = 0; j < n; ++j) {  // Duyệt từng cột trong hàng i.
            if (i > 0 && j > 0 &&
                luoi[i][j] == luoi[i - 1][j] &&     // Chỉ xét những ô không nằm ở biên
                luoi[i][j] == luoi[i][j - 1] &&     // Lý do: Vì các ô ở hàng đầu và cột đầu không có đủ 3 ô bên trái, 
                luoi[i][j] == luoi[i - 1][j - 1])   // trên và chéo trái trên để so sánh.
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            // Với mỗi ô (i,j), ta cộng dp[i][j] vào tổng số hình vuông của chữ cái đó.
            result[luoi[i][j] - 'A'] += dp[i][j];
        }
    }

    for (int i = 0; i < k; ++i) cout << result[i] << '\n';
    return 0;
}