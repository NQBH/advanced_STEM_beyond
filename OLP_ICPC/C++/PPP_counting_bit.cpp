#include <iostream>
#include <map>
using namespace std;
using ull = unsigned long long;

ull x;
map<ull, ull> dp;   // Lưu kết quả đã tính

ull f(ull a)    // Tính tổng số bit 1 trong tất cả các số từ 1 đến a
{
    if (a == 0) // Không có bit 1
        return 0;
    if (dp[a])
        return dp[a];
    if (a & 1)  // a là số lẻ
        return dp[a] = 2 * f(a / 2) + (a / 2) + 1;
    else        // a là số chẵn
        return dp[a] = f(a / 2) + f(a / 2 - 1) + (a / 2);
}

int main()
{
    ios_base::sync_with_stdio(false);  // Tắt đồng bộ để tăng tốc nhập xuất
    cin.tie(nullptr);                  // Giúp cin/cout nhanh hơn

    cin >> x;   // Nhập số x
    cout << f(x) << endl;   // Xuất kết quả số bit 1

    return 0;
}