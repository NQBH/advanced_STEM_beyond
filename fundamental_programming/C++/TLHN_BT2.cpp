

// BT2: (+1) Viết chương trình C++ nhập vào
// chiều dài & chiều rộng của hình chữ nhật, tính chu vi,
// diện tích, độ dài đường chéo hình chữ nhật đó
// (biết hàm lấy căn bậc 2 của C++ là sqrt).




#include <iostream>
#include <cmath>
using namespace std;

float chieuDai, chieuRong;

int main () {
    cout << "Nhap chieu dai cua hinh chu nhat: " << endl;
    cin >> chieuDai;

    cout << "Nhap chieu rong cua hinh chu nhat: " << endl;
    cin >> chieuRong;

    float chuVi = 2 * (chieuDai + chieuRong);
    float dienTich = chieuDai * chieuRong;
    float duongCheoHinhChuNhat = sqrt(chieuDai * chieuDai + chieuRong * chieuRong);


    cout << "Chu vi hinh chu nhat la: " << chuVi << endl;
    cout << "Dien tich hinh chu nhat la: " << dienTich << endl;
    cout << "Do dai duong cheo hinh chu nhat la: " << duongCheoHinhChuNhat << endl;
    return 0;

}
