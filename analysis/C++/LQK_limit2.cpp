#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double M;
    cout << "Nhập M > 0: ";
    cin >> M;

    if (M <= 0) {
        cout << "M phai lon hon 0.\n";
        return 1;
    }

    int n = 0;
    while (sqrt(n + 2) <= M) {
        n++;
    }

    cout << "(c) Gia tri nho nhat của n sao cho sqrt(n + 2) > M là: " << n << endl;
    return 0;
}