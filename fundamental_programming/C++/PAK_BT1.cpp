#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float chv; cout << "Nhap do dai canh cua hinh vuong : " ;
    cin >> chv;
    if (chv <= 0)
    {
        cout << " Nhập sai giá trị, cạnh phải lớn hơn 0 ";
        return 0;
    }
    double C, S;
    C = 4 * chv;
    S = pow(chv, 2);
    cout << "Chu vi cua hinh vuong canh r = " << chv << " bang " << C << '\n';
    cout << "Dien tich cua hinh vuong canh r = " << chv << " bang " << S << '\n';
}