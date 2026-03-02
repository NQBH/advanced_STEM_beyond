#include <iostream>
#include <iomanip>

using namespace std;
void timMaxMin(int n) {
    if (n <= 0) {
        cout << "So luong phan tu khong hop le!\n";
        return;
    }

    double so;
    double max, min;

    cout << "Nhap so thu 1: ";
    cin >> so;
    max = so;
    min = so;

    for (int i = 2; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> so;
        if (so > max) {
            max = so;
        }
        if (so < min) {
            min = so;
        }
    }

    cout << "\n===== KET QUA =====\n";
    cout << fixed << setprecision(2);
    cout << "So lon nhat (Max): " << max << endl;
    cout << "So nho nhat (Min): " << min << endl;
    cout << "Chenh lech (Max - Min): " << (max - min) << endl;
}

int main() {
    int n;
    do {
        cout << "===== TIM MAX VA MIN TRONG N SO THUC =====\n";
        cout << "Nhap so luong phan tu n (n > 0): ";
        cin >> n;
        if (n <= 0) {
            cout << "Vui long nhap n > 0!\n\n";
        }
    } while (n <= 0);

    cout << "\nNhap " << n << " so thuc:\n";

    timMaxMin(n);
    return 0;
}