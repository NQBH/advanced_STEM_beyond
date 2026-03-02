#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    cout << "nhap a:" << a << endl;

    if (a % 2 == 0) {
        cout << "a la so chan" << endl;
    } else {
        cout << "a la so le" << endl;
    }
    return 0;
}
