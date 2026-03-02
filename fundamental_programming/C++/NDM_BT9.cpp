#include <iostream>
using namespace std;

int main() {
    int n;
    int demchan = 0, demle = 0;
    int val;

    cout << "Nhap n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> val;
        if (val > 0) {
            if (val % 2 == 0) {
                demchan++;
            } else {
                demle++;
            }
        }
    }
    cout << "So luong so chan: " << demchan << endl;
    cout << "So luong so le: " << demle << endl;
    return 0;
}