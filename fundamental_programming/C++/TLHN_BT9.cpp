#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong so nguyen n: ";
    cin >> n;

    int x;
    
    int demSoChan = 0; // a
    int demSoLe = 0; // b

    for (int i =1; i <= n; i++) {

        cout << "Nhap so thu x " << i << "= ";
        cin >> x;

        if (x % 2 == 0)
            demSoChan++; // a++
        else
            demSoLe++; // b++
    }

    cout << "So luong so chan: " << demSoChan << endl;
    cout << "So luong so le: " << demSoLe << endl;
    return 0;
}