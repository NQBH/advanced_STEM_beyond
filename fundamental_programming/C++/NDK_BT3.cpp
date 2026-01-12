#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {
    int a, b, c;
    cout << "Nhap 3 canh a,b,c:";
    cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
    }
    else {
        if (a == b && b == c) {
            cout << "HLP" << endl;
        } else {
            cout << "HHCN" << endl;
        }

        float dientichxungquanh = 2 * (a + b) * c;
        float dientichtoanphan = 2 * (a * b + b * c + c * a);
        float duongcheo = sqrt((float) a * a + b * b + c * c);
        float thetich = (float) a * b * c;

        cout << "Dien tich xung quanh la:" << dientichxungquanh << endl;
        cout << "Dien tich toan phan la:" << dientichtoanphan << endl;
        cout << "Duong cheo la:" << duongcheo << endl;
        cout << "The tich la:" << thetich << endl;
    }
    return 0;
}
