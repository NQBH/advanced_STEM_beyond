#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    cout << "nhap n: ";
    cin >> n;

    if (pow(2, n) >= 100)
        cout << "dung " << endl;
    else cout << "sai" << endl;
    return 0;
}