#include <iostream>
#include <vector>
using namespace std;

// Tính C(n, k) = n! / (k!(n-k)!)
unsigned long long C(int n, int k) {
    if (k > n - k) k = n - k;
    unsigned long long res = 1;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// In tam giác Pascal đến dòng thứ n
void printPascal(int n) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << C(i, j) << " ";
        cout << endl;
    }
}

// Khai triển (a + b)^n
void expandAB(int n) {
    cout << "(a + b)^" << n << " = ";
    for (int k = 0; k <= n; ++k) {
        cout << C(n, k) << "*a^" << (n - k) << "*b^" << k;
        if (k < n) cout << " + ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    cout << "\n--- Tam giac Pascal ---\n";
    printPascal(n);

    cout << "\n--- Khai trien (a + b)^n ---\n";
    expandAB(n);

    return 0;
}
