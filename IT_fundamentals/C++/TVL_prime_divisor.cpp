#include <iostream>
using namespace std;

int countPrimeDivisors(int n) {
    int count = 0;
    // Kiểm tra ước nguyên tố 2
    if (n % 2 == 0) {
        count++;
        while (n % 2 == 0)
            n /= 2;
    }
    // Kiểm tra các ước nguyên tố lẻ từ 3 trở lên
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            count++;
            while (n % i == 0)
                n /= i;
        }
    }
    // Nếu còn lại 1 số nguyên tố > sqrt(n)
    if (n > 1) count++;
    return count;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "So uoc nguyen to khac nhau: " << countPrimeDivisors(n) << endl;
    return 0;
}