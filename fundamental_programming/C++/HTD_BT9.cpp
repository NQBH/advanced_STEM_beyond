#include <iostream>
using namespace std;

int main() {
    int n;
    // Nhap so luong phan tu
    cout << "Nhap n: ";
    cin >> n;

    int demChan = 0; // Dem so chann
    int demLe = 0;   // Dem so le
    
    // QUAN TRONG: temp phai la int moi chia lay du duoc
    int temp; 

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> temp;

        // Kiem tra chan le bang phep chia lay du (%)
        if (temp % 2 == 0) {
            demChan++; // Chia het cho 2 la so chan
        } else {
            demLe++;   // Khong chia het cho 2 la so le
        }
    }

    cout << "Co " << demChan << " so chan." << endl;
    cout << "Co " << demLe << " so le." << endl;

    return 0;
}