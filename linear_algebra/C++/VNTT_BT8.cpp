
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhập n (nguyên dương): ";
    if (!(cin >> n) || n <= 0) {
        cout << "n phải là số nguyên dương.\n";
        return 0;
    }

    cout << "Ma trận 0 (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << 0;
            if (j < n - 1) cout << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
\
    cout << "Ma trận đơn vị (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (i == j ? 1 : 0);
            if (j < n - 1) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
