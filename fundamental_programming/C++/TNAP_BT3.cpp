#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    // kiểm tra hình lập phương
    if ( a ==b && b==c){
        cout << "HLP" << '\n';
    }
    // kiểm tra hình chử nhật
    else {
        cout << "HHCN" << '\n';
        // TÍnh diện tích xung quang hình hộp chủ nhật
        float Sxq = 2 * (a + b) * c;
        // Tính diện tích toàn phần hình hộp chủ nhật
        float Stp = Sxq + 2 * a * b;
        // Tính thể tính thể tích
        float TheTich = a * b * c;
        // Tính đường chéo hình hộp củ nhật
        double DuongCheo = sqrt(a * a + b * b + c * c);
        cout << "Dien tich xung quanh hinh hop chu nhat la " << Sxq << '\n';
        cout << "Dien tich toan phan hinh hop chu nhat la " << Stp << '\n';
        cout << "The tich hinh hop chu nhat la " << TheTich << '\n';
        cout << "Duong cheo hinh hop chu nhat la " << DuongCheo << '\n';
    }
    return 0;
}
