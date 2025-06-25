#include <iostream>
#include <cmath>
using namespace std;
using ul = unsigned long;

ul n; // Số ô bàn cờ

ul find_ways(ul k) {
    // Số cách tối đa đặt 2 quân mã lên bàn cờ
    ul knights_placements = (pow(k, 2) * (pow(k, 2) - 1)) / 2;

    // Trường hợp 2 quân mã tấn công nhau trên bàn cờ
    ul knights_attacks = 4 * (k - 1) * (k - 2);

    return knights_placements - knights_attacks; // Trả về số cách xếp 2 quân mã cuối cùng
}

int main() {
    cin >> n;
    for (ul i = 1; i <= n; ++i)
        cout << find_ways(i) << " ";
    return 0;
}