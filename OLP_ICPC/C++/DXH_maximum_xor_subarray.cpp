#include <iostream>
#include <vector>
using namespace std;
// Sử dụng O(n^2) để tìm max XOR
int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    // Nhập mảng đầu vào
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Tạo mảng prefix XOR: prefix[i] = a[0] ^ a[1] ^ ... ^ a[i-1]
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] ^ a[i];

    // Duyệt tất cả các subarray: [i, j)
    int maxXOR = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int subXOR = prefix[j] ^ prefix[i];
            maxXOR = max(maxXOR, subXOR);
        }
    }

    cout << maxXOR << '\n';
    return 0;
}