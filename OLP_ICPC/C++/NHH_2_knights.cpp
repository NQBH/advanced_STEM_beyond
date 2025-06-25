#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

int main() {
    ll n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        ll s = i * i; // number of squares in i x i chessboard
        // Cách chọn 2 vị trí bất kỳ cho 2 quân Mã - Tổ hợp
        ll total = (s * (s - 1)) / 2; // phải ép kiểu vì mặc định là (int) 2, không ll (2)
        // Cách chọn 2 vị trí 2 quân Mã có thể tấn công nhau
        ll attack = 4LL * (i - 1) * (i - 2); // = number of 2x3 or 3x2 rectangles in ixi chessboard
        // Cách chọn 2 vị trí không để 2 quân Mã tấn công nhau
        ll res = total - attack;
        cout << res << "\n";
    }

    return 0;
}