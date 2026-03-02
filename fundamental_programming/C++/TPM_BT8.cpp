#include <iostream>
using namespace std;

int main() {
    int n, sduong, sam, s0;
    cout << "n: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s0 = 0;
    sduong = 0;
    sam = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            s0++;
        } else if (a[i] > 0) {
            sduong++;
        } else sam++;
    }
    cout << "Số số 0: " << s0 << '\n';
    cout << "Số số âm: " << sam << '\n';
    cout << "Số số dương: " << sduong << '\n';
    return 0;
}
