#include <iostream>
using namespace std;

int main() {
    int n;
    int dem_chan = 0;
    int dem_le = 0;
    int so_nguyen;
    cout << "nhap so luong phan tu n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "nhap so thuc " << i << ": ";
        cin >> so_nguyen;
        if (so_nguyen % 2 == 0) {
            dem_chan++;
        } else {
            dem_le++;
        }
    }
    cout << "\n ket qua la:"<< endl;
    cout << "so luong so chan la: " << dem_chan << endl;
    cout << "so luong so le la: " << dem_le << endl;

    return 0;
}