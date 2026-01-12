#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    cout << "nhap chieu dai hinh chu nhat ";
    cin >> a;
    int b;
    cout << "nhap chieu rong hinh chu nhat ";
    cin >> b;

    cout << "chu vi hinh chu nhat " << (a + b) * 2 << endl;
    cout << "dien tich hinh vuong " << a*b << endl;
    cout << "duong cheo hinh chu nhat " << sqrt(a * a + b * b) << endl;
}