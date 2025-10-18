#include<iostream>
using namespace std;
int main() {
    int a, b, c, d;
    cout << "Nhap 4 so nguyen a,b,c,d:";
    cin >> a >> b >> c >> d;
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
        cout << "Nhap lai khong duoc so nho hon hoac bang 0!!!!!!!!!!!!";
        return 1;
    }
    cout << "a x d = " << a * d << endl;
    cout << "b x c = " << b * c << endl;
    cout << "dinh thuc cuar ma tran 2x2 la: " << a*d - b*c;
    return 0;
}