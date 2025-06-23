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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
