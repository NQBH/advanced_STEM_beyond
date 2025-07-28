#include <iostream>
using namespace std;

// Đệ quy tính số phân hoạch tự liên hợp
int countSelfConjugate(int n, int k, int max_val) {
    if (n == 0 && k == 0)
        return 1;
    if (n < 0 || k <= 0 || max_val <= 0)
        return 0;

    int total = 0;
    for (int i = min(n, max_val); i >= 1; i -= 2) { 
        total += countSelfConjugate(n - i, k - 1, i);
    }
    return total;
}

int main() {
    int n;
    int k;
    cout << "Nhập n: ";
    cin >> n;
    cout << "Nhập k: ";
    cin >> k;
    cout << "Số phân hoạch tự liên hợp của " << n << " với " << k << " phần là: ";
    cout << countSelfConjugate(n, k, n) << endl;
    return 0;
}