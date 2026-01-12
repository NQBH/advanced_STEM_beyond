#include <iostream>
using namespace std ;
int main ()
{
    int a , b, c ;
    cout << "Nhap ba so nguyen a , b, c: " ;
    cin >> a >> b >> c ;
    if (a > 0 && b > 0 && c > 0 && a == b && b == c && a == c)
    {
        cout << " Hinh lap phuong" << endl ;
    }
    else if (a > 0 && b > 0 && c > 0 ) {
        cout << " Hinh hop chu nhat" << endl ;
        if ( a <= 0 || b <= 0 || c <= 0 )
        {
            cout << "-1" << endl ;
        }
        else
        {
            int S = 2 * (a * b + b * c + c * a) ;
            cout << " Dien tich toan phan hinh hop chu nhat la: " << S << endl ;
            int V = a * b * c ;
            cout << " The tich hinh hop chu nhat la: " << V << endl ;
            int d = sqrt ( a * a + b * b + c * c ) ;
            cout << " Do dai duong cheo hinh hop chu nhat la: " << d << endl ;
            int s1 = 2 * (a * b + b * c + c * a) + 2 * (a * a + b * b + c * c) ;
            cout << " Dien tich toan phan hinh lap phuong la: " << s1 << endl ;
        }
    }
    return 0 ;
}