#include <iostream>
using namespace std;

int main()
{
    bool a,b;   // a: propositson a, b : proposition b
    int x,y,z;
    cout << "Nhap gia tri cua x (so nguyen):" ;
    cin >> x; 
    cout <<"Nhap gia tri cua y (so nguyen):" ;
    cin >> y;
    cout << "Nhap gia tri cua z (so nguyen):" ;
    cin >> z;
    if (x + 1 == 2)
        a = true; 
    else
        a= false;
    if (x + y == z)
        b = true;
    else 
        b = false;
    cout <<"proposition a is " << a << '\n';
    cout <<"proposition b is " << b << '\n';
}