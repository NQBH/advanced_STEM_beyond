#include <bits/stdc++.h>
using namespace std;

int main() {
    float cd, cr;
    cout << "chiều dài của hình chữ nhật : " ; cin >> cd;
    cout << "chiều rộng của hình chữ nhật : "; cin >> cr;
    if (cd <= 0 || cr <= 0)
    {
        cout << " Nhập sai giá trị, cạnh phải lớn hơn 0 ";
        return 0;
    }
    float C, S, dck;
    C = (cd + cr) * 2;
    S = cd * cr;
    dck = sqrt(pow(cd, 2) + pow(cr, 2));
    cout << "Chu vi của hình chữ nhật : " << C << '\n';
    cout << "Diện tích của hình chữ nhật : " << S << '\n';
    cout << "Độ dài cạnh chéo của hình chữ nhật : " << dck << "\n";

}