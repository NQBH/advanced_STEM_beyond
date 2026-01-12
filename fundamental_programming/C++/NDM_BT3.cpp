#include <cmath>
#include <iostream>
using namespace std;

int main() {

    // kiem tra HLP hay HHCP
    float a, b, c;
    cout << "Nhap a:";
    cin >> a;
    cout << "Nhap b:";
    cin >> b;
    cout << "Nhap c:";
    cin >> c;

    if (a == b && b == c && a > 0) { // xac dinh hinh HLP
        cout << "HLP";
        return 0;
    }
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN"; // Khong phai HLP => HHCN

        float Sxq = (a + b) * 2 * c;
        float Stp = Sxq + (a * b) * 2;
        float V = a * b * c;
        float duongcheohhcn = sqrt(a * a + b * b + c * c);

        cout << "Dien tich xung quanh hinh hop chu nhat:" << Sxq << '\n';
        cout << "Dien tich toan phan hinh hop chu nhat:" << Stp << '\n';
        cout << "The tich hinh hop chu nhat:" << V << '\n';
        cout << "Duong cheo hinh hop chu nhat:" << duongcheohhcn << '\n';
    }
    else { // khong phai hinh hop chu nhat
        cout << -1;
    }

    return 0;
}