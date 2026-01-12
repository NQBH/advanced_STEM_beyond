#include <iostream>
using namespace std;

int main() {
    float a; // dung float cho nhe
    cout << "Nhap canh hinh vuong: ";
    cin >> a;

    float chuvi, dientich;
    chuvi = a * 4;
    dientich = a * a;

    cout << "Ket qua chu vi la: " << chuvi << endl;
    cout << "Ket qua dien tich la: " << dientich;

    return 0;
}
