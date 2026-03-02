#include <iostream>
using namespace std;

int main() {
    int n, x;
    int demChan = 0, demLe = 0;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so nguyen thu " << i << ": ";
        cin >> x;
        if (x % 2 == 0) {
            demChan++;
        } else {
            demLe++;
        }
    }

    cout << "So so chan: " << demChan << endl;
    cout << "So so le: " << demLe << endl;

    return 0;
}
