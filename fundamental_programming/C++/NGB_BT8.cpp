#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double so;
    int so_ko = 0;
    int so_am = 0;
    int so_duong = 0;
    //Nhập số lượng phần tử
    cout << "Nhập n: ";
    cin >> n;
    //Nhập từng số và đếm
    for (int i = 1; i <= n; i++) {
        cout << "Nhập số thứ " << i << ": ";
        cin >> so;

        if (so == 0) {
            so_ko = so_ko + 1;
        } else if (so < 0) {
            so_am = so_am + 1;
        } else {
            so_duong = so_duong + 1;
        }
    }
    cout << "Kết quả: " << endl;
    cout << "So so 0: " << so_ko << endl;
    cout << "So so am: " << so_am << endl;
    cout << "So so duong: " << so_duong << endl;

    return 0;
}