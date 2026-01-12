#include <cmath> // Thư viện cho hàm sqrt và pow
#include <iostream>
using namespace std;
int main()
{
    // Bài tập 1 Hình vuông
    cout << "Bài tập 1:\n";
    float canh;
    cout << "canh= ";
    cin >> canh;
    float chuvi;
    chuvi = canh * 4;
    cout << "\nChu vi hình vuông bằng " << chuvi << endl;
    float dientich;
    dientich = canh * canh;
    cout << "\nDien tich hình vuông bằng " << dientich << endl;
    // Bài tập 2 Hình chữ nhật
    cout << "Bài tập 2:\n";
    float chieudai;
    cout << "Chiều dài= ";
    cin >> chieudai;
    float chieurong;
    cout << "\nChiều rộng= ";
    cin >> chieurong;
    float chuvichunhat;
    chuvichunhat = ( chieudai + chieurong ) * 2;
    cout << "\nChu vi hình chữ nhật bằng " << chuvichunhat << endl;
    float dientichchunhat;
    dientichchunhat = chieudai * chieurong;
    cout << "\nDiện tích hình chữ nhật bằng " << dientichchunhat << endl;
    float dodaiduongcheochunhat;
    dodaiduongcheochunhat = sqrt(pow(chieudai, 2) + pow(chieurong, 2));
    cout << "\nĐộ dài đường chéo hình chữ nhật bằng " << dodaiduongcheochunhat << endl;
    // Bài tập 3
    cout << "Bài tập 3:\n";
    int a; // Chiều dài
    cout << "Nhập giá trị số nguyên a= ";
    cin >> a;
    int b; // Chiều rộng
    cout << "\nNhập giá trị số nguyên b= ";
    cin >> b;
    int c; // Chiều cao
    cout << "\nNhập giá trị số nguyên c= ";
    cin >> c;
    // Kiểm  tra hình lập phương
    if (a == b && b == c && a > 0) { cout << "HLP"; }
    //Kiểm tra hình hộp chữ nhật
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN" << endl;
        int dientichxungquanh;
        dientichxungquanh = 2 * c * ( a + b );
        cout << "Diện tích xung quanh= " << dientichxungquanh << endl;
        int dientichtoanphan;
        dientichtoanphan = dientichxungquanh + 2 * ( a * b );
        cout << "\nDiện tích toàn phần= " << dientichtoanphan << endl;
        int duongcheo;
        duongcheo = sqrt (a * a + b * b + c * c);
        cout << "\nĐường chéo= " << duongcheo << endl;
        int thetich;
        thetich = a * b * c;
        cout << "\nThể tích= " << thetich << endl;
    }
    // Không phải hình hộp chữ nhật
    else {
        cout << "\n-1";
    }
    return 0;
}