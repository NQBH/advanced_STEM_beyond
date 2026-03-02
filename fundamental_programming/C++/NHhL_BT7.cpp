#include <bits/stdc++.h>
using namespace std;

int main() {
   
    cout << "Tìm max Min của 3 số" << endl;
    double a, b, c;
    cout << "Nhập 3 số thực a, b, c: ";
    cin >> a >> b >> c;

    double max = a; 
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c; 
    }

    double min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }

    cout << "số lớn nhất (Max): " << max << endl;
    cout << "số nhỏ nhất (Min): " << min << endl;

    cout << "------------------------------------" << endl << endl;


    cout << "Tìm Max và Min của N số" << endl;
    int n;
    cout << "Nhập số lượng N (n > 0): ";
    cin >> n;

    if (n <= 0) {
        cout << "error: N phải lớn hơn 0!" << endl;
    } else {
        double val;
        cout << "nhập số thứ 1: ";
        cin >> val;

        double maxN = val;
        double minN = val;

        for (int i = 2; i <= n; i++) {
            cout << "nhập số thứ " << i << ": ";
            cin >> val;

            if (val > maxN) {
                maxN = val;
            }
            
            if (val < minN) {
                minN = val;
            }
        }

        cout << "kết quả " << n << " số vừa nhập: " << endl;
        cout << "   số lớn nhất: " << maxN << endl;
        cout << "   số nhỏ nhất: " << minN << endl;
    }

    return 0;
}