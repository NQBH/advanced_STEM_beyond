#include <iostream>
using namespace std;

int main() {
    double n;
    cout << "nhap vao canh 1 hinh vuong: ";
    cin >> n;
    while (n <= 0) {
        cout << "loi so, vui long nhap lai " << endl;
        cin >> n;
    }
    cout << "chu vi hinh vuong: " << n * 4 << endl;
    cout << "dien tich hinh vuong: " << n * n << endl;
}