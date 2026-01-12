#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float Chieudai;
    float Chieurong;
    float P;
    float S;
    float d;
    cout << "Nhap chieu dai:";
    cin >> Chieudai;
    cout << "Nhap chieu rong:";
    cin >> Chieurong;
    P = ( Chieudai + Chieurong ) * 2;
    S = Chieudai * Chieurong;
    d = sqrt( Chieudai * Chieudai + Chieurong * Chieurong);
    cout << "Chu vi hinh chu nhat la:" << P << endl;
    cout << "Dien tich hinh chu nhat la:" << S << endl;
    cout << "Do dai duong cheo hinh chu nhat la:" << d << endl;
    return 1;
}
