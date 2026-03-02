#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double m, M;
    cout << "Nhap m : ";
    cin >> m ;
    cout << " nhap M:";
    cin >> M;
    double S = 0;
    int n = 0;

    // cho  n = 1; điều kiện là  S + n^m vẫn <= M; nếu kết quả lớn hơn M thì phép toán dừng lại, tăng n sau nỗi phép toán
    for (int i = 1; S + pow(i, m) <= M; i++) {
        S += pow(i, m);
        n = i;
    }

    if (n == 0) {
        cout << "Khong co gia tri n nao thoa man." << endl;
    } else {
        cout << "n lon nhat la: " << n << " (Tong S = " << S << ")" << endl;
    }

    return 0;
}