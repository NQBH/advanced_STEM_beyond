#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    int c;
    cout << "Nhap canh a: ";
    cin >> a;
    cout << "Nhap canh b: ";
    cin >> b;
    cout << "Nhap canh c: ";
    cin >> c;
    //Kiểm tra 3 cạnh luôn dương
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1 << endl;
        return 0;
    }
    //Kiem tra hình lập phương
    if (a == b && b == c) {
        cout << "HLP" << endl;
        return 0;
    }
    //Kiểm tra hình hộp chữ nhật
    else {
        cout << "HHCN" << endl;
        float Sxq; //Diện tích xung quanh
        float Stp; //Diện tích toàn phần
        float H; //Đường chéo
        float V; //Thể tích
        //Các công thức
        Sxq = (a + b + a + b) * c;
        Stp = Sxq + 2 * a * b;
        H = sqrt(a * a + b * b + c * c);
        V = a * b * c;
        //In kết quả
        cout << "Diện tích xq của hình hộp chữ nhật là: " << Sxq << endl;
        cout << "Diện tích tp của hình hộp chữ nhật là: " << Stp << endl;
        cout << "Đường chéo của hình hộp chữ nhật là: " << H << endl;
        cout << "Thể tích của hình hộp chữ nhật là: " << V << endl;
    }
    return 0;
}