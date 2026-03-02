#include <iostream>
using namespace std;

int main() {
    int n;
    float so;
    int demDuong = 0, demAm = 0, demZero = 0;

  
    cout << "Bạn muốn nhập bao nhiêu số (n): ";
    cin >> n;

    //  n thuộc N* (n > 0)
    if (n <= 0) {
        cout << "Vui lòng nhập n là số nguyên dương!" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> so;

        if (so > 0) {
            demDuong++;
        } else if (so < 0) {
            demAm++;
        } else {
            demZero++;
        }
    }

    cout << "\n Kết quả thống kê" << endl;
    cout << "Số lượng số dương: " << demDuong << endl;
    cout << "Số lượng số âm: " << demAm << endl;
    cout << "Số lượng số 0: " << demZero << endl;

    return 0;
}