#include <iostream>


using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    int demChan = 0;
    int demLe = 0;
    int so;

    for (int i = 0; i < n; i++) {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> so;

        // Kiem tra chan le
        if (so % 2 == 0) {
            demChan++; // Tang bien dem chan
        } else {
            demLe++;   // Tang bien dem le
        }
    }

    cout << "-------------------------" << endl;
    cout << "So luong so chan: " << demChan << endl;
    cout << "So luong so le: " << demLe << endl;

    return 0;
}