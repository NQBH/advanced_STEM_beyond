#include <iostream>
#include <cmath>
using namespace std;
int main() {
//Tìm số lớn nhất nhỏ nhất trong 3 số thực cho trước
    double a, b, c;
    cout << "Nhập a: ";
    cin >> a;
    cout << "Nhập b: ";
    cin >> b;
    cout << "Nhập c: ";
    cin >> c;
    double max, min;
    //Tìm max
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }
    //Tìm min
    if (a <= b && a <= c) {
        min = a;
    } else if (b <= a && b <= c) {
        min = b;
    } else {
        min = c;
    }
    cout << "Max là: " << max << endl;
    cout << "Min là: " << min << endl;
//Tìm số lơn nhất, nhỏ nhất trong n số thực được nhập vào
    double n;
    cout << "Nhập n số thực: ";
    cin >> n;
    double lon, nho;
    if (n <= 0) {
        cout << "Số lượng phải lớn hơn 0" << endl;
        return 1;
    }
    for (int i = 1; i <= n; ++i) {
        double x;
        cout << "Nhập số thứ " << i << ": ";
        cin >> x;
        if (i == 1) {
            lon = x;
            nho = x;
        } else {
            if (x > lon) {
                lon = x;
            }
            if (x < nho) {
                nho = x;
            }
        }
    }
    cout << "Số lớn nhất là: " << lon << endl;
    cout << "Số bé nhất là: " << nho << endl;
    return 0;
}
