#include <iostream>
using namespace std;
int () {
    int a;
    cout << "chieu dai hinh chu nhat: ";
    cin >> a;
    int b;
    cout << "chieu rong hinh chu nhat: ";
    cin >> b;
    cout << "chu vi hinh chu nhat la: " << (a + b) * 2 << endl;
    cout << "dien tich hinh chu nhat la: " << a * b << endl;
    cout << "do dai duong cheo hinh chu nhat la: " << sqrt(a * a + b * b) << endl;
    return 0;
}