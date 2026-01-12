#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a = 7; 
    float b = 3; 
    float c = 4;

    // Nhập dữ liệu ban đầu
    cout << "Nhap canh a: ";
    cin >> a;
    cout << "Nhap canh b: ";
    cin >> b;
    cout << "Nhap canh c: ";
    cin >> c;

    //  Kiểm tra 3 cạnh phải dương .
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1 << endl;
        return 0;
    }

    //  Kiểm tra Hình Lập Phương
    if (a == b && b == c) {
        cout << "HLP" << endl;
    } 
    
    else {
        cout << "HHCN" << endl;

        
        float dientichxungquanh, dientichtoanphan, thetich;
        float chuvi, dientichday;
        float duongcheo; 

        
        chuvi = (a + b) * 2;
        dientichday = a * b;
        dientichxungquanh = chuvi * c;
        dientichtoanphan = dientichxungquanh + 2 * dientichday;
        thetich = a * b * c;
        duongcheo = sqrt(a * a + b * b + c * c); 
        cout << "Dien tich xung quanh hinh hop chu nhat: " << dientichxungquanh << endl;
        cout << "Dien tich toan phan hinh hop chu nhat: " << dientichtoanphan << endl;
        cout << "Duong cheo hinh hop chu nhat: " << duongcheo << endl;
        cout << "The tich hinh hop chu nhat: " << thetich << endl;
        
    }

    return 0;
}