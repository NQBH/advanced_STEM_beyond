#include<iostream>
using namespace std;

int main()
{
    double a, b, c, d;
    cout << "Nhap phan tu cua ma tran 2x2 dạng (a b ; c d): \n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;
    double det = a * d - b * c;
    cout << "ma tran vua nhap: " << endl;
    cout << a << "\t" << b << endl;
    cout << c << "\t" << d << endl;
    cout << "Dinh thuc cua ma tran det(A): " << det << endl;
    return 0;
}