#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float chieuDai, chieuRong;
    
    cout << "Nhap chieu dai: ";
    cin >> chieuDai;
    
    cout << "Nhap chieu rong: ";
    cin >> chieuRong;

    float chuvi = (chieuDai + chieuRong) * 2;
    float dientich = chieuDai * chieuRong;
    float duongCheo = sqrt(chieuDai * chieuDai + chieuRong * chieuRong);

    cout << "Chu vi la: " << chuvi << endl;
    cout << "Dien tich la: " << dientich << endl;
    cout << "Duong cheo la: " << duongCheo << endl;

    return 0;
}