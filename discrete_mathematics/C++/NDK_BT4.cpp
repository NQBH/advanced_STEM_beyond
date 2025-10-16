#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    cout << "Nhap n: ";
    cin >> n;

    bool p = (pow(2, n) >= 100);

    if (p)
        cout << "Bất đẳng thức 2^n >= 100: Đúng" << endl;
    else
        cout << "Bất đẳng thức 2^n >= 100: Sai" << endl;

    return 0;
}
