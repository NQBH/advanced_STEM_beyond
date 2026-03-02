#include <iostream>
using namespace std;
int main() {

    int x;
    int max = x, min = x;
    cout << "Nhap so thu 1: " ;
    cin >> x;
    for (int i = 1; i < 3; i++) {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> x;
        if (x > max)
            max = x;
        if (x < min)
            min = x;
    }
    cout << "So lon nhat la: " << max << endl;
    cout << "So nho nhat la: " << min << endl;
    return 0;
}
