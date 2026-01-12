#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int canh;
    cout << " Nhập cạnh hình vuông: ";
    cin >> canh;

    int ChuVi = canh * 4;
    cout << " Chu vi hình vuông cạnh " << canh << " bằng " << ChuVi << '\n';

    int DienTich = pow(canh, 2);
    cout << " Diện tích hình vuông cạnh " << canh << " bằng " << DienTich << '\n';

    return 0;
}