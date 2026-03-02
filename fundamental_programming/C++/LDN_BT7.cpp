#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cout << "Nhap 3 so thuc a, b, c: ";
    cin >> a >> b >> c;
    double maxVal = a, minVal = a;
    if (b > maxVal) {
        maxVal = b;
    } else {
        if (c > maxVal) {
            maxVal = c;
        }
    }
    if (b < minVal) {
        minVal = b;
    } else {
        if (c < minVal) {
            minVal = c;
        }
    }
    cout << "Max = " << maxVal << ", Min = " << minVal << endl;
}