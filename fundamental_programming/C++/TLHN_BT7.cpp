// Đề: dùng if-else, tìm số max và min trong 3 số thực cho trước (+1)
// Không dùng (min(a, b, c)) => 0 điểm, Không dùng (max(a, b, c)) => 0 điểm
// (mở rộng code sách "Nhập môn lập trình" trang 92)
// n được nhập vào
// Tìm số lớn nhât & nhỏ nhất trong n số thực được nhập vào


#include <iostream>
#include <cmath>
using namespace std;

int main () {

    double a;
    double b;
    double c;
    double vMax;
    double vMin;

    cout << "Nhap so a: " << endl;
    cin >> a;

    cout << "Nhap so b: " << endl;
    cin >> b;

    cout << "Nhap so c: " << endl;
    cin >> c;

    vMax = a;
    vMin = a;

    if (b > vMax) vMax = b;
    if (c > vMax) vMax = c;

    if (b < vMin) vMin = b;
    if (c < vMin) vMin = c;


    cout << "Max cua 3 so thuc = " << vMax << endl;
    cout << "Min cua 3 so thuc = " << vMin << endl;



    int n;
    double soX;
    double maxSoN, minSoN;

    cout << "Nhap n (bao nhieu so n ban muon nhap): " << endl;
    cin >> n;

    cout << "Nhap so thuc thu nhat: " << endl;
    cin >> soX;
    maxSoN = soX;
    minSoN = soX;


    for (int i = 2; i <= n; i++) {
        cout << "Nhap so thu" << i << ": " << endl;
        cin >> soX;

        if (soX > maxSoN) maxSoN = soX;
        if (soX < minSoN) minSoN = soX;

    }

    cout << "So lon nhat trong n so la: " << maxSoN << endl;
    cout << "So nho nhat trong n so la: " << minSoN << endl;

    return 0;

}