#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    int so;
    int so_chan = 0;
    int so_le = 0;
    cout << "Nhập n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhập số thứ " << i << ": ";
        cin >> so;
        if (so % 2 == 0) {
            so_chan = so_chan + 1;
        } else {
            so_le = so_le + 1;
        }
    }
    cout << "Kết quả: " << endl;
    cout << "So so chan: " << so_chan << endl;
    cout << "So so le: " << so_le << endl;

    return 0;
}