#include <iostream>
using namespace std;

int main() {
    double a, b, c, d;
    cout << "Nhập các phần tử ma trận 2x2 (a b c d): ";
    cin >> a >> b >> c >> d;

    double det = a * d - b * c;

    cout << "Định thức của ma trận là: " << det << endl;
    return 0;
}