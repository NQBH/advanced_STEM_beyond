#include <cmath>
#include <iostream>
using namespace std;

int main() {
    float a; //Chiều dài
    float b; //Chiều rộng
    float C; //Chu vi
    float S; //Dien tích
    float H; //Đường chéo
    cout << "Nhap chieu dai cua hinh chu nhat: ";
    cin >> a;
    cout << "Nhap chieu rong cua hinh chu nhat: ";
    cin >> b;

    C = (a + b) * 2; //Công thức chu vi
    S =  a * b; //Công thức diện tích
    H = sqrt(a * a + b * b); //Công thức đường chéo

    // In kết quả
    cout << "Chu vi hinh chu nhat la: " << C << endl;
    cout << "Dien tich hinh chu nhat la: " << S << endl;
    cout << "Duong cheo hinh chu nhat la: " << H << endl;
    
    return 0;
}