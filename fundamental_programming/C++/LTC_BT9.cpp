#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu n: ";
    cin >> n;
    int x;
    int demChan = 0, demLe = 0;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> x;
        if (x % 2 == 0)
            demChan++;
        else
            demLe++;
    }
    cout << "So luong so chan: " << demChan << endl;
    cout << "So luong so le: " << demLe << endl;

    return 0;
}
