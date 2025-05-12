#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double M;
    cout << "Nhap M > 0: ";
    cin >> M;

    if (M <= 0) {
        cout << "M lon hon 0";
        return 1;
    }

    int N = ceil(M * M - 2);
    cout << "Gia tri N nho nhat de sqrt(n + 2) > " << M << " la: " << N << endl;

 return 0;
}