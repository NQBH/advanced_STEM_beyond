#include <iostream>
using namespace std;

int main() {
    double n;
    cout << "nhap vao canh 1 hinh vuong: ";
    cin >> n;
    if (n <= 0) {
        cout << "loi so" << endl;
        return 0;
    }
    cout << "chu vi hinh vuong: " << n * 4 << endl;
    cout << "dien tich hinh vuong: " << n*n << endl;
}