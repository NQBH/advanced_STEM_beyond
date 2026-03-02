#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c;
    cout << "Nhap 3 so thuc a, b, c: ";
    cin >> a >> b >> c;

    // Dung ham fmax va fmin de tim nhanh
    float max_val = fmax(a, fmax(b, c));
    float min_val = fmin(a, fmin(b, c));

    cout << "So lon nhat la: " << max_val << endl;
    cout << "So nho nhat la: " << min_val << endl;

    return 0;
}