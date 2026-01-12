#include <cmath>
#include <iostream>
using namespace std;

int main() {

    double dai;
    double rong;
    cout << " Nhập chiều dài hình chữ nhật: ";
    cin >> dai; 

    cout << " Nhập chiều rộng hình chữ nhật: ";
    cin >> rong;

    double ChuVi = (dai + rong) * 2;
    cout << " Chu vi hình chữ nhật (dài = " << dai << ", rộng = " << rong << ") bằng " << ChuVi << '\n';

    double DienTich = dai * rong;
    cout << " Diện tích hình chữ nhật bằng " << DienTich << '\n';

    double DuongCheo = sqrt(pow(dai, 2) + pow(rong, 2));
    cout << " Độ dài đường chéo hình chữ nhật bằng " << DuongCheo << '\n';
    
    return 0;
}